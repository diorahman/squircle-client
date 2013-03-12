import QtQuick 1.1
import com.nokia.meego 1.0
import com.rockybars.package 1.0

PageStackWindow {
    id: appWindow

    initialPage: mainPage

    Svc{
        id: svc
    }

    MainPage {
        id: mainPage
    }

    ToolBarLayout {
        id: commonTools
        visible: true
        ToolIcon {
            platformIconId: "toolbar-view-menu"
            anchors.right: (parent === undefined) ? undefined : parent.right
            onClicked: (myMenu.status === DialogStatus.Closed) ? myMenu.open() : myMenu.close()
        }
    }

    Menu {
        id: myMenu
        visualParent: pageStack
        MenuLayout {
            MenuItem { text: qsTr("I love N9") }
        }
    }
}
