#include "aboutcommand.h"
#include "../app.h"
AboutCommand::AboutCommand(app * ptr_App)
{
    ptrApp = ptr_App;
}
AboutCommand::~AboutCommand(){}
void AboutCommand::SetParameter(const std::any &param){}
void AboutCommand::Exec(){
    (ptrApp->getFirstPage())->close();
    (ptrApp->getAbout()) ->show();
}
