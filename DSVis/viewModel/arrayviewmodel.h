#ifndef ARRAYVIEWMODEL_H
#define ARRAYVIEWMODEL_H
#include "../model/arraymodel.h"
#include "../common/etlbase.h"
#include "sinks/arraymodelsink.h"
#include "commands/arrayaddcommand.h"
#include "commands/arraydelcommand.h"
#include "commands/stackpopcommand.h"
#include "commands/queuedeqcommand.h"
#include "commands/arrayreplacecommand.h"
#include "commands/arraynewcommand.h"
class ArrayViewModel:public Proxy_PropertyNotification<ArrayViewModel>,
        public Proxy_CommandNotification<ArrayViewModel>
{
public:
    ArrayViewModel();
    ~ArrayViewModel(){}
    void setArrayModel(const std::shared_ptr<ArrayModel> &AM);
    std::shared_ptr<ARRAYC> getArray();
    std::shared_ptr<ICommandBase> getArrayAddCommand();
    std::shared_ptr<ICommandBase> getArrayDelCommand();
    std::shared_ptr<ICommandBase> getStackPopCommand();
    std::shared_ptr<ICommandBase> getQueueDeqCommand();
    std::shared_ptr<ICommandBase> getArrayReplaceCommand();
    std::shared_ptr<ICommandBase> getArrayNewCommand();
    std::shared_ptr<ArrayModel> _ArrayModel;

private:
    std::shared_ptr<ArrayModelSink> _AMSink;
    std::shared_ptr<ArrayAddCommand> _AAC;
    std::shared_ptr<ArrayDelCommand> _ADC;
    std::shared_ptr<StackPopCommand> _SPC;
    std::shared_ptr<QueueDeqCommand> _QDC;
    std::shared_ptr<ArrayReplaceCommand> _ARC;
    std::shared_ptr<ArrayNewCommand> _ANC;

};

#endif // ARRAYVIEWMODEL_H
