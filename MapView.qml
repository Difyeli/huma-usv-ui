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
    ListModel { id: waypointModel }

    Plugin { id: osmPlugin; name: "osm" }

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
                width: 32; height: 32
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
                    waypointModel.append({ lat: c.latitude, lon: c.longitude })
                    backend.addWaypoint(c.latitude, c.longitude)
                }
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
        Button { text: "+"; onClicked: map.zoomLevel = Math.min(map.zoomLevel + 1, 20) }
        Button { text: "–"; onClicked: map.zoomLevel = Math.max(map.zoomLevel - 1, 1) }
    }
}
