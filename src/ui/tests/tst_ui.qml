import QtQuick 2.15
import QtTest 1.15

TestCase {
    name: "UITest"

    function test_quickWidgetTabText() {
        var component = Qt.createComponent("../QuickWidgetTab.qml");
        var item = createTemporaryObject(component, parent);
        var text_item = item.children.find(function (child) {
            return child.objectName === "Text";
        });
        compare(text_item.text, "This is QML via QQuickWidget");
    }

    function test_quickViewTabText() {
        var component = Qt.createComponent("../QuickViewTab.qml");
        var item = createTemporaryObject(component, parent);
        var text_item = item.children.find(function (child) {
            return child.objectName === "Text";
        });
        compare(text_item.text, "This is QML via QQuickView (QWindow)");
    }
}
