#include "domain.hpp"

// JoystickViewModel: Reference implementation example
// Replace this with your own domain logic based on requirements
JoystickViewModel::JoystickViewModel(QObject* parent)
    : QObject(parent), m_labelX(0.0), m_labelY(0.0), m_labelText("Hello, world!") {}

qreal JoystickViewModel::labelX() const {
    return m_labelX;
}

void JoystickViewModel::setLabelX(qreal x) {
    if (m_labelX != x) {
        m_labelX = x;
        emit labelXChanged();
    }
}

qreal JoystickViewModel::labelY() const {
    return m_labelY;
}

void JoystickViewModel::setLabelY(qreal y) {
    if (m_labelY != y) {
        m_labelY = y;
        emit labelYChanged();
    }
}

QString JoystickViewModel::labelText() const {
    return m_labelText;
}

void JoystickViewModel::moveUp() {
    setLabelY(m_labelY - MOVE_STEP);
}

void JoystickViewModel::moveDown() {
    setLabelY(m_labelY + MOVE_STEP);
}

void JoystickViewModel::moveLeft() {
    setLabelX(m_labelX - MOVE_STEP);
}

void JoystickViewModel::moveRight() {
    setLabelX(m_labelX + MOVE_STEP);
}

void JoystickViewModel::centerLabel() {
    setLabelX(0.0);
    setLabelY(0.0);
}