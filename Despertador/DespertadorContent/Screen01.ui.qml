

import QtQuick
import QtQuick.Controls
import Despertador

Rectangle {
    width: Constants.width
    height: Constants.height

    color: Constants.backgroundColor

    Text {
        text: qsTr("Hello Despertador")
        anchors.centerIn: parent
        font.family: Constants.font.family
    }

    Button {
        id: button
        x: 912
        y: 592
        text: reloj.alarmaActivada ? "Desactivar Alarma" : "Activar Alarma"
        onClicked: {
            reloj.cambiarEstadoAlarma();  // Llama al método C++ para cambiar el estado de la alarma
        }
    }

    Slider {
        id: slider
        x: 860
        y: 638
        value: 0.5
        onValueChanged: {
            // Imagina que tienes una función en C++ para ajustar el volumen
            reloj.cambiarVolumen(value);  // Método que debes implementar en C++
        }
    }

    SpinBox {
        id: spinBox
        x: 890
        y: 703
        from: 0
        to: 23
        onValueChanged: {
            reloj.configurarAlarma(value, 0);  // Configura la hora de la alarma desde el spinbox
        }
    }

    Timer {
        interval: 1000 // 1 segundo
        running: true
        repeat: true
        onTriggered: {
            reloj.obtenerHoraActual();
        }
    }
}
