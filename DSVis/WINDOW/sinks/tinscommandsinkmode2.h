#ifndef TINSCOMMANDSINKMODE2_H
#define TINSCOMMANDSINKMODE2_H
#include"../../common/etlbase.h"
#include "qmessagebox.h"
class Model2_main;
class TInsCommandSinkMode2: public ICommandNotification
{
public:
    TInsCommandSinkMode2(Model2_main* ptr);
    virtual void OnCommandComplete(const std::string& str, bool bOK);
private:
     Model2_main * _Op;
};
#endif // TINSCOMMANDSINKMODE2_H
