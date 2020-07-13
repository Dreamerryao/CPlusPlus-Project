#ifndef MODE1_DISPLAYCOMMANDSINK_H
#define MODE1_DISPLAYCOMMANDSINK_H
#include"../../common/etlbase.h"
#include "qmessagebox.h"
class Mode1_display;
class Mode1_displayCommandSink: public ICommandNotification
{
public:
    Mode1_displayCommandSink(Mode1_display* ptr);
    virtual void OnCommandComplete(const std::string& str, bool bOK);
private:
     Mode1_display * _Op;
};

#endif // MODE1_DISPLAYCOMMANDSINK_H
