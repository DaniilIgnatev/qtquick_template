
# Copilot Instruction: C++/QML Type Registration for Tests

## Pattern for Scalable C++/QML Bindings

- All C++ types to be used in QML (e.g., ViewModels) must be registered in `src/app/qml_type_registration.cpp` via `qmlRegisterType<YourType>("AppVM", 1, 0, "YourType")`.
- The function `registerQmlTypes()` (declared in `qml_type_registration.hpp`) must be called before any QML engine or view is created.
- This applies to both the main application and all test runners (C++ or QML integration tests).

## For QML/Integration Tests
- In any C++ test harness that creates a QML engine (e.g., QtQuickTest, custom QML test runners), call `registerQmlTypes()` before instantiating the QML engine or loading QML files.
- This ensures all registered C++ types are available in the QML context for tests, just as in the main app.

## Example (C++ Test Main)
```cpp
#include "src/app/qml_type_registration.hpp"
#include <QtQuickTest/quicktest.h>

int main(int argc, char** argv) {
    registerQmlTypes();
    return quick_test_main(argc, argv, "qmltests", /*...*/);
}
```

## Benefits
- Centralizes all QML type registration for maintainability.
- Guarantees consistency between app and test environments.
- Scales easily as new C++ types are added.

---

**Always update `qml_type_registration.cpp` and call `registerQmlTypes()` in all QML test entry points.**
