#ifndef TINSCOMMANDSINK_H
#define TINSCOMMANDSINK_H

#include"../../common/etlbase.h"
#include "qmessagebox.h"
class operation;
class TInsCommandSink: public ICommandNotification
{
public:
    TInsCommandSink(operation* ptr);
    virtual void OnCommandComplete(const std::string& str, bool bOK);
private:
     operation * _Op;
};

#endif // TINSCOMMANDSINK_H
