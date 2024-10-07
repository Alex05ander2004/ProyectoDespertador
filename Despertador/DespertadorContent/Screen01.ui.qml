

import QtQuick
import QtQuick.Controls

Rectangle {
    width: 640
    height: 480
    color: "lightblue"

    Text {
        text: qsTr("Hello Despertador")
        anchors.centerIn: parent
        font.family: "Arial"
    }

    Button {
        id: button
        text: qsTr("Button")
        anchors.centerIn: parent
    }

    Slider {
        id: slider
        value: 0.5
        anchors.top: button.bottom
        anchors.horizontalCenter: parent
    }

    SpinBox {
        id: spinBox
        anchors.top: slider.bottom
        anchors.horizontalCenter: parent
    }
}
