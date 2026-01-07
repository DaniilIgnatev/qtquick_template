
# Copilot Instruction: C++/QML Type Registration for Tests

## Pattern for Scalable C++/QML Bindings

- All C++ types to be used in QML (e.g., ViewModels) must be registered in `src/app/qml_type_registration.cpp` via `qmlRegisterType<YourType>("App.Domain", 1, 0, "YourType")`.
- Include the domain header: `#include "../domain/include/domain.hpp"`
- The function `registerQmlTypes()` (declared in `qml_type_registration.hpp`) must be called before any QML engine or view is created.
- This applies to both the main application and all test runners (C++ or QML integration tests).

## Domain Pattern
- All domain logic classes live in `src/domain/include/domain.hpp` and `src/domain/src/domain.cpp` for simplicity reasons.
- Example: `JoystickViewModel` is defined in domain.hpp and implemented in domain.cpp
- To add new domain classes, simply add them to domain.hpp/cpp and register in qml_type_registration.cpp

## For QML/Integration Tests
- In any C++ test harness that creates a QML engine (e.g., QtQuickTest, custom QML test runners), call `registerQmlTypes()` before instantiating the QML engine or loading QML files.
- This ensures all registered C++ types are available in the QML context for tests, just as in the main app.
- Tests must include qml_type_registration.cpp source and link with domain library

## Example (QML Test Setup with QObject-based Setup class)
```cpp
#include <QtQuickTest/quicktest.h>
#include <QQmlEngine>
#include <QQmlContext>
#include "../../app/qml_type_registration.hpp"

class Setup : public QObject {
    Q_OBJECT
public:
    Setup() {
        registerQmlTypes();
    }
};

QUICK_TEST_MAIN_WITH_SETUP(ui_tests, Setup)
#include "test_ui.moc"
```

## Benefits
- Centralizes all QML type registration for maintainability.
- Guarantees consistency between app and test environments.
- Scales easily as new C++ types are added.
- Single source of truth: domain.hpp/cpp for all domain logic

---

**Always update `qml_type_registration.cpp` and call `registerQmlTypes()` in all QML test entry points.**
