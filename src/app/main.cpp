#include <QApplication>
#include <QLabel>
#include <QMainWindow>
#include <QQmlContext>
#include <QQuickView>
#include <QQuickWidget>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QWidget>

#include "qml_type_registration.hpp"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    // Register all C++ types for QML before any QML engine/view is created
    registerQmlTypes();

    QQuickView* quickView = new QQuickView();
    quickView->setSource(QUrl("qrc:/qml/ui/RootView.qml"));

    QWidget* quickViewContainer = QWidget::createWindowContainer(quickView);
    QMainWindow mainWindow;
    mainWindow.setCentralWidget(quickViewContainer);

    mainWindow.resize(600, 400);
    mainWindow.show();

    return app.exec();
}
