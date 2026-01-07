// tst_runner.cpp
#include <QtQuickTest/quicktest.h>

#include <QQmlContext>
#include <QQmlEngine>

#include "../../app/qml_type_registration.hpp"

class Setup : public QObject {
    Q_OBJECT
   public:
    Setup() { registerQmlTypes(); }
};

QUICK_TEST_MAIN_WITH_SETUP(ui_tests, Setup)
#include "test_ui.moc"
