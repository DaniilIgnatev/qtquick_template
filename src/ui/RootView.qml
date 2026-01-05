import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    id: rootView
    color: "white"
    anchors.fill: parent

    Column {
        id: contentColumn
        anchors.centerIn: parent
        spacing: 16

        Text {
            id: helloWorldText
            objectName: "helloWorldText"
            text: "Hello world"
            font.pixelSize: 32
            color: "#222"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }
}
