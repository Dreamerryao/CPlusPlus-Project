#include "arrayviewmodel.h"

ArrayViewModel::ArrayViewModel()
{
}

void ArrayViewModel::setArrayModel(const std::shared_ptr<ArrayModel> &AM){
    _ArrayModel = AM;
}

std::shared_ptr<ARRAYC> ArrayViewModel::getArray(){
    return _ArrayModel->getArrayc();
}

