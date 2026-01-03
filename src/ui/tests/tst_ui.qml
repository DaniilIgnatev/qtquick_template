import QtQuick 2.15
import QtTest 1.15

TestCase {
    name: "UITest"

    function test_quickWidgetTabText() {
        var item = createTemporaryObject("../QuickWidgetTab.qml", parent);
        compare(item.Text.text, "This is QML via QQuickWidget");
    }

    function test_quickViewTabText() {
        var item = createTemporaryObject("../QuickViewTab.qml", parent);
        compare(item.Text.text, "This is QML via QQuickView (QWindow)");
    }
}
