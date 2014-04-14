


#ifndef TESTCLIENT_H
#define TESTCLIENT_H

#include <QObject>
#include <QList>
#include <QThread>
#include "mocapSubject.h"

class TestClient : public QThread
{
	Q_OBJECT

public:
	TestClient( MocapSubjectList *subjectList, QObject *parent = NULL);

	friend QTextStream& operator << (QTextStream &, TestClient &);

	MocapSubjectList *subjects;

	virtual void run();

	bool running;

	size_t count;

    float val, mousex, mousey;

signals:
    void outMessage(QString);
    void newFrame(int);
};



#endif
