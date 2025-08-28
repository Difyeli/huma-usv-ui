// MapView.qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtLocation 5.15
import QtPositioning 5.15



Item {
    id: root; width: parent.width; height: parent.height

    // C++ tarafı burayı güncelleyecek
    property real vehicleLat: 0
    property real vehicleLon: 0
    property real vehicleHeading: 0

    // Waypoint listesi
    ListModel {
            id: waypointModel
            objectName: "waypointModel"
        }

    function appendWaypoint(lat, lon) {
        waypointModel.append({ lat: lat, lon: lon })
    }


    Plugin { id: osmPlugin; name: "osm" }


    function removeWaypointAt(index) {
           // QML'in kendi remove metodu
           waypointModel.remove(index)
       }


    Map {
        id: map; anchors.fill: parent
        plugin: osmPlugin
        center: QtPositioning.coordinate(vehicleLat, vehicleLon)
        zoomLevel: 14

        // Araç işaretçisi
        MapQuickItem {
            coordinate: QtPositioning.coordinate(vehicleLat, vehicleLon)
            anchorPoint.x: arrow.width/2
            anchorPoint.y: arrow.height/2
            sourceItem: Image {
                id: arrow
                source: "qrc:/icons/usv.png"
                width: 16; height: 16
                rotation: vehicleHeading
            }
        }

        // Sağ-tıkla waypoint ekle
        MouseArea {
            anchors.fill: parent
            acceptedButtons: Qt.RightButton
            onPressed: {
                if (mouse.button === Qt.RightButton) {
                    var c = map.toCoordinate(Qt.point(mouse.x, mouse.y))
                    // Sadece backend üzerinden ekle (tablo + harita tek yerden güncellensin)
                    backend.addWaypoint(c.latitude, c.longitude)
                }
            }
        }

        MouseArea {
            id: mapDragArea
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton | Qt.RightButton
            property var pressedPos
            property var pressedCoord

            onPressed: {
                if (mouse.button === Qt.LeftButton) {
                    pressedPos = Qt.point(mouse.x, mouse.y)
                    pressedCoord = map.toCoordinate(pressedPos)
                } else if (mouse.button === Qt.RightButton) {
                    var c = map.toCoordinate(Qt.point(mouse.x, mouse.y))
                    backend.addWaypoint(c.latitude, c.longitude)
                }
            }

            onPositionChanged: {
                if (mouse.buttons & Qt.LeftButton && pressedCoord) {
                    var currentCoord = map.toCoordinate(Qt.point(mouse.x, mouse.y))

                    var dx = pressedCoord.longitude - currentCoord.longitude
                    var dy = pressedCoord.latitude - currentCoord.latitude

                    // Yön değiştir ve kaydır
                    map.center.latitude += dy
                    map.center.longitude += dx
                }
            }

            onReleased: {
                pressedPos = null
                pressedCoord = null
            }
        }




        // Modelden waypoint’leri haritaya bas
        MapItemView {
            model: waypointModel
            delegate: MapQuickItem {
                coordinate: QtPositioning.coordinate(lat, lon)
                anchorPoint.x: pin.width/2
                anchorPoint.y: pin.height
                sourceItem: Image {
                    id: pin
                    source: "qrc:/icons/waypoint.png"
                    width: 24; height: 24
                }
            }
        }


    }

    // + / – zoom kontrolleri
    Row {
        spacing: 4
        anchors.top: parent.top; anchors.right: parent.right; anchors.margins: 8
        Button { text: "+"; onClicked: map.zoomLevel = Math.min(map.zoomLevel + 1, 24) }
        Button { text: "–"; onClicked: map.zoomLevel = Math.max(map.zoomLevel - 1, 1) }
    }
}
