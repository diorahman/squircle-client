#include <QtGui/QApplication>
#include <qdeclarative.h>
#include "qmlapplicationviewer.h"
#include <QDeclarativeEngine>
#include "netaccessmanfactory.h"

#include "svc.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    qmlRegisterType<Svc>("com.rockybars.package", 1, 0, "Svc");

    QmlApplicationViewer viewer;
    viewer.engine()->setNetworkAccessManagerFactory(new NetAccessManFactory);
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/squircle/main.qml"));
    viewer.showExpanded();

    return app->exec();
}
