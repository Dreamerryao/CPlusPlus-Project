#include "m2command.h"
#include "../app.h"
M2Command::M2Command(app * ptr_App)
{
    ptrApp = ptr_App;
}
M2Command::~M2Command(){}
void M2Command::SetParameter(const std::any &param){}
void M2Command::Exec(){
    (ptrApp->getFirstPage())->close();
    (ptrApp->getModel2_main()) ->show();
}
