#include "arraymodel.h"

ArrayModel::ArrayModel()
{
    _Array = std::make_shared<ARRAYC>();
}

std::shared_ptr<ARRAYC> ArrayModel::getArrayc(){
    return _Array;
}

void ArrayModel::add(int a){
    _Array->Add(a);
    Fire_OnPropertyChanged("ArrayModel");
}

int ArrayModel::del(int a){
    int res = 0;
    if(!(_Array->isArrayNull()))
    res = _Array->Del(a);
    Fire_OnPropertyChanged("ArrayModel");
    return res;
}
