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

void ArrayViewModel::setArrayModel(const std::shared_ptr<ArrayModel> &AM){
    _ArrayModel = AM;
    _ArrayModel->AddPropertyNotification(std::static_pointer_cast<IPropertyNotification>(_AMSink));
}

std::shared_ptr<ARRAYC> ArrayViewModel::getArray(){
    return _ArrayModel->getArrayc();
}

std::shared_ptr<ICommandBase> ArrayViewModel::getArrayAddCommand(){
    return std::static_pointer_cast<ICommandBase>(_AAC);
}

std::shared_ptr<ICommandBase> ArrayViewModel::getArrayDelCommand(){
    return std::static_pointer_cast<ICommandBase>(_ADC);
}


std::shared_ptr<ICommandBase> ArrayViewModel::getStackPopCommand(){
    return std::static_pointer_cast<ICommandBase>(_SPC);
}

std::shared_ptr<ICommandBase> ArrayViewModel::getQueueDeqCommand(){
    return std::static_pointer_cast<ICommandBase>(_QDC);
}

std::shared_ptr<ICommandBase> ArrayViewModel::getArrayReplaceCommand(){
    return std::static_pointer_cast<ICommandBase>(_ARC);
}

std::shared_ptr<ICommandBase> ArrayViewModel::getArrayNewCommand(){
    return std::static_pointer_cast<ICommandBase>(_ANC);
}

