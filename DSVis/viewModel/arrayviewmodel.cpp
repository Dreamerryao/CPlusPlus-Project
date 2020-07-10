#include "arrayviewmodel.h"
#include "sinks/arraymodelsink.h"

ArrayViewModel::ArrayViewModel()
{
    _AMSink = std::make_shared<ArrayModelSink>(this);
    _AAC = std::make_shared<ArrayAddCommand>(this);
    _ADC = std::make_shared<ArrayDelCommand>(this);
    _SPC = std::make_shared<StackPopCommand>(this);
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

std::shared_ptr<ICommandBase> ArrayViewModel::getArrayDelCommand(){
    return std::static_pointer_cast<ICommandBase>(_ADC);
}
int ArrayViewModel::Exec_Adel_command(int I){
    return _ArrayModel->del(I);
}

std::shared_ptr<ICommandBase> ArrayViewModel::getStackPopCommand(){
    return std::static_pointer_cast<ICommandBase>(_SPC);
}
int ArrayViewModel::Exec_Spop_command(){
    return _ArrayModel->pop();
}
