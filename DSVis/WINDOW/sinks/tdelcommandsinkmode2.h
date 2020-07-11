#ifndef TDELCOMMANDSINKMODE2_H
#define TDELCOMMANDSINKMODE2_H
#include"../../common/etlbase.h"
#include "qmessagebox.h"
class Model2_main;
class TDelCommandSinkMode2: public ICommandNotification
{
public:
    TDelCommandSinkMode2(Model2_main* ptr);
    virtual void OnCommandComplete(const std::string& str, bool bOK);
private:
     Model2_main * _Op;
};
#endif // TDELCOMMANDSINKMODE2_H
