#ifndef ADELCOMMANDSINK_H
#define ADELCOMMANDSINK_H

#include"../../common/etlbase.h"
#include "qmessagebox.h"
class operation;
class ADelCommandSink: public ICommandNotification
{
public:
   ADelCommandSink(operation* ptr);
    virtual void OnCommandComplete(const std::string& str, bool bOK);
private:
     operation * _Op;
};

#endif // ADELCOMMANDSINK_H
