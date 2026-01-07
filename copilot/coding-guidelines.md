# Coding Guidelines – C++ / QtQuick / QML


These guidelines apply to all code generated in this repository.
This is a demo-focused project, not production-grade software.

---

## Project Configuration & Supplementary Files

- Whenever code or project structure changes (e.g., new modules, tests, resources, or dependencies), ensure all relevant configuration and supplementary files are automatically updated. This includes:
	- CMakeLists.txt and related CMake files
	- CI/CD workflows (e.g., GitHub Actions)
	- VSCode configuration (.vscode/)
	- Packaging scripts (e.g., CPackConfig.cmake)
	- Documentation (README, CONTRIBUTING, etc.)
- This ensures the project remains buildable, testable, and usable as a template without manual intervention.

---

## General Principles

- Do not fall into assumptions, clarify the problem first
- Generated code is isolated into separated files and put aside from manually tunable code
- Use CMake best practises to organize the project
- Follow the top-down approach in code design and structure of the project
- Prefer clarity over cleverness
- Optimize for readability and demo value
- Avoid overengineering and unnecessary abstractions
- Follow the commonly accepted idioms in software development
- Verify correctness of the generated code
- Build the project and run tests before commiting the changes
- Follow the best practises in unit-testing
- Mock external dependencies for testing

---

## C++ Guidelines (Qt)

### Language & Style
- Prefer modern C++
- Prefer RAII and smart pointers
- Avoid raw `new` / `delete`
- Avoid macros unless required by Qt

### Qt Usage
- Use Qt types (`QString`, `QVector`, `QObject`) where appropriate
- Prefer signals and slots over callbacks
- Use `QObject` as the base class only when signals, slots, or properties are needed
- Use `Q_PROPERTY` for data exposed to QML

### Class Design
- **For this template**: All domain logic is consolidated in `src/domain/include/domain.hpp` and `src/domain/src/domain.cpp` for simplicity and demo purposes
- **For larger projects**: Consider splitting into one class per file when the codebase grows
- Keep classes small and focused
- Use `explicit` constructors
- Delete copy constructors when ownership is unclear

### Memory & Ownership
- Parent `QObject`s whenever possible
- Prefer Qt parent ownership over manual lifetime management
- Avoid global state

### Naming
- Classes: `PascalCase`
- Methods: `camelCase`
- Member variables: `m_camelCase`
- Signals: `somethingChanged`
- Slots: `onSomethingChanged`

---

## QML Guidelines

### Structure
- One root item per file
- One main visual component per QML file
- Keep files under ~1000 lines

### Properties & State
- Use `property` declarations explicitly
- Prefer bindings over imperative logic
- Avoid deep nesting of states
- Avoid JavaScript-heavy logic in QML

### Testability
- Add `objectName` property to elements that need to be accessed from tests
- Use descriptive `objectName` values (e.g., `objectName: "movableLabel"`)
- Keep QML components simple and testable in isolation
- Avoid complex nested structures when possible

### Layout & UI
- Prefer `Column`, `Row`, `Grid`, and `Layout` types
- Avoid hard-coded sizes unless required for the demo
- Use anchors consistently

### Signals & Handlers
- Use `onSignalName` handlers sparingly
- Avoid complex logic inside signal handlers
- Forward logic to C++ when it becomes non-trivial

---

## QML Module Setup (CMake)

### For Application QML Modules
- Use `qt_add_library()` followed by `qt_add_qml_module()`
- Specify a clear URI (e.g., `URI ui`)
- Set appropriate `VERSION` and `RESOURCE_PREFIX`

**Example:**
```cmake
qt_add_library(ui STATIC)
qt_add_qml_module(ui
    URI ui
    VERSION 1.0
    RESOURCE_PREFIX qml
    QML_FILES
        RootView.qml
)
```

---

## C++ ↔ QML Integration

- Expose data via `Q_PROPERTY`
- Use `NOTIFY` signals for all mutable properties
- Keep business logic in C++
- Keep UI logic in QML
- Avoid accessing QML objects directly from C++

---

## Imports & Modules

- Explicitly list required QML imports
- Avoid unused imports
- Prefer stable Qt modules

Example:
```qml
import QtQuick 2.15
import QtQuick.Controls 2.15
```
