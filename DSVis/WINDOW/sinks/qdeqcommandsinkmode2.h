#ifndef QDEQCOMMANDSINKMODE2_H
#define QDEQCOMMANDSINKMODE2_H
#include"../../common/etlbase.h"
#include "qmessagebox.h"
class Model2_main;
class QDeqCommandSinkMode2: public ICommandNotification
{
public:
    QDeqCommandSinkMode2(Model2_main* ptr);
    virtual void OnCommandComplete(const std::string& str, bool bOK);
private:
     Model2_main * _Op;
};
#endif // QDEQCOMMANDSINKMODE2_H
