//
// Copyright 2004 Andras Varga
//
// This library is free software, you can redistribute it and/or modify
// it under  the terms of the GNU Lesser General Public License
// as published by the Free Software Foundation;
// either version 2 of the License, or any later version.
// The library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU Lesser General Public License for more details.
//

#ifndef __TCPGENERICSRVTHREAD_H_
#define __TCPGENERICSRVTHREAD_H_

#include <omnetpp.h>
#include "TCPSrvHostApp.h"


/**
 * Example server thread, to be used with TCPSrvHostApp.
 */
class TCPGenericSrvThread : public TCPServerThreadBase
{
  public:
    TCPGenericSrvThread() {}

    virtual void established();
    virtual void dataArrived(cMessage *msg, bool urgent);
    virtual void timerExpired(cMessage *timer);
};


#endif


