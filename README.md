# AI-Generated QtQuick Template Project

## Overview
This template demonstrates how to use AI-assisted workflows (e.g., GitHub Copilot) to generate QtQuick applications with C++ backend logic. It is designed for rapid prototyping, demos, and educational purposes.

## Features
- Modular CMake-based build system
- QtQuick 2.15 UI with MVVM pattern
- C++17 backend logic
- Example QML and C++ unit tests
- Cross-platform: Desktop & WebAssembly
- Coding/testing guidelines included

## Getting Started
### Prerequisites
- Qt 6.10+ (with Quick, QuickWidgets, Widgets)
- CMake 3.22+
- C++17 compiler

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
- `copilot/` – Guidelines and requirements

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
