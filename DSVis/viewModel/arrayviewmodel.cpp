#include "arrayviewmodel.h"
#include "sinks/arraymodelsink.h"

ArrayViewModel::ArrayViewModel()
{
    _AMSink = std::make_shared<ArrayModelSink>(this);
    _AAC = std::make_shared<ArrayAddCommand>(this);
    _ADC = std::make_shared<ArrayDelCommand>(this);
}

void ArrayViewModel::setArrayModel(std::shared_ptr<ArrayModel> AM){
    _ArrayModel = AM;
    _ArrayModel->AddPropertyNotification(_AMSink);
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

