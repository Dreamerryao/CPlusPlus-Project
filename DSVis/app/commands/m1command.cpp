#include "m1command.h"
#include "../app.h"
M1Command::M1Command(app * ptr_App)
{
    ptrApp = ptr_App;
}
M1Command::~M1Command(){}
void M1Command::SetParameter(const _new_any_space_::any &param){}
void M1Command::Exec(){
    (ptrApp->getFirstPage())->close();
    (ptrApp->getModel1_main()) ->show();
}
