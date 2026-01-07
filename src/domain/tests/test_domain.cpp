#include <QtTest/QtTest>

#include "domain.hpp"

class DomainTest : public QObject {
    Q_OBJECT
   private slots:
    // JoystickViewModel tests - reference implementation example
    void joystickViewModel_initialPosition();
    void joystickViewModel_moveUp();
    void joystickViewModel_moveDown();
    void joystickViewModel_moveLeft();
    void joystickViewModel_moveRight();
    void joystickViewModel_centerLabel();
    void joystickViewModel_labelText();
};

void DomainTest::joystickViewModel_initialPosition() {
    JoystickViewModel vm;
    QCOMPARE(vm.labelX(), 0.0);
    QCOMPARE(vm.labelY(), 0.0);
}

void DomainTest::joystickViewModel_moveUp() {
    JoystickViewModel vm;
    vm.moveUp();
    QCOMPARE(vm.labelY(), -20.0);
}

void DomainTest::joystickViewModel_moveDown() {
    JoystickViewModel vm;
    vm.moveDown();
    QCOMPARE(vm.labelY(), 20.0);
}

void DomainTest::joystickViewModel_moveLeft() {
    JoystickViewModel vm;
    vm.moveLeft();
    QCOMPARE(vm.labelX(), -20.0);
}

void DomainTest::joystickViewModel_moveRight() {
    JoystickViewModel vm;
    vm.moveRight();
    QCOMPARE(vm.labelX(), 20.0);
}

void DomainTest::joystickViewModel_centerLabel() {
    JoystickViewModel vm;
    vm.moveRight();
    vm.moveDown();
    QVERIFY(vm.labelX() != 0.0 || vm.labelY() != 0.0);
    vm.centerLabel();
    QCOMPARE(vm.labelX(), 0.0);
    QCOMPARE(vm.labelY(), 0.0);
}

void DomainTest::joystickViewModel_labelText() {
    JoystickViewModel vm;
    QCOMPARE(vm.labelText(), QString("Hello, world!"));
}

QTEST_MAIN(DomainTest)
#include "test_domain.moc"
