# Architecture - Joystick Hello World

## Overview
This architecture implements a simple MVVM-based QtQuick application for demonstrating AI-assisted development workflows. The design prioritizes clarity, testability, and educational value over production-grade complexity.

**Key Requirements Addressed:**
- RQ-1 to RQ-6: Movable label with directional controls
- RQ-7: Demo/educational focus (simplicity)

## Architectural Pattern: MVVM

The application follows Model-View-ViewModel pattern with QML View and C++ ViewModel.

**Rationale:**
- Requirements (RQ-1 to RQ-6) demand reactive UI that updates on user interaction
- MVVM provides clean separation: QML handles presentation, C++ handles logic
- Qt's Q_PROPERTY and signals/slots make MVVM natural and efficient
- Improves testability: ViewModel can be tested independently of UI

**Trade-offs:**
- Slight overhead compared to direct QML logic
- Benefit: Clearer architecture, easier to maintain and extend

## Architecture Layers

### Application Layer
**Purpose:** Application bootstrapping and C++/QML integration

**Components:**
- **main.cpp:** Entry point that creates QGuiApplication, calls type registration, creates QQmlApplicationEngine, and loads RootView.qml
- **qml_type_registration.cpp/hpp:** Centralized registration of C++ types for QML access using `qmlRegisterType<JoystickViewModel>("App.Domain", 1, 0, "JoystickViewModel")`

**Design Decision:** Centralized type registration (not in main.cpp)
- Rationale: Scalability, testability, follows Qt best practices
- See `copilot/cpp-qml-type-registration.md` for pattern details
- Trade-off: Extra indirection for simple apps, but consistent pattern that scales

### UI Layer
**Purpose:** Declarative presentation layer

**Components:**
- **RootView.qml:** Main QML view containing layout and UI elements
  - Instantiates JoystickViewModel
  - Contains Text element (objectName: "movableLabel") displaying and positioned by ViewModel
  - Contains five Button elements: upButton, downButton, leftButton, rightButton, centerButton
  - Layout: Column with buttons arranged in cross pattern

**Property Bindings:**
- `Text.text` ← `viewModel.labelText` (displays ViewModel text)
- `Text.x` ← `viewModel.labelX` (horizontal position)
- `Text.y` ← `viewModel.labelY` (vertical position)

**Command Bindings:**
- Each Button's `onClicked` invokes corresponding ViewModel method (moveUp/Down/Left/Right/centerLabel)

**Design Decision:** Property-based reactivity
- Rationale: Requirements demand fluid UI updates (RQ-4, RQ-5); QML bindings automatically react to property changes
- Trade-off: Extra boilerplate (NOTIFY signals) vs. automatic UI synchronization
- Decision: Worth it for demo clarity and correctness

### Domain Layer
**Purpose:** Business logic and state management

**Components:**
- **JoystickViewModel (C++ QObject):** Located in `src/domain/domain.hpp/cpp`
  - Manages label position and text
  - Exposes state via Q_PROPERTY, commands via Q_INVOKABLE

**Properties (Q_PROPERTY with NOTIFY):**
- `labelX` (qreal): Horizontal position of label
- `labelY` (qreal): Vertical position of label  
- `labelText` (QString): Text content (initially "Hello, world!")

**Methods (Q_INVOKABLE):**
- `moveUp()`: Decrements labelY by MOVE_STEP
- `moveDown()`: Increments labelY by MOVE_STEP
- `moveLeft()`: Decrements labelX by MOVE_STEP
- `moveRight()`: Increments labelX by MOVE_STEP
- `centerLabel()`: Resets labelX and labelY to 0

**Constants:**
- `MOVE_STEP = 20.0` pixels per movement

**Internal State:**
- `m_labelX`, `m_labelY`, `m_labelText` (private members)

**Design Decision:** Consolidated domain logic in single ViewModel class
- Rationale: RQ-7 demo simplicity; small scope doesn't justify separate Model class
- Trade-off: Less modular, but lower cognitive load for educational purposes
- Can be split later if requirements grow

**Design Decision:** Command pattern for user actions (Q_INVOKABLE methods)
- Rationale: Clean separation, QML calls commands instead of manipulating state directly
- Alternative considered: Direct property manipulation from QML (rejected: breaks encapsulation, harder to test)

**Design Decision:** 20px movement step
- Rationale: Visible but not jarring for demo purposes
- Trade-off: Hard-coded vs. configurable (chose simplicity per RQ-7)

## Data Flows

### User Interaction Flow
When user clicks a directional button:

1. User clicks button in RootView.qml (e.g., upButton)
2. QML `onClicked` handler invokes `viewModel.moveUp()`
3. JoystickViewModel executes `moveUp()`: `m_labelY -= MOVE_STEP`
4. ViewModel emits `labelYChanged()` signal
5. QML property binding reacts: `Text.y = viewModel.labelY`
6. QtQuick engine triggers re-render with new position

**Design Decision:** Unidirectional data flow
- Rationale: QML never mutates ViewModel state directly; commands flow UI→ViewModel, state flows ViewModel→UI
- Prevents synchronization bugs, makes behavior predictable and debuggable

See `dataflow.puml` for visual sequence diagram.

### Initialization Flow
Application startup sequence:

1. `main.cpp` creates QGuiApplication
2. Calls `registerQmlTypes()` from qml_type_registration
3. `qmlRegisterType<JoystickViewModel>()` registers type with QML engine
4. Creates QQmlApplicationEngine and loads RootView.qml
5. RootView.qml instantiates JoystickViewModel
6. JoystickViewModel constructor initializes properties (labelX=0, labelY=0, labelText="Hello, world!")
7. QML establishes property bindings
8. QtQuick renders initial UI state

## Testing Architecture

**Three-layer strategy:** Unit (C++), Integration (QML), System (full app)

**Rationale:**
- Requirements validation needs comprehensive coverage
- Each layer targets different failure modes:
  - Unit: Logic errors in ViewModel
  - Integration: QML/C++ binding issues  
  - System: Full application lifecycle problems

**Why not just system tests?** Slow feedback, hard to diagnose, can't test edge cases easily

**Why not just unit tests?** Miss integration issues (type registration, property bindings), don't validate actual workflows

### Unit Tests: test_domain.cpp
- Framework: QtTest
- Scope: JoystickViewModel business logic in isolation
- Coverage: Initial state, moveUp/Down/Left/Right logic, centerLabel, property signals
- Test count: 7 tests

### Integration Tests: tst_ui.qml
- Framework: QtQuickTest
- Scope: QML/C++ integration, UI bindings
- Coverage: Component loading, property bindings, button clicks, objectName access

### System Tests: test_system.cpp
- Framework: QtTest
- Scope: End-to-end application behavior
- Coverage: Full lifecycle, integration of all components

**Test Reusability:** System tests reuse `qml_type_registration` code, ensuring test environment matches production

See `copilot/testing-guidelines.md` for comprehensive testing strategy.

## Technology Stack Alignment

Architecture fully complies with constraints in `copilot/tech-stack.md`:
- **CMake:** Modular build system
- **MVVM:** Required design pattern ✓
- **QtQuick 2.15:** UI framework (not using newer Qt 6-only features) ✓
- **C++17:** Backend logic ✓
- **Qt Quick Test:** Unit testing ✓
- **Cross-platform:** Desktop and WebAssembly support ✓

## Design Constraints Impact

**RQ-7 (Demo Simplicity):**
- Domain logic consolidated in single ViewModel (not separate Model)
- Hard-coded constants instead of configuration
- Minimal error handling

**QtQuick 2.15:**
- Use compatible QML subset only
- Avoid Qt 6+ features

**C++17:**
- Modern C++ features available (smart pointers, auto, etc.)

**Cross-platform:**
- No platform-specific code
- Pure Qt/QML implementation

## Non-Goals (RQ-7 Compliance)
- No production-grade architecture (dependency injection, plugin system)
- No complex state management (Redux-like patterns)
- No network/database layers
- No sophisticated error handling
- No persistence

## Future Extensibility
If requirements evolve beyond demo scope:
- Split ViewModel and Model into separate classes
- Add dependency injection framework
- Introduce service layer for complex logic
- Add configuration management system
- Implement state persistence

## Visual Documentation
- `structure.puml` - Component relationships diagram (complex many-to-many relationships benefit from visual representation)
- `dataflow.puml` - User interaction sequence diagram (temporal flow visualization)

## References
- `copilot/requirements/5_final/output.yaml` - Final requirements
- `copilot/coding-guidelines.md` - C++/QML coding standards
- `copilot/testing-guidelines.md` - Testing strategy
- `copilot/cpp-qml-type-registration.md` - Type registration pattern
- `copilot/tech-stack.md` - Technology constraints
