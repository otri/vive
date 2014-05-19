#ifndef NATURALPOINTCLIENT_H
#define NATURALPOINTCLIENT_H

#include <QObject>
#include <QList>
#include <QThread>
#include <QUdpSocket>
#include "mocapSubject.h"

#include "NatNetTypes.h"
#include "CMNatNetPacketParser.h"

class NaturalPointClient : public QThread
{
    Q_OBJECT

public:
    NaturalPointClient( MocapSubjectList *subjectList, QObject *parent = NULL);

    bool mocapConnect();
    bool mocapDisconnect();

    bool connected;
    QHostAddress connectGroupAddress;
    QUdpSocket *socket;

    MocapSubjectList *subjects;
    CMNatNetPacketParser mParser;

    virtual void run();

    bool running;
    size_t count;
    QString host;
    int     port;

private:

signals:
    void outMessage(QString);
    void connectedEvent(bool);
    void newFrame(unsigned int);
};

#endif // NATURALPOINTCLIENT_H