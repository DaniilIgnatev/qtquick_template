# Requirements Analysis Pipeline Instructions

This document describes a generic, step-by-step pipeline for requirements analysis. Each stage is located in its own numbered folder under `copilot/requirements/`, with separate input and output files for clarity and traceability.

## Pipeline Overview


| Step | Folder          | Input File                   | Purpose of Input File                                                                 | Output File                |
|------|-----------------|------------------------------|--------------------------------------------------------------------------------------|----------------------------|
| 1    | 1_gathering     | input.md                     | Collects all initial sources: stakeholder notes, sketches, and context (Markdown)     | output.yaml                |
|      |                 | input_images/                | (Optional) UI sketches to be translated into text requirements                        |                            |
| 2    | 2_analysis      | input.yaml                   | Copy/reference of raw requirements for analysis, clarification, and prioritization    | output.yaml                |
| 3    | 3_specification | input.yaml                   | Copy/reference of structured requirements for detailed specification                  | output.yaml                |
| 4    | 4_validation    | input.yaml                   | Copy/reference of specifications for validation planning and execution                | output.yaml                |
| 5    | 5_final         | input.yaml                   | Copy/reference of validated specs for final documentation and sign-off                | output.yaml                |

## Step-by-Step Instructions




### 1. Requirements Gathering (`1_gathering`)
- See [1_gathering/instructions.md](1_gathering/instructions.md) for step details.




### 2. Requirements Analysis (`2_analysis`)
- See [2_analysis/instructions.md](2_analysis/instructions.md) for step details.




### 3. Specification (`3_specification`)
- See [3_specification/instructions.md](3_specification/instructions.md) for step details.




### 4. Validation (`4_validation`)
- See [4_validation/instructions.md](4_validation/instructions.md) for step details.




### 5. Documentation/Finalization (`5_final`)
- See [5_final/instructions.md](5_final/instructions.md) for step details.

## Notes
- Each output file should be used as the input for the next step (copy or reference as needed).
- **File Format Convention:** Step 1 (gathering) uses `input.md` for initial unstructured input, all subsequent steps use `input.yaml` and `output.yaml` (YAML only).
- This structure is generic and can be adapted for different project needs.
- Use clear, concise language in all files for traceability and collaboration.
