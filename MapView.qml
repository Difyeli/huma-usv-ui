import QtQuick 2.15
import QtQuick.Controls 2.15
import QtLocation 5.15
import QtPositioning 5.15

Item {
    id: root; width: 800; height: 600

    property real vehicleLat: 0
    property real vehicleLon: 0
    property real vehicleHeading: 0

    ListModel { id: waypointModel }

    Plugin {
        id: osmPlugin; name: "osm"
    }

    Map {
        id: map; anchors.fill: parent
        plugin: osmPlugin
        center: QtPositioning.coordinate(vehicleLat, vehicleLon)
        zoomLevel: 14

        // Araç işaretçisi
        MapQuickItem {
            id: vehicleMarker
            coordinate: QtPositioning.coordinate(vehicleLat, vehicleLon)
            anchorPoint.x: icon.width/2
            anchorPoint.y: icon.height/2
            sourceItem: Image {
                id: icon; source: "qrc:/icons/usv.png"
                width:32; height:32
                rotation: vehicleHeading
            }
        }

        // Sağ tıkla waypoint ekleme
        MouseArea {
            anchors.fill: parent
            acceptedButtons: Qt.RightButton
            onClicked: {
                var coord = map.toCoordinate(Qt.point(mouse.x, mouse.y))
                // Kullanıcıya sor:
                var accept = Qt.createQmlObject('import QtQuick.Dialogs 1.2; MessageDialog { text: "Buraya waypoint ekleyelim mi?"; standardButtons: StandardButton.Yes|StandardButton.No }', root)
                accept.open()
                accept.onAccepted = function() {
                    waypointModel.append({ lat: coord.latitude, lon: coord.longitude })
                    backend.addWaypoint(coord.latitude, coord.longitude)
                }
            }
        }

        // Waypoint’leri göster
        MapItemView {
            model: waypointModel
            delegate: MapQuickItem {
                coordinate: QtPositioning.coordinate(lat, lon)
                anchorPoint.x: mark.width/2
                anchorPoint.y: mark.height
                sourceItem: Image {
                    id: mark; source: "qrc:/icons/waypoint.png"
                    width:24; height:24
                }
            }
        }
    }

    // Zoom kontrol düğmeleri
    Row {
        spacing: 4
        anchors.top: parent.top; anchors.right: parent.right; anchors.margins: 8
        Button { text: "+"; onClicked: map.zoomLevel = Math.min(map.zoomLevel+1, 20) }
        Button { text: "–"; onClicked: map.zoomLevel = Math.max(map.zoomLevel-1, 1) }
    }
}
