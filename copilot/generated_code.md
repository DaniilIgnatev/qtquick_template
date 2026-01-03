# Generated vs Manual Code

## Principles
- Generated code (by AI tools) should be placed in dedicated files/folders.
- Manual code is for user customization, extension, and tuning.
- Generated code should be easy to identify and replace.
- Documentation is not split into manual and generated files, instead generated documentation is put together with manual under a corresponding remark.

## Example Structure
- `src/generated/` – AI-generated C++/QML files
- `src/manual/` – User-written C++/QML files
- Document in README and CONTRIBUTING how to add new generated/manual code.

## Usage
- When generating new modules/components, place them in `src/generated/`.
- Manual overrides/extensions go in `src/manual/`.
- Keep clear separation for maintainability and demo value.
