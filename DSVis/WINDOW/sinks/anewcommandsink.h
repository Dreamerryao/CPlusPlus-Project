#ifndef ANEWCOMMANDSINK_H
#define ANEWCOMMANDSINK_H


#include"../../common/etlbase.h"
#include "qmessagebox.h"
class operation;
class ANewCommandSink: public ICommandNotification
{
public:
    ANewCommandSink(operation* ptr);
    virtual void OnCommandComplete(const std::string& str, bool bOK);
private:
     operation * _Op;
};

#endif // ANEWCOMMANDSINK_H
