#include "getline.h"
#include "../app.h"
getlineCommand::getlineCommand(app *ptr_App)
{
    ptrApp = ptr_App;
}

void getlineCommand::Exec(){
    (ptrApp->getModel2_main())->getLine();
}
