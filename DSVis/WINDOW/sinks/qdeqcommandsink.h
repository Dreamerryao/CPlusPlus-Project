#ifndef QDEQCOMMANDSINK_H
#define QDEQCOMMANDSINK_H

#include"../../common/etlbase.h"
#include "qmessagebox.h"
class operation;
class QDeqCommandSink: public ICommandNotification
{
public:
    QDeqCommandSink(operation* ptr);
    virtual void OnCommandComplete(const std::string& str, bool bOK);
private:
     operation * _Op;
};

#endif //QDEQCOMMANDSINK_H
