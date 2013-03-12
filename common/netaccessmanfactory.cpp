#include "netaccessmanfactory.h"
#include "netaccessman.h"

QNetworkAccessManager * NetAccessManFactory::create(QObject *parent)
{
    NetAccessMan *nam = new NetAccessMan(parent);
    return nam;
}
