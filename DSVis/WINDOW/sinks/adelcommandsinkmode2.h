#ifndef ADELCOMMANDSINKMODE2_H
#define ADELCOMMANDSINKMODE2_H
#include"../../common/etlbase.h"
#include "qmessagebox.h"
class Model2_main;
class ADelCommandSinkMode2: public ICommandNotification
{
public:
   ADelCommandSinkMode2(Model2_main* ptr);
    virtual void OnCommandComplete(const std::string& str, bool bOK);
private:
     Model2_main * _Op;
};
#endif // ADELCOMMANDSINKMODE2_H
