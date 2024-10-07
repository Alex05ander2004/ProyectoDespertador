import QtQuick 2.15
import QtQuick.Controls 2.15
import Despertador 1.0

Rectangle {
    width: 640
    height: 480
    color: "lightblue"

    // Incluir el archivo .ui.qml como un componente visual
    Screen01UI {
        id: uiComponent
        anchors.fill: parent
    }

    // Añadir lógica a los componentes interactivos
    Button {
        text: "Press Me"
        anchors.centerIn: parent
        onClicked: {
            console.log("Button Pressed!")
        }
    }

    Slider {
        anchors.top: uiComponent.button.bottom
        anchors.horizontalCenter: parent
        from: 0
        to: 100
        onValueChanged: {
            console.log("Slider value: " + value)
        }
    }

    SpinBox {
        anchors.top: uiComponent.slider.bottom
        anchors.horizontalCenter: parent
        value: 0
        minimumValue: 0
        maximumValue: 100
        onValueChanged: {
            console.log("SpinBox value: " + value)
        }
    }
}
