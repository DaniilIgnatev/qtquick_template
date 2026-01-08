# Example: Initial Architecture Idea

## Purpose
Document the architectural thinking and rationale behind the Joystick Hello World demo app.

## Context from Requirements
Driven by `copilot/requirements/5_final/output.yaml`:
- **RQ-1 to RQ-6:** Interactive UI with movable label and directional controls
- **RQ-7:** Demo/educational purpose - prioritize simplicity and clarity over production complexity

## Architectural Reasoning

### Why MVVM?
- Requirements demand reactive UI that updates on user interaction (RQ-4)
- QML excels at declarative bindings, C++ at business logic
- Clear separation improves testability and educational value
- Pattern is well-documented and familiar to Qt developers

### Why Consolidate Model into ViewModel?
- RQ-7 emphasizes demo simplicity
- Application has minimal state (label position, text)
- Separate Model class would add complexity without benefit
- Can be refactored later if scope grows

### Why Centralize QML Type Registration?
- Scalability: easy to add types without touching main.cpp
- Testability: registration code reused in test executables
- Follows Qt best practices for maintainable applications
- Initial overhead pays off in demo clarity

### Why Property-Based Reactivity?
- Aligns with QML's declarative paradigm
- Reduces imperative code ("fluid design" goal from requirements)
- Automatic UI updates on state changes
- No manual synchronization needed

## Design Constraints & Trade-offs

**Constraint:** Demo/educational focus (RQ-7)
- Trade-off: Simplicity over modularity
- Decision: Single ViewModel class instead of layered architecture

**Constraint:** Cross-platform (Desktop + WebAssembly)
- Trade-off: Avoid platform-specific optimizations
- Decision: Pure Qt/QML implementation

**Constraint:** QtQuick 2.15
- Trade-off: Cannot use newer Qt 6 features
- Decision: Stick to widely compatible QML subset

## Open Questions
- Should we add state persistence? (Not in requirements, defer)
- Animation on label movement? (Could enhance demo, discuss with stakeholders)
- Keyboard shortcuts in addition to buttons? (Nice-to-have, not critical)

## References
- `copilot/requirements/5_final/output.yaml` - Requirements
- `structure.yaml` - Component specifications
- `structure.puml` - Component diagram
