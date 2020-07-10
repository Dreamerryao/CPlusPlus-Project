#ifndef TDELCOMMANDSINK_H
#define TDELCOMMANDSINK_H

#include"../../common/etlbase.h"
#include "qmessagebox.h"
class operation;
class TDelCommandSink: public ICommandNotification
{
public:
    TDelCommandSink(operation* ptr);
    virtual void OnCommandComplete(const std::string& str, bool bOK);
private:
     operation * _Op;
};
#endif // TDELCOMMANDSINK_H
