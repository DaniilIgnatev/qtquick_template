#include <QApplication>
#include <QLabel>
#include <QMainWindow>
#include <QQuickView>
#include <QQuickWidget>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QtTest/QtTest>

// POC system test: launches the main window and checks all tabs/components are present

class SystemTest : public QObject {
    Q_OBJECT
   public:
    SystemTest() {
        m_mainWindow = new QMainWindow();
        m_tabs = new QTabWidget(m_mainWindow);

        // QWidget tab
        m_widgetTab = new QWidget();
        QVBoxLayout* widgetLayout = new QVBoxLayout(m_widgetTab);
        m_label = new QLabel("This is a pure QWidget tab");
        widgetLayout->addWidget(m_label);
        m_tabs->addTab(m_widgetTab, "QWidget");

        // QQuickWidget tab
        m_quickWidgetTab = new QQuickWidget();
        m_quickWidgetTab->setResizeMode(QQuickWidget::SizeRootObjectToView);
        m_quickWidgetTab->setSource(QUrl("qrc:/qml/ui/QuickWidgetTab.qml"));
        m_tabs->addTab(m_quickWidgetTab, "QQuickWidget");

        // QQuickView tab
        m_quickView = new QQuickView();
        m_quickView->setSource(QUrl("qrc:/qml/ui/QuickViewTab.qml"));
        m_quickViewContainer = QWidget::createWindowContainer(m_quickView);
        m_tabs->addTab(m_quickViewContainer, "QQuickView");

        m_mainWindow->setCentralWidget(m_tabs);
        m_mainWindow->resize(600, 400);
        m_mainWindow->show();
    }

    ~SystemTest() override {
        m_mainWindow->close();
        delete m_mainWindow;
        // All children are deleted by Qt parent ownership
    }

   private slots:
    void test_app_components() {
        // Test: all tabs present
        QCOMPARE(m_tabs->count(), 3);
        QCOMPARE(m_tabs->tabText(0), QString("QWidget"));
        QCOMPARE(m_tabs->tabText(1), QString("QQuickWidget"));
        QCOMPARE(m_tabs->tabText(2), QString("QQuickView"));

        // Test: QWidget tab label
        m_tabs->setCurrentIndex(0);
        QLabel* foundLabel = m_widgetTab->findChild<QLabel*>();
        QVERIFY(foundLabel);
        QCOMPARE(foundLabel->text(), QString("This is a pure QWidget tab"));

        // Test: QQuickWidget loads QML
        m_tabs->setCurrentIndex(1);
        QVERIFY(m_quickWidgetTab->rootObject());

        // Test: QQuickView loads QML
        m_tabs->setCurrentIndex(2);
        QVERIFY(m_quickView->rootObject());
    }

   private:
    QMainWindow* m_mainWindow = nullptr;
    QTabWidget* m_tabs = nullptr;
    QWidget* m_widgetTab = nullptr;
    QLabel* m_label = nullptr;
    QQuickWidget* m_quickWidgetTab = nullptr;
    QQuickView* m_quickView = nullptr;
    QWidget* m_quickViewContainer = nullptr;
};

QTEST_MAIN(SystemTest)
#include "test_system.moc"
