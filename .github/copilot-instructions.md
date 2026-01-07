# Copilot Instructions for AI Agents

Always verify that the instructions below are up to date with the latest project structure and requirements before generating or modifying code.
Always verify that any generated code adheres to the  guidelines, can be compiled and pass tests.
Always allow to send "a" followed by "Enter" to the terminal when it will be reused by tasks.

## Project Overview
- **Purpose:** Rapid prototyping and demo of QtQuick apps with C++17 backend, using AI-assisted workflows. The following instructions guide the AI in generating, testing, and maintaining the project.

- **Architecture:**
  - Modular CMake build (see `CMakeLists.txt` at root and in `src/`)
  - UI: QML (MVVM pattern) in `src/ui/`
  - Business logic: C++ in `src/domain/`
  - App entry: `src/app/`

## Key Workflows
- **Build:**
  - `cmake -S . -B build`
  - `cmake --build build`
- **Run:**
  - macOS: `./build/src/app/app.app/Contents/MacOS/app`
- **Test:**
  - `ctest --test-dir build` (runs both C++ and QML tests)
  - QML tests: see `src/ui/tests/`, C++ tests: `src/domain/tests/`
- **CI:**
  - See `.github/workflows/cmake.yml` for cross-platform build/test


## Coding & Structure Conventions
**C++:**
  - Modern C++17, RAII, smart pointers, Qt types (`QString`, etc.)
  - One class per file, explicit constructors, parent QObjects
  - Naming: Classes `PascalCase`, methods `camelCase`, members `m_camelCase`
**QML:**
  - One root item per file, explicit `property` declarations
  - Prefer bindings, avoid imperative JS logic
  - Use `import QtQuick 2.15` and `import QtQuick.Controls 2.15`
  - Add `objectName` to elements accessed from tests
**C++/QML Integration:**
  - Expose data via `Q_PROPERTY` with `NOTIFY` signals
  - Keep business logic in C++, UI logic in QML

## Testing
- **Unit tests:** QtTest for C++, QtQuickTest for QML
- **Test structure:**
  - C++: `src/domain/tests/`
  - QML: `src/ui/tests/`
- **Test guidelines:** See `copilot/testing-guidelines.md`

## Updating Project Structure
- Always update all relevant CMake files when adding/removing modules, tests, or resources.
- Document new modules/components in `README.md` and `CHANGELOG.md` as needed.

## References
- [copilot/goals.md](../copilot/goals.md): What must be achieved
- [copilot/coding-guidelines.md](../copilot/coding-guidelines.md): Coding standards
- [copilot/testing-guidelines.md](../copilot/testing-guidelines.md): Testing strategy
- [copilot/tech-stack.md](../copilot/tech-stack.md): Tech stack
- [README.md](../README.md): Project overview, build/run instructions
- [CONTRIBUTING.md](../CONTRIBUTING.md): Contribution process

---
**Example:**
- To add a new QML component, place it in `src/ui/`, update `src/ui/CMakeLists.txt`, and add necessery tests in `src/ui/tests/`.
- For new C++ logic, add to `src/domain/`, update `src/domain/CMakeLists.txt`, and necessery tests in `src/domain/tests/`.
