# Architecture Decisions and Rationale - Joystick Hello World

## Overview
This architecture implements a simple MVVM-based QtQuick application for demonstrating AI-assisted development workflows. The design prioritizes clarity, testability, and educational value over production-grade complexity.

**Key Requirements Addressed:**
- RQ-1 to RQ-6: Movable label with directional controls
- RQ-7: Demo/educational focus (simplicity)

## Architectural Decisions

### 1. MVVM Pattern
**Decision:** Use Model-View-ViewModel pattern with QML View and C++ ViewModel.

**Rationale:**
- Requirements (RQ-1 to RQ-6) demand reactive UI that updates on user interaction
- MVVM provides clean separation: QML handles presentation, C++ handles logic
- Qt's Q_PROPERTY and signals/slots make MVVM natural and efficient
- Improves testability: ViewModel can be tested independently of UI

**Trade-offs:**
- Slight overhead compared to direct QML logic
- Benefit: Clearer architecture, easier to maintain and extend

### 2. Consolidated Domain Logic
**Decision:** Keep all domain logic in `domain.hpp/domain.cpp` (JoystickViewModel)

**Rationale:**
- RQ-7: Demo purposes - simplicity over modularity
- Small application scope doesn't justify multiple domain classes
- Easier to understand for educational purposes
- Can be split later if requirements grow

**Trade-offs:**
- Less modular than separate Model/ViewModel classes
- Benefit: Lower cognitive load for demo audience

### 3. Centralized QML Type Registration
**Decision:** All C++/QML type registration in `qml_type_registration.cpp`

**Rationale:**
- Scalability: Easy to add new types without touching main.cpp
- Testability: Registration can be reused in test executables
- Follows Qt best practices for larger applications
- See `copilot/cpp-qml-type-registration.md` for pattern details

**Trade-offs:**
- Extra indirection for simple apps
- Benefit: Consistent pattern that scales

### 4. Property-Based Reactivity
**Decision:** Use Q_PROPERTY with NOTIFY signals for all ViewModel state

**Rationale:**
- Requirements demand fluid UI updates (RQ-4, RQ-5)
- QML bindings automatically react to property changes
- Declarative approach reduces imperative code
- Aligns with Qt/QML best practices

**Trade-off:** Slight overhead vs. manual updates
- Cost: Extra boilerplate (NOTIFY signals, getter methods)
- Benefit: Automatic UI synchronization, no manual update calls
- Decision: Worth it for demo clarity and correctness

### 5. Command Pattern for User Actions
**Decision:** Q_INVOKABLE methods for button actions

**Rationale:**
- Clean separation: QML calls commands, doesn't manipulate state directly
- Easier to test and extend (can mock commands)
- Follows command pattern idiom familiar to developers

**Alternative Considered:** Direct property manipulation from QML
- Rejected: Breaks encapsulation, harder to test, couples UI to state representation

### 6. Three-Layer Testing Strategy
**Decision:** Unit (C++), Integration (QML), System (full app) tests

**Rationale:**
- Requirements validation needs comprehensive coverage
- Each layer targets different failure modes:
  - Unit: Logic errors in ViewModel
  - Integration: QML/C++ binding issues
  - System: Full application lifecycle problems

**Why Not Just System Tests?**
- Slow feedback loop
- Hard to diagnose failures
- Cannot test edge cases easily

**Why Not Just Unit Tests?**
- Miss integration issues (type registration, property bindings)
- Don't validate actual user workflows

See `structure.yaml` for test component details and `copilot/testing-guidelines.md` for strategy.

## Component Organization Rationale

### Why Three Layers?
- **Application:** Bootstrapping and integration (unavoidable boilerplate)
- **UI:** Presentation logic (QML strength)
- **Domain:** Business logic (C++ strength)

Clear boundaries improve:
- Testability: each layer tested independently
- Maintainability: changes isolated to appropriate layer
- Educational value: architecture easy to explain

### Why 20px Movement Step?
- Visible but not jarring for demo purposes
- Simple constant, easy to adjust
- Trade-off: Hard-coded vs. configurable (chose simplicity per RQ-7)

## Data Flow Design

See `dataflow.puml` for visual sequence. Key decision: **unidirectional data flow**.

**Rationale:**
- QML never mutates ViewModel state directly
- Commands flow: UI → ViewModel (via Q_INVOKABLE)
- State flows: ViewModel → UI (via Q_PROPERTY bindings)
- Prevents synchronization bugs
- Makes behavior predictable and debuggable

## Technology Stack Alignment

Architecture fully complies with constraints in `copilot/tech-stack.md`. Key decisions driven by stack:
- MVVM chosen (required pattern)
- QtQuick 2.15 (not newer Qt 6 features)
- C++17 features used where appropriate
- Cross-platform design (no platform-specific code)

## Diagrams
- `structure.puml` - Component relationships (see for visual architecture)
- `dataflow.puml` - User interaction sequence (see for runtime behavior)
- `structure.yaml` - Detailed component specifications (see for API details)

## Non-Goals (RQ-7 Compliance)
- No production-grade architecture (e.g., dependency injection, plugin system)
- No complex state management (e.g., Redux-like patterns)
- No network/database layers
- No sophisticated error handling

## Future Extensibility
If requirements evolve beyond demo scope:
- Split ViewModel and Model into separate classes
- Add proper dependency injection
- Introduce service layer for complex logic
- Add configuration management

## References
- `copilot/requirements/5_final/output.yaml` - Final requirements
- `copilot/coding-guidelines.md` - C++/QML coding standards
- `copilot/testing-guidelines.md` - Testing strategy
- `copilot/cpp-qml-type-registration.md` - Type registration pattern
- `copilot/tech-stack.md` - Technology constraints
