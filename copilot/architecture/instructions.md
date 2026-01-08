# Architecture Step Instructions

This folder defines the iterative architecture analysis and design process for the project. It is tightly coupled to the requirements pipeline and prioritizes the intent and results from the requirements step.

## Overview
- The architecture step is **iterative**: input, review, refine, and output cycles are encouraged.
- Input can be in natural language (.md), YAML (.yaml), or PlantUML (.puml) formats.
- Output must include both architectural decisions and the rationale behind them.
- PlantUML diagrams are required for all major components and their relationships; minor diagrams are optional.

## Folder Structure
- `input/`  – Raw architectural ideas, sketches, drafts (accepts .md, .yaml, .puml)
- `input/example/` – Reference examples showing correct input format
- `output/` – Finalized architecture artifacts (.md, .yaml, .puml)
- `output/example/` – Reference examples showing correct output format

## File Format Priority (Avoid Redundancy!)

**Priority Order:** Markdown → YAML → PlantUML

Each format has a primary role. Use higher-priority formats first; fall back to lower-priority formats only for what cannot be expressed well in the higher ones.

### 1. Markdown (.md) - PRIMARY DOCUMENTATION
**Priority:** Highest - use this for everything you can
**Purpose:** Comprehensive human-readable architecture documentation
- **Include:** 
  - Overview and goals
  - Architectural decisions with rationale
  - Why decisions were made (requirements, trade-offs, alternatives considered)
  - Component descriptions and responsibilities
  - Design patterns and principles applied
  - Data flow explanations
  - Technology stack alignment
  - Testing strategy rationale
  - References to requirements
  - Future extensibility considerations
- **Exclude:** 
  - Complex structured data (component APIs with many properties/methods → use YAML)
  - Complex visual relationships (many interconnected components → use PlantUML)

### 2. YAML (.yaml) - STRUCTURED SPECIFICATIONS
**Priority:** Secondary - use only for what MD cannot express well
**Purpose:** Formal structured data that's awkward in prose
- **Include:** 
  - Component API specifications (properties, methods, signals)
  - Layer definitions with multiple components
  - Detailed data flow sequences (step-by-step)
  - Configuration schemas
  - Lists with complex nested structure
- **Exclude:** 
  - Rationale or explanations (belongs in MD)
  - Visual relationships (belongs in PlantUML)
  - Anything that reads well as prose (belongs in MD)

### 3. PlantUML (.puml) - VISUAL DIAGRAMS
**Priority:** Lowest - use only for what MD and YAML cannot express well
**Purpose:** Complex relationships and flows that are hard to describe textually
- **Include:** 
  - Component diagrams (many-to-many relationships)
  - Sequence diagrams (temporal flows with multiple actors)
  - Architecture diagrams (spatial/hierarchical relationships)
- **Exclude:** 
  - Simple explanations (belongs in MD)
  - API specs (belongs in YAML)
  - Anything that can be clearly described in text

## Input Guidelines
- Place all initial architectural ideas in the `input/` folder
- Acceptable formats: Markdown (.md), YAML (.yaml), PlantUML (.puml)
- Reference and prioritize the **intent and results** from `copilot/requirements/`
- Link each input to specific requirements (e.g., "Driven by RQ-1, RQ-7")
- See `input/example/` for format guidance

## Output Guidelines
- Place all finalized architecture artifacts in the `output/` folder
- **Required:**
  - `output.md`: **Primary comprehensive documentation** - architecture overview, decisions, rationale, component descriptions, data flows, everything that can be written in prose
  - `structure.yaml`: Structured component API specifications and detailed sequences (use only for data that's awkward in prose)
  - `structure.puml`: Component architecture diagram (use only if relationships are too complex to describe clearly in MD)
  - `dataflow.puml`: Sequence diagram for key workflows (use only if temporal flow is too complex for text)
- **Decision Rule:** Can this be clearly explained in Markdown? → Use MD. If not, can it be structured in YAML? → Use YAML. If not, use PlantUML.
- See `output/example/` for complete working examples

## Iterative Process
1. **Gather:** Create input files (ideas, sketches) in `input/`
2. **Review:** Assess against requirements and technical constraints
3. **Refine:** Update inputs based on feedback and new insights
4. **Formalize:** Create output files with decisions, specs, and diagrams in `output/`
5. **Iterate:** Repeat as requirements or understanding evolve

## Quality Checklist

Before finalizing outputs, verify:
- [ ] Markdown is comprehensive and primary source of truth (not just "why")
- [ ] YAML is used only for structured data that's awkward in prose
- [ ] PlantUML is used only for complex visual relationships
- [ ] No duplication between formats (check: can I delete YAML/PlantUML and still understand architecture from MD alone? If yes, you've over-documented in lower-priority formats)
- [ ] All decisions reference specific requirements (e.g., RQ-1, RQ-7)
- [ ] Trade-offs and alternatives are documented
- [ ] Component responsibilities are clear
- [ ] Data flows are explained (in MD if simple, in YAML+PlantUML if complex)

## References
- **Examples:** See `input/example/` and `output/example/` for authoritative format guidance
- **Requirements:** `copilot/requirements/` - source of architectural intent and constraints
- **PlantUML:** https://plantuml.com/ - diagram syntax reference
- **Tech Stack:** `copilot/tech-stack.md` - technology constraints
- **Guidelines:** `copilot/coding-guidelines.md` - implementation standards
