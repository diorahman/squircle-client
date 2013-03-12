import QtQuick 1.1
import com.nokia.meego 1.0
import QtMobility.systeminfo 1.2
import QtMobility.location 1.2
import QtWebKit 1.0

import "Constants.js" as Constants

Page {
    tools: commonTools

    Component.onCompleted: {
        // register 'this' device
        svc.post(Constants.ENDPOINT, buildUserAgent() + "&timestamp=" + new Date())
    }

    function handleArray(data){
        console.log(JSON.stringify(data))
        countLabel.text = data.length
    }

    function handleObject(data){
        console.log(JSON.stringify(data))
    }

    function buildUserAgent() {
        var result = ""
        result += "udid="
        result += Qt.btoa(deviceInfo.uniqueDeviceID)
        result += "&manufacturer="
        result += deviceInfo.manufacturer
        result += "&model="
        result += deviceInfo.model
        result += "&firmware="
        result += generalInfo.firmwareVersion
        result += "&os="
        result += generalInfo.osVersion
        result += "&language="
        result += generalInfo.currentLanguage
        return result
    }

    WebView {
         url: Constants.VIEW
         preferredWidth: parent.width
         preferredHeight: parent.height
         smooth: false
         anchors.centerIn: parent
         onLoadFinished: {
             countLabel.text = 'counting...'
             svc.get(Constants.ENDPOINT)
         }
    }

    Rectangle{
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        height: 80
        opacity: 0.5

        Label{
            id: countLabel
            anchors.centerIn: parent
            text: "squircling..."
        }
    }

    DeviceInfo {
        id: deviceInfo
    }

    GeneralInfo {
        id: generalInfo
    }

    Connections{
        target: svc
        onResult: {
            if(error.length == 0){
                var obj = JSON.parse(data)
                if(Array.isArray(obj)){
                    handleArray(obj)
                }
                else{
                    handleObject(obj)
                }
            }
        }
    }

    /*

    // simple usage of the service, well this is sooo simple

    Label {
        id: label
        anchors.centerIn: parent
        text: ""
    }

    // retrieve a data
    Button{
        id: getButton
        anchors {
            horizontalCenter: parent.horizontalCenter
            top: label.bottom
            topMargin: 10
        }
        text: qsTr("GET")
        onClicked: {
            svc.get(Constants.ENDPOINT)
        }
    }

    // add a data
    Button{
        id: postButton
        anchors {
            horizontalCenter: parent.horizontalCenter
            top: getButton.bottom
            topMargin: 10
        }
        text: qsTr("POST")
        onClicked: {
            svc.post(Constants.ENDPOINT, buildUserAgent() + "&timestamp=" + new Date())
        }
    }*/
}
