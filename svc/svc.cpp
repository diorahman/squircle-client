#include "svc.h"

#include <QNetworkAccessManager>
#include "netaccessman.h"
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QDebug>

#include <QDateTime>

Svc::Svc(QObject *parent) :
    QObject(parent)
{
        m_netAccessMan = new NetAccessMan(this);
}

void Svc::get(const QString & url){
    QNetworkRequest req;
    req.setUrl(QUrl(url));

    QNetworkReply * r = m_netAccessMan->get(req);
    connect(r, SIGNAL(finished()), SLOT(serverReply()));
}

void Svc::post(const QString &url, const QString & data)
{
    QNetworkRequest req;
    req.setUrl(QUrl(url));

    emit loading();

    QNetworkReply * r = m_netAccessMan->post(req, data.toAscii());
    connect(r, SIGNAL(finished()), SLOT(serverReply()));
}

void Svc::serverReply()
{
    QNetworkReply * reply = qobject_cast<QNetworkReply *>(sender());

    QString error;

    if(reply->error() != QNetworkReply::NoError){
            error = reply->errorString();
    }

    emit result(error, reply->readAll());

    reply->deleteLater();
}


