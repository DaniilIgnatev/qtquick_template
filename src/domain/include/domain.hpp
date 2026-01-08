#pragma once

#include <QObject>
#include <QString>

// ============================================================================
// REFERENCE EXAMPLE: JoystickViewModel
// ============================================================================
// This is a working reference implementation demonstrating:
// - Complete C++/QML MVVM pattern
// - Q_PROPERTY bindings for reactive UI
// - Q_INVOKABLE methods for QML interaction
// - Proper signal emission and state management
//
// USAGE: Study this example to understand the pattern, then:
// 1. Define your requirements in copilot/requirements/1_gathering/input.md
// 2. Replace this class with your own domain logic
// 3. Update src/app/qml_type_registration.cpp to register your types
// 4. Create your UI in src/ui/RootView.qml
// 5. Write tests following the examples in tests/
//
// For simple projects: Keep domain.hpp/cpp and replace JoystickViewModel
// For larger projects: Split into multiple files (MyViewModel.hpp/cpp, etc.)
// ============================================================================

/**
 * @brief ViewModel for the Joystick Hello World application (REFERENCE EXAMPLE)
 *
 * Manages the state and behavior of a movable label controlled by directional buttons.
 * Implements the MVVM pattern with Qt property bindings for reactive UI updates.
 */
class JoystickViewModel : public QObject {
    Q_OBJECT
    Q_PROPERTY(qreal labelX READ labelX NOTIFY labelXChanged)
    Q_PROPERTY(qreal labelY READ labelY NOTIFY labelYChanged)
    Q_PROPERTY(QString labelText READ labelText NOTIFY labelTextChanged)

   public:
    explicit JoystickViewModel(QObject* parent = nullptr);

    qreal labelX() const;
    qreal labelY() const;
    QString labelText() const;

    Q_INVOKABLE void moveUp();
    Q_INVOKABLE void moveDown();
    Q_INVOKABLE void moveLeft();
    Q_INVOKABLE void moveRight();
    Q_INVOKABLE void centerLabel();

   signals:
    void labelXChanged();
    void labelYChanged();
    void labelTextChanged();

   private:
    static constexpr qreal MOVE_STEP = 20.0;
    qreal m_labelX;
    qreal m_labelY;
    QString m_labelText;
};