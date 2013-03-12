#ifndef SVC_H
#define SVC_H

#include <QObject>
class NetAccessMan;

class Svc : public QObject
{
    Q_OBJECT
public:
    explicit Svc(QObject *parent = 0);

signals:
    void loading();
    void result(const QString & error, const QString & data);

public slots:
    void get(const QString & url);
    void post(const QString & url, const QString & data);

private slots:
    void serverReply();

private:
    NetAccessMan * m_netAccessMan;
};

#endif // SVC_H
