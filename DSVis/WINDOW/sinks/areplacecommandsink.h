#ifndef AREPLACECOMMANDSINK_H
#define AREPLACECOMMANDSINK_H


#include"../../common/etlbase.h"
#include "qmessagebox.h"
class operation;
class AReplaceCommandSink: public ICommandNotification
{
public:
   AReplaceCommandSink(operation* ptr);
    virtual void OnCommandComplete(const std::string& str, bool bOK);
private:
     operation * _Op;
};

#endif // AREPLACECOMMANDSINK_H
