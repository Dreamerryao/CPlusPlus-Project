#include "arrayviewmodel.h"
#include "sinks/arraymodelsink.h"

ArrayViewModel::ArrayViewModel()
{
    _AMSink = std::make_shared<ArrayModelSink>(this);
    _AAC = std::make_shared<ArrayAddCommand>(this);
    _ADC = std::make_shared<ArrayDelCommand>(this);
    _SPC = std::make_shared<StackPopCommand>(this);
    _QDC = std::make_shared<QueueDeqCommand>(this);
    _ARC = std::make_shared<ArrayReplaceCommand>(this);
    _ANC = std::make_shared<ArrayNewCommand>(this);
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

std::shared_ptr<ICommandBase> ArrayViewModel::getQueueDeqCommand(){
    return std::static_pointer_cast<ICommandBase>(_QDC);
}
int ArrayViewModel::Exec_Qdeq_command(){
    return _ArrayModel->deq();
}

std::shared_ptr<ICommandBase> ArrayViewModel::getArrayReplaceCommand(){
    return std::static_pointer_cast<ICommandBase>(_ARC);
}

int ArrayViewModel::Exec_ARep_command(int index, int newValue){
    return _ArrayModel->replace(index,newValue);
}

std::shared_ptr<ICommandBase> ArrayViewModel::getArrayNewCommand(){
    return std::static_pointer_cast<ICommandBase>(_ANC);
}

void ArrayViewModel::Exec_ANew_command(int size){
    _ArrayModel->Anew(size);
}
