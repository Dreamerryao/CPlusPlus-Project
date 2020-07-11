#include "cancelcommand.h"
#include "../app.h"
cancelCommand::cancelCommand(app * ptr_App)
{
    ptrApp = ptr_App;
}
cancelCommand::~cancelCommand(){}
void cancelCommand::SetParameter(const _new_any_space_::any &param){}
void cancelCommand::Exec(){
    (ptrApp->getModel2_main())->close();
    (ptrApp->getModel1_main())->close();
    (ptrApp->getAbout()) ->close();
    (ptrApp->getOp()) ->close();
    (ptrApp->getFirstPage())->show();
}
