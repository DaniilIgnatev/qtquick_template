#include <QApplication>
#include <QLabel>
#include <QMainWindow>
#include <QQuickView>
#include <QQuickWidget>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QtTest/QtTest>
#include "../src/app/qml_type_registration.hpp"

class SystemTest : public QObject {
    Q_OBJECT
   public:
    SystemTest() {
        registerQmlTypes();
        m_quickView = new QQuickView();
        m_quickView->setSource(QUrl("qrc:/qml/ui/RootView.qml"));
        m_quickViewContainer = QWidget::createWindowContainer(m_quickView);
    }

    ~SystemTest() override {}

   private slots:
    void test_app_components() { QVERIFY(m_quickView->rootObject()); }

   private:
    QQuickView* m_quickView = nullptr;
    QWidget* m_quickViewContainer = nullptr;
};

QTEST_MAIN(SystemTest)
#include "test_system.moc"
