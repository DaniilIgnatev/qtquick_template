# Contributing to AI-Generated QtQuick Template

Thank you for considering contributing!

## How to Contribute
- Fork the repository and create your branch from `main`.
- Follow the coding and testing guidelines in the `copilot/` folder.
- For new features, add relevant documentation and tests.
- For bug fixes, add a clear description and test case.
- Use clang-format for C++ code style.
- For QML, follow the style in existing files.

## Pull Request Process
- Ensure all tests pass (CI/CD will check automatically).
- Update the changelog for significant changes.
- Describe your changes clearly in the PR.

## Code Organization
- Domain logic should be in `src/domain/` (domain.cpp/hpp)
- UI components in `src/ui/` (QML files)
- Tests consolidated per module (e.g., test_domain.cpp for all domain tests)
- All C++ types for QML must be registered in `src/app/qml_type_registration.cpp`

## License
By contributing, you agree your code will be released under the MIT License.
