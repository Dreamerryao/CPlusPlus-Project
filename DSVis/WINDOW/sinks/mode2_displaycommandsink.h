#ifndef MODE2_DISPLAYCOMMANDSINK_H
#define MODE2_DISPLAYCOMMANDSINK_H

#include"../../common/etlbase.h"
#include "qmessagebox.h"
class Model2_main;
class Mode2_displayCommandSink: public ICommandNotification
{
public:
   Mode2_displayCommandSink(Model2_main* ptr);
    virtual void OnCommandComplete(const std::string& str, bool bOK);
private:
     Model2_main * _Op;
};



#endif // MODE2_DISPLAYCOMMANDSINK_H
