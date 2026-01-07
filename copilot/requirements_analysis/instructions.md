# Requirements Analysis Pipeline Instructions

This document describes a generic, step-by-step pipeline for requirements analysis. Each stage is located in its own numbered folder under `copilot/requirements_analysis/`, with separate input and output files for clarity and traceability.

## Pipeline Overview

| Step | Folder                          | Input File                      | Output File                       |
|------|---------------------------------|---------------------------------|-----------------------------------|
| 1    | 1_gathering                     | input_sources.md                | raw_requirements.md               |
| 2    | 2_analysis                      | raw_requirements_input.md        | structured_requirements.md        |
| 3    | 3_specification                 | requirements_input.md            | specs.md                          |
| 4    | 4_validation                    | specs_input.md                   | validation_report.md              |
| 5    | 5_final                         | validated_specs_input.md         | requirements_final.md             |

## Step-by-Step Instructions

### 1. Requirements Gathering (`1_gathering`)
- **Purpose:** Collect initial requirements from various sources.
- **Input:** `input_sources.md` — Describe sources (e.g., interviews, surveys).
- **Output:** `raw_requirements.md` — List all unprocessed requirements.

### 2. Requirements Analysis (`2_analysis`)
- **Purpose:** Clarify, categorize, and prioritize requirements.
- **Input:** `raw_requirements_input.md` — Copy or reference `1_gathering/raw_requirements.md`.
- **Output:** `structured_requirements.md` — Organized and prioritized requirements.

### 3. Specification (`3_specification`)
- **Purpose:** Translate structured requirements into actionable specifications.
- **Input:** `requirements_input.md` — Copy or reference `2_analysis/structured_requirements.md`.
- **Output:** `specs.md` — Functional and non-functional specifications.

### 4. Validation (`4_validation`)
- **Purpose:** Validate specifications for completeness and feasibility.
- **Input:** `specs_input.md` — Copy or reference `3_specification/specs.md`.
- **Output:** `validation_report.md` — Document validation results and feedback.

### 5. Documentation/Finalization (`5_final`)
- **Purpose:** Finalize and document the agreed requirements and specifications.
- **Input:** `validated_specs_input.md` — Copy or reference `4_validation/validation_report.md`.
- **Output:** `requirements_final.md` — Final requirements/specifications document.

## Notes
- Each output file should be used as the input for the next step (copy or reference as needed).
- This structure is generic and can be adapted for different project needs.
- Use clear, concise language in all files for traceability and collaboration.
