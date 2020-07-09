#ifndef SPOPCOMMANDSINK_H
#define SPOPCOMMANDSINK_H

#include"../../common/etlbase.h"
#include "qmessagebox.h"
class operation;
class SPopCommandSink: public ICommandNotification
{
public:
    SPopCommandSink(operation* ptr);
    virtual void OnCommandComplete(const std::string& str, bool bOK);
private:
     operation * _Op;
};

#endif // SPOPCOMMANDSINK_H
