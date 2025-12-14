#include <QApplication>
#include <QMainWindow>
#include <QTabWidget>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>

#include <QQuickWidget>
#include <QQuickView>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QMainWindow mainWindow;
    QTabWidget* tabs = new QTabWidget(&mainWindow);

    // -------------------------------------------------
    // TAB 1: Pure QWidget
    // -------------------------------------------------
    QWidget* widgetTab = new QWidget();
    QVBoxLayout* widgetLayout = new QVBoxLayout(widgetTab);
    widgetLayout->addWidget(new QLabel("This is a pure QWidget tab"));
    tabs->addTab(widgetTab, "QWidget");

    // -------------------------------------------------
    // TAB 2: QQuickWidget (QML inside QWidget)
    // -------------------------------------------------
    QQuickWidget* quickWidgetTab = new QQuickWidget();
    quickWidgetTab->setResizeMode(QQuickWidget::SizeRootObjectToView);
    quickWidgetTab->setSource(QUrl("qrc:/qml/com/infineon/bms/qml/QuickWidgetTab.qml"));
    tabs->addTab(quickWidgetTab, "QQuickWidget");

    // -------------------------------------------------
    // TAB 3: QQuickView wrapped with createWindowContainer
    // -------------------------------------------------
    QQuickView* quickView = new QQuickView();
    quickView->setSource(QUrl("qrc:/qml/com/infineon/bms/qml/QuickViewTab.qml"));

    QWidget* quickViewContainer =
        QWidget::createWindowContainer(quickView);

    tabs->addTab(quickViewContainer, "QQuickView");

    // -------------------------------------------------

    mainWindow.setCentralWidget(tabs);
    mainWindow.resize(600, 400);
    mainWindow.show();

    return app.exec();
}
