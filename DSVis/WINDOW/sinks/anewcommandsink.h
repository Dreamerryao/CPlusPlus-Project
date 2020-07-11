#ifndef ANEWCOMMANDSINK_H
#define ANEWCOMMANDSINK_H


#include"../../common/etlbase.h"
#include "qmessagebox.h"
class Model2_main;
class ANewCommandSink: public ICommandNotification
{
public:
    ANewCommandSink(Model2_main* ptr);
    virtual void OnCommandComplete(const std::string& str, bool bOK);
private:
     Model2_main * _Op;
};

#endif // ANEWCOMMANDSINK_H
