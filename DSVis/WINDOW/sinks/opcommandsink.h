#ifndef OPCOMMANDSINK_H
#define OPCOMMANDSINK_H
#include"../../common/etlbase.h"
#include "qmessagebox.h"
class operation;
class OpCommandSink: public ICommandNotification
{
public:
   OpCommandSink(operation* ptr);
    virtual void OnCommandComplete(const std::string& str, bool bOK);
private:
     operation * _Op;
};
#endif // OPCOMMANDSINK_H
