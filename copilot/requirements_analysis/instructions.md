# Requirements Analysis Pipeline Instructions

This document describes a generic, step-by-step pipeline for requirements analysis. Each stage is located in its own numbered folder under `copilot/requirements_analysis/`, with separate input and output files for clarity and traceability.

## Pipeline Overview


| Step | Folder          | Input File                   | Purpose of Input File                                                                 | Output File                |
|------|-----------------|------------------------------|--------------------------------------------------------------------------------------|----------------------------|
| 1    | 1_gathering     | input_sources.md             | Collects all initial sources: stakeholder notes, sketches, and context                | raw_requirements.md        |
|      |                 | images/                      | (Optional) UI sketches to be translated into text requirements                        |                            |
| 2    | 2_analysis      | raw_requirements_input.md    | Copy/reference of raw requirements for analysis, clarification, and prioritization    | structured_requirements.md |
| 3    | 3_specification | requirements_input.md        | Copy/reference of structured requirements for detailed specification                  | specs.md                   |
| 4    | 4_validation    | specs_input.md               | Copy/reference of specifications for validation planning and execution                | validation_report.md       |
| 5    | 5_final         | validated_specs_input.md      | Copy/reference of validated specs for final documentation and sign-off                | requirements_final.md      |

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
- This structure is generic and can be adapted for different project needs.
- Use clear, concise language in all files for traceability and collaboration.
