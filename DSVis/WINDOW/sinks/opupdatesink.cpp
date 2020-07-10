#include "opupdatesink.h"
#include "../operation.h"
OpUpdateSink::OpUpdateSink(operation *ptr)
{

    _Op = ptr;
}

 void OpUpdateSink::OnPropertyChanged(const std::string& str){
    if(str=="ArrayModel"||str=="TreeModel"){
    _Op->update();
    }

}
