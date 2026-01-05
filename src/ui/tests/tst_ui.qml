import QtQuick 2.15
import QtTest 1.15

TestCase {
    name: "RootViewTest"

    function findChildByObjectName(item, name) {
        if (!item)
            return null;
        if (item.objectName === name)
            return item;
        if (item.children) {
            for (var i = 0; i < item.children.length; ++i) {
                var found = findChildByObjectName(item.children[i], name);
                if (found)
                    return found;
            }
        }
        return null;
    }

    function test_example() {
        var component = Qt.createComponent("RootView.qml");
        if (component.status === Component.Error) {
            console.error("Component error:", component.errorString());
        }
        verify(component.status === Component.Ready, "Component should be ready");
        var view = component.createObject(this);
        verify(view !== null, "RootView instance should be created");

        var textItem = findChildByObjectName(view, "helloWorldText");
        verify(textItem !== null, "helloWorldText should exist");
        compare(textItem.text, "Hello world");

        view.destroy();
    }
}
