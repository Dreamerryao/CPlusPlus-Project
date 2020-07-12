#include "changecommand.h"
#include "../app.h"
changeCommand::changeCommand(app * ptr_App)
{
    ptrApp = ptr_App;
}
changeCommand::~changeCommand(){}
void changeCommand::SetParameter(const std::any &param){}
void changeCommand::Exec(){
    (ptrApp->getModel1_main())->close();
    (ptrApp->getOp())->setLabel(ptrApp->getModel1_main()->TT);
    (ptrApp->getOp())->type=(ptrApp->getModel1_main())->type;
    (ptrApp->getOp())->set_treeType();
    (ptrApp->getOp())->set_arrayType();
    (ptrApp->getOp())->show_TQ();
    (ptrApp->getOp())->show_button();
    (ptrApp->getOp())->show();
}
