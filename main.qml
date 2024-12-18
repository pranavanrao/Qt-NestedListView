import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Component {
        id: comp1
        Rectangle {
            width: lv1.width
            height: 50
            color: "blue"

            Text {
                id: txt1
                text: "Name: " + model.name + ", Type: " + model.type
                leftPadding: 10
                anchors.verticalCenter: parent.verticalCenter
            }
        }
    }

    ListView {
        id: lv1
        width: parent.width*0.9
        height: parent.height
        anchors.centerIn: parent
        spacing: 10

        model: mainList
        delegate: comp1
    }
}
