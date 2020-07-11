#include "arraymodel.h"
#include "Windows.h"
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

int ArrayModel::pop(){
    int res = 0;
    if(!(_Array->isArrayNull()))
    res = _Array->Pop();
    Fire_OnPropertyChanged("ArrayModel");
    return res;
}

int ArrayModel::deq(){
    int res = 0;
    if(!(_Array->isArrayNull()))
    res = _Array->Deq();
    Fire_OnPropertyChanged("ArrayModel");
    return res;
}

int ArrayModel::replace(int index,int newValue){
    int res = _Array->Replace(index,newValue);
    Fire_OnPropertyChanged("ArrayModel");
    return res;
}

void ArrayModel::Anew(int size){
    if(size>0){
        _Array->New(size);
    }
    Fire_OnPropertyChanged("ArrayModel");
}
