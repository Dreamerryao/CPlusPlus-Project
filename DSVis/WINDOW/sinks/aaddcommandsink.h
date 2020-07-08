#ifndef AADDCOMMANDSINK_H
#define AADDCOMMANDSINK_H
#include"../../common/etlbase.h"
#include "qmessagebox.h"
class operation;
class AAddCommandSink: public ICommandNotification
{
public:
    AAddCommandSink(operation* ptr);
    virtual void OnCommandComplete(const std::string& str, bool bOK);
private:
     operation * _Op;
};

#endif // AADDCOMMANDSINK_H
