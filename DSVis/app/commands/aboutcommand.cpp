#include "aboutcommand.h"
#include "../app.h"
AboutCommand::AboutCommand(app * ptr_App)
{
    ptrApp = ptr_App;
}
AboutCommand::~AboutCommand(){}
void AboutCommand::SetParameter(const _new_any_space_::any &param){}
void AboutCommand::Exec(){
    (ptrApp->getFirstPage())->close();
    //(ptrApp->getTest()) ->close();
    (ptrApp->getTest()) ->show();
}
