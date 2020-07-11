#ifndef AREPLACECOMMANDSINK_H
#define AREPLACECOMMANDSINK_H


#include"../../common/etlbase.h"
#include "qmessagebox.h"
class Model2_main;
class AReplaceCommandSink: public ICommandNotification
{
public:
   AReplaceCommandSink(Model2_main* ptr);
    virtual void OnCommandComplete(const std::string& str, bool bOK);
private:
     Model2_main * _Op;
};

#endif // AREPLACECOMMANDSINK_H
