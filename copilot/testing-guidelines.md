# Testing Guidelines for Qt Quick Applications

## 1. Purpose

This document defines testing principles, strategies, and best practices for Qt Quick applications.
The goal is to ensure **correctness, stability, maintainability, and performance** across QML and C++ layers while keeping tests fast, reliable, and easy to understand.

---

## 2. Testing Scope

The application consists of:

* **QML UI layer**
* **C++ backend (business logic, models, services)**
* **Integration between QML and C++**
* **End-to-end user flows**

Testing must cover all layers with appropriate test types.

---

## 3. Test Pyramid

We follow a test pyramid approach:

1. **Unit Tests (majority)**

   * C++ logic
   * QML JavaScript functions
2. **Integration Tests**

   * QML ↔ C++ bindings
   * Models exposed to QML
3. **UI / System Tests (few, critical paths)**

   * User workflows
   * Visual and interaction behavior

---

## 4. Unit Testing

### 4.1 C++ Unit Tests

**Tools**

* Qt Test (`QtTest`)
* Optional: GoogleTest (if already used in the project)

**Guidelines**

* Test business logic independently of QML
* Avoid GUI dependencies (`QGuiApplication` only if required)
* Prefer pure C++ classes with minimal Qt dependencies
* Mock external services (network, filesystem, hardware)

**Example**

```cpp
class CalculatorTest : public QObject
{
    Q_OBJECT
private slots:
    void add_returnsCorrectSum();
};
```

---

### 4.2 QML Unit Tests

**Tools**

* `QtQuickTest`
* `Custom test executable using `QUICK_TEST_MAIN()`

**What to Test**

* JavaScript helper functions
* Property bindings
* Signal emissions
* State changes
* QML component instantiation and behavior

**Guidelines**

* Avoid full UI trees when possible
* Use lightweight QML components
* Do not rely on timing unless unavoidable
* Always verify component loading status before proceeding
* Use `objectName` property for accessing nested QML elements in tests
* Copy necessary QML files to test build directory using CMake

**Common Pitfalls**

* **Do NOT** try to access nested elements via chained `id` references (e.g., `root.column.myText`)—this only works within the same QML file
* **Always** check component status and log errors for easier debugging
* **Always** copy QML files to test build directory using `configure_file()`

---

## 5. Integration Testing

### 5.1 QML ↔ C++ Integration

**Goals**

* Verify properties, signals, and invokable methods
* Ensure models behave correctly in QML

**Guidelines**

* Test real C++ objects registered to QML
* Avoid mocking QML engine unless required
* Validate error handling and edge cases

**Example Scenarios**

* C++ model updates reflected in QML
* QML actions triggering C++ logic
* Signal propagation correctness

---

## 6. UI and System Testing

### 6.1 UI Tests

**Tools**

* Squish for Qt (recommended)
* Qt Test (limited UI interaction)
* Custom test harness (if needed)

**What to Test**

* Critical user flows
* Non-trivial logic
* Functionality that is prone to changes
* Functionality that previously triggered errors
* Navigation
* Input handling
* Visual state changes

**Guidelines**

* Focus on behavior, not exact visuals
* Avoid pixel-perfect assertions
* Keep tests independent and repeatable
* Minimize use of delays (`wait()`)

---

### 6.2 End-to-End Tests

**Purpose**

* Validate full application behavior
* Ensure components work together correctly

**Guidelines**

* Run only on CI or nightly builds
* Use real application builds
* Cover high-risk and high-value workflows

---

## 7. Test Data and Fixtures

* Use deterministic test data
* Avoid shared mutable state
* Clean up files, settings, and QML engines after tests
* Reset `QSettings` and global singletons between tests

---

## 8. Performance Testing

**Areas to Monitor**

* Application startup time
* QML component creation
* Model updates and bindings
* Animations and transitions

**Guidelines**

* Measure performance regressions in CI
* Avoid heavy bindings inside delegates
* Profile with Qt Creator and `QML Profiler`

---

## 9. Continuous Integration (CI)

**CI Requirements**

* All unit and integration tests must run on CI
* Tests must not depend on local environment
* No interactive input required

**Best Practices**

* Run tests in headless mode when possible
* Fail the build on test failure
* Publish test reports and logs

---

## 10. Naming and Structure

### 10.1 File Structure

```
tests/
 ├─ unit/
 │   ├─ cpp/
 │   └─ qml/
 ├─ integration/
 └─ system/
```

### 10.2 Naming Conventions

* Test files mirror source file names
* Test case names describe behavior
* Use `should_...` or `returns_...` style

---

## 11. Test Quality Guidelines

* Tests must be:

  * Deterministic
  * Readable
  * Independent
* One test = one behavior
* Prefer explicit checks over implicit assumptions
* Avoid testing Qt framework internals

---

## 12. Known Limitations

* UI tests are slower and more fragile
* Timing-based tests may be flaky
* Platform-specific behavior must be isolated
* QML `id` properties are not accessible outside the QML file scope—use `objectName` instead
* Component loading from relative paths requires QML files to be copied to the test build directory

---

## 13. QML Testing Troubleshooting

### Component Loading Failures

**Symptom:** `Component.status === Component.Error` or "module not found"

**Solutions:**
1. Check that QML files are copied to test build directory using `configure_file()`
2. Add error logging: `console.error("Component error:", component.errorString())`
3. Verify file paths are correct relative to test working directory

### Cannot Access Nested Elements

**Symptom:** "Cannot read property of undefined" when accessing child elements

**Solutions:**
1. Add `objectName` property to QML elements that need to be accessed from tests
2. Use recursive search helper function (`findChildByObjectName`)
3. Do NOT try to access via chained `id` references (e.g., `root.child.subchild`)
4. Verify the element exists before accessing its properties

### Test Executable Linking Errors

**Symptom:** "undefined reference to quick_test_main"

**Solutions:**
1. Link against `Qt6::QuickTest` in CMakeLists.txt
2. Include `#include <QtQuickTest/quicktest.h>` in test runner
3. Use `QUICK_TEST_MAIN(moduleName)` macro

---

## 14. When to Add Tests

Add or update tests when:

* Adding new features
* Fixing bugs (regression tests)
* Refactoring logic
* Exposing new C++ APIs to QML

---

## 14. References

* Qt Test Documentation
* Qt Quick Test Documentation
* Squish for Qt
* Qt QML Best Practices

---
## 16. Real-World Example: Testing a QML Component

This section demonstrates a complete example based on actual project experience.

**Component: RootView.qml**
```qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import App.Domain 1.0

Rectangle {
    id: rootView
    color: "white"
    anchors.fill: parent

    JoystickViewModel {
        id: viewModel
    }

    Column {
        id: contentColumn
        anchors.centerIn: parent
        spacing: 16

        Text {
            id: movableLabel
            objectName: "movableLabel"  // Required for test access
            text: viewModel.labelText
            font.pixelSize: 32
            x: viewModel.labelX
            y: viewModel.labelY
        }

        Button {
            objectName: "upButton"
            text: "↑"
            onClicked: viewModel.moveUp()
        }
    }
}
```

**Test: tst_ui.qml**
```qml
import QtQuick 2.15
import QtTest 1.15

TestCase {
    name: "RootViewTest"
    
    // Helper function to recursively find child by objectName
    function findChildByObjectName(item, name) {
        if (!item) return null;
        if (item.objectName === name) return item;
        if (item.children) {
            for (var i = 0; i < item.children.length; ++i) {
                var found = findChildByObjectName(item.children[i], name);
                if (found) return found;
            }
        }
        return null;
    }

    function test_movableLabel() {
        var component = Qt.createComponent("RootView.qml");
        
        // Always log errors for debugging
        if (component.status === Component.Error) {
            console.error("Component error:", component.errorString());
        }
        verify(component.status === Component.Ready, "Component should be ready");
        
        var view = component.createObject(this);
        verify(view !== null, "RootView instance should be created");

        // Find nested element by objectName
        var textItem = findChildByObjectName(view, "movableLabel");
        verify(textItem !== null, "movableLabel should exist");
        compare(textItem.text, "Hello, world!");

        view.destroy();
    }
}
```

**CMakeLists.txt for tests**
```cmake
add_executable(ui_tests test_ui.cpp)
target_link_libraries(ui_tests PRIVATE Qt6::Test Qt6::Quick Qt6::QuickWidgets Qt6::Widgets Qt6::QuickTest uiplugin)

# Copy test QML file to build directory
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/tst_ui.qml 
               ${CMAKE_CURRENT_BINARY_DIR}/tst_ui.qml COPYONLY)

# Copy component QML file needed by test
configure_file(${CMAKE_SOURCE_DIR}/src/ui/RootView.qml 
               ${CMAKE_CURRENT_BINARY_DIR}/RootView.qml COPYONLY)

add_test(NAME ui_tests COMMAND ui_tests)

# Set QML import path for finding modules
set_tests_properties(ui_tests PROPERTIES
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    ENVIRONMENT "QML_IMPORT_PATH=${CMAKE_BINARY_DIR}/src/ui;${CMAKE_BINARY_DIR}/src/ui/tests"
)
```

**Test runner: test_ui.cpp**
```cpp
#include <QtQuickTest/quicktest.h>
QUICK_TEST_MAIN(ui_tests)
```

**Key takeaways from this example:**
1. Always set `objectName` on elements you need to access from tests
2. Use recursive search helpers—never rely on `id` for external access
3. Copy all necessary QML files to the test build directory
4. Log component errors for easier debugging
5. Set `QML_IMPORT_PATH` and `WORKING_DIRECTORY` correctly
6. Link against all required Qt modules including `Qt6::QuickTest`

---