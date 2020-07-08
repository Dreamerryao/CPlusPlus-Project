#include "arraymodelsink.h"
#include "../arrayviewmodel.h"

ArrayModelSink::ArrayModelSink(ArrayViewModel *ptr)
{
    _AVM = ptr;
}
void ArrayModelSink::OnPropertyChanged(const std::string &str){
    _AVM ->Fire_OnPropertyChanged(str);
}
