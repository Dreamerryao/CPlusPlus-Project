#include "changecommand.h"
#include "../app.h"
changeCommand::changeCommand(app * ptr_App)
{
    ptrApp = ptr_App;
}
changeCommand::~changeCommand(){}
void changeCommand::SetParameter(const _new_any_space_::any &param){}
void changeCommand::Exec(){
    (ptrApp->getModel1_main())->close();
    (ptrApp->getOp())->setLabel(ptrApp->getModel1_main()->TT);
    (ptrApp->getOp())->type=(ptrApp->getModel1_main())->type;
    (ptrApp->getOp())->show();
}
