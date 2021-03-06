/*
VIVE - Very Immersive Virtual Experience
Copyright (C) 2014 Alastair Macleod, Emily Carr University

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef VICONCLIENT_H
#define VICONCLIENT_H

#include <QObject>
#include <QList>
#include "baseClient.h"
#include "ViconStreamClient.h"
#include <QLineEdit>

class ViconClient : public BaseClient
{
	Q_OBJECT

public:
    ViconClient( MocapSubjectList *subjectList,
                 QPushButton *button,
                 QLineEdit *statusLine,
                 QLineEdit *hostField,
                 QLineEdit *portField,
                 QObject *parent = NULL);

    ViconDataStreamSDK::CPP::Client mClient;

    //! @returns "Vicon"
    virtual QString ClientStr() { return QString("Vicon"); }

    //! Implements QThread (parent of baseclient)
    virtual void run();

    //! True if thread loop is currently running
    /*! Set to false just before thread loop completes */
    bool running;

    //! Connect to vicon
    /*! @returns true if connection was successful */
    bool mocapConnect();

    //! Disconnect from vicon
    /*! @returns false if not connected, or disconnection fails */
    bool mocapDisconnect();

    //! see BaseClient::mocapStart()
    virtual void mocapStart();

    //! see BaseClient::mocapStop()
    virtual void mocapStop();

    //! see BaseClient::ClientId()
    /*! @returns "Vicon" */
    virtual QString ClientId() { return "Vicon"; }

    //! see baseClient::UIConnectingState()
    virtual void UIConnectingState();

    //! @returns true if the service is running
    virtual bool isRunning() { return running; }

    QString host;
    int     port;

    enum eStreamMode
    {
        SERVER_PUSH,
        CLIENT_PULL,
        CLIENT_PULL_PRE_FETCH
    };

    QLineEdit *hostField;
    QLineEdit *portField;

private:
    bool          frameError;
    eStreamMode   streamMode;



};



#endif
