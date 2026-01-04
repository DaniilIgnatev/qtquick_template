#include <QApplication>
#include <QLabel>
#include <QMainWindow>
#include <QQmlContext>
#include <QQuickView>
#include <QQuickWidget>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QWidget>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    QQuickView* quickView = new QQuickView();
    quickView->setSource(QUrl("qrc:/qml/ui/QuickView.qml"));

    QWidget* quickViewContainer = QWidget::createWindowContainer(quickView);
    QMainWindow mainWindow;
    mainWindow.setCentralWidget(quickViewContainer);

    mainWindow.resize(600, 400);
    mainWindow.show();

    return app.exec();
}
