#ifndef SPOPCOMMANDSINKMODE2_H
#define SPOPCOMMANDSINKMODE2_H
#include"../../common/etlbase.h"
#include "qmessagebox.h"
class Model2_main;
class SPopCommandSinkMode2: public ICommandNotification
{
public:
    SPopCommandSinkMode2(Model2_main* ptr);
    virtual void OnCommandComplete(const std::string& str, bool bOK);
private:
     Model2_main * _Op;
};
#endif // SPOPCOMMANDSINKMODE2_H
