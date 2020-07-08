#include "arrayviewmodel.h"
#include "sinks/arraymodelsink.h"

ArrayViewModel::ArrayViewModel()
{
    _AMSink = std::make_shared<ArrayModelSink>(this);
}

void ArrayViewModel::setArrayModel(std::shared_ptr<ArrayModel> AM){
    _ArrayModel = AM;
    _ArrayModel->AddPropertyNotification(std::static_pointer_cast<IPropertyNotification>(_AMSink));
}

std::shared_ptr<ARRAYC> ArrayViewModel::getArray(){
    return _ArrayModel->getArrayc();
}

std::shared_ptr<ICommandBase> ArrayViewModel::getArrayAddCommand(){
    return std::static_pointer_cast<ICommandBase>(_AAC);
}
void ArrayViewModel::Exec_Aadd_command(int I){
    _ArrayModel->add(I);
}
