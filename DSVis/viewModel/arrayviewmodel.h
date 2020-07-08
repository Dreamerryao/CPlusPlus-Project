#ifndef ARRAYVIEWMODEL_H
#define ARRAYVIEWMODEL_H
#include "../model/arraymodel.h"
#include "../common/etlbase.h"
#include "sinks/arraymodelsink.h"
#include "commands/arrayaddcommand.h"

class ArrayViewModel:public Proxy_PropertyNotification<ArrayViewModel>,
        public Proxy_CommandNotification<ArrayViewModel>
{
public:
    ArrayViewModel();
    ~ArrayViewModel(){}
    void setArrayModel(std::shared_ptr<ArrayModel> AM);
    std::shared_ptr<ARRAYC> getArray();
    std::shared_ptr<ICommandBase> getArrayAddCommand();
    void Exec_Aadd_command(int I);
private:
    std::shared_ptr<ArrayModel> _ArrayModel;
    std::shared_ptr<ArrayModelSink> _AMSink;
    std::shared_ptr<ArrayAddCommand> _AAC;
};

#endif // ARRAYVIEWMODEL_H