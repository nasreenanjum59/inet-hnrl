//
// Copyright (C) 2013 Kyeong Soo (Joseph) Kim
// Copyright (C) 2005 Andras Varga
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program; if not, see <http://www.gnu.org/licenses/>.
//


#ifndef __INET_BASICTOKENBUCKETMETER_H
#define __INET_BASICTOKENBUCKETMETER_H

#include <omnetpp.h>
#include "INETDefs.h"
//#include "IQoSMeter.h"

/**
 * A meter based on two token buckets one for average and the other for peak rates.
  */
class INET_API BasicTokenBucketMeter : public cSimpleModule
{
  public:

  protected:
    // configuration
    long long bucketSize;   // in bit; note that the corresponding parameter in NED/INI is in byte.
    double meanRate;
    int mtu;   // in bit; note that the corresponding parameter in NED/INI is in byte.
    double peakRate;

    // state
    long long meanBucketLength;  // the number of tokens (bits) in the bucket for mean rate/burst control
    int peakBucketLength;  // the number of tokens (bits) in the bucket for peak rate/MTU control
    simtime_t lastTime; // the last time the TBF used
    bool isTxScheduled; // flag to indicate whether there is any scheduled frame transmission

    // statistics
    bool warmupFinished;        ///< if true, start statistics gathering
    int numBitsConformed;
    int numBitsReceived;
    int numPktsConformed;
    int numPktsReceived;

  protected:

    virtual void initialize();
    virtual void finish();

    /**
     * The method should return the result of metering based on two token buckets
     * for the given packet, 0 for conformance and 1 for not.
     */
    virtual int meterPacket(cMessage *msg);
};

#endif
