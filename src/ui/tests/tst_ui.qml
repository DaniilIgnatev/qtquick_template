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

    function test_joystick_controls() {
        var component = Qt.createComponent("RootView.qml");
        if (component.status === Component.Error) {
            console.error("Component error:", component.errorString());
        }
        verify(component.status === Component.Ready, "Component should be ready");
        var view = component.createObject(this);
        verify(view !== null, "RootView instance should be created");

        var textItem = findChildByObjectName(view, "movableLabel");
        verify(textItem !== null, "movableLabel should exist");
        compare(textItem.text, "Hello, world!");

        var upButton = findChildByObjectName(view, "upButton");
        verify(upButton !== null, "upButton should exist");

        var downButton = findChildByObjectName(view, "downButton");
        verify(downButton !== null, "downButton should exist");

        var leftButton = findChildByObjectName(view, "leftButton");
        verify(leftButton !== null, "leftButton should exist");

        var rightButton = findChildByObjectName(view, "rightButton");
        verify(rightButton !== null, "rightButton should exist");

        var centerButton = findChildByObjectName(view, "centerButton");
        verify(centerButton !== null, "centerButton should exist");

        // Test initial position (centered)
        var initialX = textItem.x;
        var initialY = textItem.y;

        // Test movement
        rightButton.clicked();
        verify(textItem.x > initialX, "Label should move right");

        downButton.clicked();
        verify(textItem.y > initialY, "Label should move down");

        // Test center button
        centerButton.clicked();
        compare(textItem.x, initialX, "Label X should return to center");
        compare(textItem.y, initialY, "Label Y should return to center");

        view.destroy();
    }
}
