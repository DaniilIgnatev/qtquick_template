import QtQuick 2.15
import QtQuick.Controls 2.15
import App.Domain 1.0

Rectangle {
    id: rootView
    color: "white"
    anchors.fill: parent

    // JoystickViewModel: Current reference implementation for demo
    JoystickViewModel {
        id: viewModel
    }

    Column {
        id: contentColumn
        anchors.centerIn: parent
        spacing: 32

        Text {
            id: helloWorldText
            objectName: "helloWorldText"
            text: viewModel.labelText
            font.pixelSize: 32
            color: "#222"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            x: viewModel.labelX
            y: viewModel.labelY
        }

        Column {
            spacing: 8
            anchors.horizontalCenter: parent.horizontalCenter

            // Up button
            Button {
                id: upButton
                objectName: "upButton"
                text: "↑"
                width: 60
                height: 60
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: viewModel.moveUp()
            }

            Row {
                spacing: 8
                anchors.horizontalCenter: parent.horizontalCenter

                // Left button
                Button {
                    id: leftButton
                    objectName: "leftButton"
                    text: "←"
                    width: 60
                    height: 60
                    onClicked: viewModel.moveLeft()
                }

                // Spacer
                Item {
                    width: 60
                    height: 60
                }

                // Right button
                Button {
                    id: rightButton
                    objectName: "rightButton"
                    text: "→"
                    width: 60
                    height: 60
                    onClicked: viewModel.moveRight()
                }
            }

            // Down button
            Button {
                id: downButton
                objectName: "downButton"
                text: "↓"
                width: 60
                height: 60
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: viewModel.moveDown()
            }

            // Center button
            Button {
                id: centerButton
                objectName: "centerButton"
                text: "Center"
                width: 128
                height: 40
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: viewModel.centerLabel()
            }
        }
    }
}
