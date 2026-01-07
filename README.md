# QtQuick Template Project with AI

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
- **Reference: Joystick Demo** – C++/QML MVVM, joystick-style UI, full requirements pipeline, and test coverage

## Getting Started
### Prerequisites
- Qt 6.8.3+ (with Quick, QuickWidgets, Widgets)
- CMake 3.27+
- C++17 compiler

### Requirements Analysis Pipeline
The requirements pipeline is in `copilot/requirements_analysis/` and consists of:
- 1_gathering: Stakeholder/context input (Markdown or images)
- 2_analysis: Raw requirements to structured YAML
- 3_specification: Detailed specs and acceptance criteria (YAML)
- 4_validation: Validation results (YAML)
- 5_final: Finalized requirements/specs (YAML)

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

## Reference Example: Joystick Demo

This template includes a full-featured joystick demo:
- Requirements pipeline artifacts for a joystick UI (see copilot/requirements_analysis/)
- C++ domain logic (JoystickViewModel) consolidated in domain.cpp/hpp with Q_PROPERTY and Q_INVOKABLE
- QML UI with objectName for testability
- Consolidated test suite in test_domain.cpp (all tests passing)
- See `src/domain/include/domain.hpp` and `src/ui/RootView.qml`

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
