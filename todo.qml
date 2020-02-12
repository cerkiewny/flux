import QtQuick 2.3
import QtQuick.Controls 2.12

ApplicationWindow {
    visible: true
    width: 800 
    height: 400 
    Rectangle {
        anchors.centerIn: parent
        width: 200
        height: 100

        Text {
            anchors.centerIn: parent
            text: "Hello, World!"
        }
    }

}
