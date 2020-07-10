#include "testbuttoncommand.h"
#include "../app.h"
testButtonCommand::testButtonCommand(app* ptr_App)
{
    ptrApp = ptr_App;
}

void testButtonCommand::Exec(){
    (ptrApp->getTest())->setLabel("www");
}
