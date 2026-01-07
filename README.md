# QtQuick Template Project with AI

[![CMake Build & Test](https://github.com/USERNAME/qtquick_template/actions/workflows/cmake.yml/badge.svg)](https://github.com/USERNAME/qtquick_template/actions/workflows/cmake.yml)

## Version
**Current Version:** 1.0.0  
See [releases](https://github.com/USERNAME/qtquick_template/releases) for version history and release notes.

## Overview
This template demonstrates how to use AI-assisted workflows (e.g., GitHub Copilot) to generate QtQuick applications with C++ backend logic. It is designed for rapid prototyping, demos, and educational purposes.

## Features
- Modular CMake-based build system
- QtQuick 2.15 UI with MVVM pattern
- C++17 backend logic
- Example QML and C++ unit tests
- Cross-platform: Desktop & WebAssembly
- Stepwise requirements analysis pipeline (see copilot/requirements_analysis/)
- YAML-driven requirements artifacts for automation
- Coding/testing guidelines included
- **Working Reference Example**: Joystick demo showing complete MVVM implementation

## Getting Started
### Prerequisites
- Qt 6.8.3+ (with Quick, QuickWidgets, Widgets)
- CMake 3.27+
- C++17 compiler

### Requirements Analysis Pipeline
The requirements pipeline is in `copilot/requirements_analysis/` and consists of:
- **1_gathering**: Stakeholder/context input (**Markdown** for initial unstructured input)
- **2_analysis**: Raw requirements to structured format (**YAML** input/output)
- **3_specification**: Detailed specs and acceptance criteria (**YAML** input/output)
- **4_validation**: Validation results (**YAML** input/output)
- **5_final**: Finalized requirements/specs (**YAML** input/output)

**File Format Convention:** Step 1 uses `.md` for unstructured input; all subsequent steps use `.yaml` only.

Each step has:
- `input.yaml`/`input.md` and `output.yaml` (see each step's instructions.md)
- Example subfolder for sample input/output

### Build & Run
```sh
cmake -S . -B build
cmake --build build
./build/src/app/app.app/Contents/MacOS/app # macOS example
```

### Run Tests
```sh
ctest --test-dir build
```

## Project Structure
- `src/app/` – Application entry point
- `src/ui/` – QML UI components
- `src/domain/` – Business logic, models
- `tests/` – Top-level test config
- `copilot/requirements_analysis/` – Stepwise requirements pipeline (see instructions.md in each step)
- `copilot/` – Guidelines and requirements

## Requirements Analysis Pipeline

See [copilot/requirements_analysis/](copilot/requirements_analysis/) for the full stepwise requirements pipeline, YAML formats, and example-driven workflow. Each step's instructions.md describes the required input/output and formatting.

## C++/QML Type Registration

All C++/QML type registration is centralized for scalability and testability. See:

- [copilot/cpp-qml-type-registration.md](copilot/cpp-qml-type-registration.md) — for the full pattern and test integration instructions.

## Template Usage Pattern

**This template includes a working reference implementation (JoystickViewModel) that demonstrates:**
- Complete C++/QML MVVM pattern
- Q_PROPERTY bindings for reactive UI
- Q_INVOKABLE methods for QML interaction
- Comprehensive test coverage (C++, QML, system integration)
- Clean code organization in `domain.cpp/hpp`

**To use this template for your application:**

1. **Define your requirements**: Start with `copilot/requirements_analysis/1_gathering/input.md`
2. **Replace reference implementation**: 
   - For simple projects: Keep `domain.hpp/domain.cpp` and replace `JoystickViewModel` with your own domain logic classes
   - For larger projects: Replace `domain.hpp/domain.cpp` with your own application-specific files (e.g., `MyAppViewModel.hpp/cpp`, `DataModel.hpp/cpp`, etc.)
3. **Update QML registration**: Modify `src/app/qml_type_registration.cpp` to register your types
4. **Create your UI**: Replace `src/ui/RootView.qml` with your application UI
5. **Update tests**: Replace reference tests in `src/domain/tests/` and `src/ui/tests/` with your own

**Key Pattern:** This template consolidates all domain logic in `domain.cpp/hpp` for simplicity. For larger applications, you can split into multiple files as needed.

**Study the reference implementation** before removing it to understand the complete workflow.

**Key Pattern:** All domain logic lives in domain.cpp/hpp - simply replace JoystickViewModel with your own logic for new use cases.

## Usage as a Template
- Fork or copy this repo
- Replace UI and domain logic as needed
- Follow coding/testing guidelines in `copilot/`

## License
See LICENSE file (MIT recommended)

## Contributing
See CONTRIBUTING.md for template usage and contribution rules.

## Changelog
See CHANGELOG.md for version history.
