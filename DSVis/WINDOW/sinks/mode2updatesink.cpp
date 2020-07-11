#include "mode2updatesink.h"
#include "../model2_main.h"
Mode2UpdateSink::Mode2UpdateSink(Model2_main *ptr)
{

    _Op = ptr;
}

 void Mode2UpdateSink::OnPropertyChanged(const std::string& str){
    if(str=="ArrayModel"||str=="TreeModel"){
    _Op->update();
    }

}
