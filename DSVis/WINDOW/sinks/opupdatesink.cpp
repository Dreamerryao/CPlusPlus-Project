#include "opupdatesink.h"
#include "../mode1_display.h"
OpUpdateSink::OpUpdateSink(operation *ptr)
{

    _Op = ptr;
}

 void OpUpdateSink::OnPropertyChanged(const std::string& str){
    if(str=="ArrayModel"){
    _Op->update();
    }

}
