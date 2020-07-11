#include "opupdatesink.h"
#include "../mode1_display.h"
OpUpdateSink::OpUpdateSink(Mode1_display *ptr)
{

    _Op = ptr;
}

 void OpUpdateSink::OnPropertyChanged(const std::string& str){
    if(str=="ArrayModel"||str=="TreeModel"){
    _Op->update();
    }

}
