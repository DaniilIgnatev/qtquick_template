import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    color: "#d0eaff"
    anchors.fill: parent

    Text {
        objectName: "Text"
        text: "This is QML via QQuickWidget"
        anchors.centerIn: parent
        font.pixelSize: 18
    }
}
