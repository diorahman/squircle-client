#ifndef NETACCESSMANFACTORY_H
#define NETACCESSMANFACTORY_H

#include <QObject>
#include <QDeclarativeNetworkAccessManagerFactory>

class NetAccessManFactory : public QDeclarativeNetworkAccessManagerFactory
{
public:
    virtual QNetworkAccessManager *create(QObject *parent);
};

#endif // NETACCESSMANFACTORY_H
