#include "netaccessman.h"
#include <QNetworkRequest>
#include <QNetworkReply>

#include <QDesktopServices>
#include <QNetworkDiskCache>


#define USER_AGENT "Mozilla/5.0 (Symbian/3; Series60/5.2 NokiaN8-00/013.016; Profile/MIDP-2.1 Configuration/CLDC-1.1 ) AppleWebKit/525 (KHTML, like Gecko) Version/3.0 BrowserNG/7.2.8.10 3gpp-gba"


NetAccessMan::NetAccessMan(QObject *parent) :
    QNetworkAccessManager(parent)
{
    m_networkDiskCache = new QNetworkDiskCache();
    m_networkDiskCache->setCacheDirectory(QDesktopServices::storageLocation(QDesktopServices::CacheLocation));

    setCache(m_networkDiskCache);

}

NetAccessMan::~NetAccessMan(){
    if(m_networkDiskCache)
        delete m_networkDiskCache;
}

// protected:
QNetworkReply * NetAccessMan::createRequest(Operation op, const QNetworkRequest & req, QIODevice * outgoingData)
{
    // Pass duty to the superclass - Nothing special to do here (yet?)
    QNetworkRequest r = req;
    r.setRawHeader("User-Agent", USER_AGENT);
    r.setAttribute(QNetworkRequest::CacheLoadControlAttribute, QNetworkRequest::Automatic);

    QNetworkReply *reply = QNetworkAccessManager::createRequest(op, r, outgoingData);
    reply->ignoreSslErrors();
    return reply;
}

