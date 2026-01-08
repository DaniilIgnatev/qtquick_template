#include "domain.hpp"

// ============================================================================
// REFERENCE EXAMPLE IMPLEMENTATION
// Replace this with your own domain logic based on your requirements
// ============================================================================

JoystickViewModel::JoystickViewModel(QObject* parent)
    : QObject(parent), m_labelX(0.0), m_labelY(0.0), m_labelText("Hello, world!") {}

qreal JoystickViewModel::labelX() const {
    return m_labelX;
}

qreal JoystickViewModel::labelY() const {
    return m_labelY;
}

QString JoystickViewModel::labelText() const {
    return m_labelText;
}

void JoystickViewModel::moveUp() {
    if (m_labelY != m_labelY - MOVE_STEP) {
        m_labelY -= MOVE_STEP;
        emit labelYChanged();
    }
}

void JoystickViewModel::moveDown() {
    if (m_labelY != m_labelY + MOVE_STEP) {
        m_labelY += MOVE_STEP;
        emit labelYChanged();
    }
}

void JoystickViewModel::moveLeft() {
    if (m_labelX != m_labelX - MOVE_STEP) {
        m_labelX -= MOVE_STEP;
        emit labelXChanged();
    }
}

void JoystickViewModel::moveRight() {
    if (m_labelX != m_labelX + MOVE_STEP) {
        m_labelX += MOVE_STEP;
        emit labelXChanged();
    }
}

void JoystickViewModel::centerLabel() {
    bool changed = false;
    if (m_labelX != 0.0) {
        m_labelX = 0.0;
        emit labelXChanged();
        changed = true;
    }
    if (m_labelY != 0.0) {
        m_labelY = 0.0;
        emit labelYChanged();
        changed = true;
    }
}