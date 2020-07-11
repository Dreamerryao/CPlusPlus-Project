#ifndef AADDCOMMANDSINKMODE2_H
#define AADDCOMMANDSINKMODE2_H

#include"../../common/etlbase.h"
#include "qmessagebox.h"
class Model2_main;
class AAddCommandSinkMode2: public ICommandNotification
{
public:
    AAddCommandSinkMode2(Model2_main* ptr);
    virtual void OnCommandComplete(const std::string& str, bool bOK);
private:
     Model2_main * _Op;
};


#endif // AADDCOMMANDSINKMODE2_H
