import QtQuick 2.15
import QtQuick.Controls 2.15
import App.Domain 1.0

// ============================================================================
// REFERENCE EXAMPLE: Joystick Hello World UI
// ============================================================================
// This demonstrates:
// - QML/C++ integration via ViewModel
// - Property bindings for reactive UI (text, x, y)
// - Q_INVOKABLE method calls from QML (onClicked handlers)
// - objectName properties for testing
// - Clean layout using Column, Row, spacing
//
// USAGE: Replace this with your application UI based on your requirements
// ============================================================================

/**
 * Main view for the Joystick Hello World application (REFERENCE EXAMPLE)
 * Displays a movable label controlled by directional buttons in a cross pattern
 */
Rectangle {
    id: rootView
    color: "white"
    anchors.fill: parent

    // ViewModel instance - replace with your own ViewModel
    JoystickViewModel {
        id: viewModel
    }

    Column {
        id: contentColumn
        anchors.centerIn: parent
        spacing: 32

        Text {
            id: movableLabel
            objectName: "movableLabel"
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
