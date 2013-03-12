#ifndef NETACCESSMAN_H
#define NETACCESSMAN_H

#include <QNetworkAccessManager>

class QNetworkDiskCache;

class NetAccessMan : public QNetworkAccessManager
{
    Q_OBJECT
public:
    explicit NetAccessMan(QObject *parent = 0);
    ~NetAccessMan();

    QNetworkReply * createRequest(Operation op, const QNetworkRequest & req, QIODevice * outgoingData);

signals:

public slots:

private:
        QNetworkDiskCache* m_networkDiskCache;

};

#endif // NETACCESSMAN_H
