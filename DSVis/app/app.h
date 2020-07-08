#ifndef APP_H
#define APP_H

#include "../WINDOW/testwindow.h"
#include "../WINDOW/firstpage.h"
#include "../WINDOW/model2_main.h"

#include "commands/testbuttoncommand.h"
#include "commands/m1command.h"
#include "commands/m2command.h"
#include "commands/aboutcommand.h"
#include "commands/getline.h"
class app
{
private:
    testWindow _testWindow;
    Model2_main _Model2_main;
    FirstPage _firstPage;

    std::shared_ptr<testButtonCommand> _testBC;
    std::shared_ptr<M1Command> _M1Command;
    std::shared_ptr<M2Command> _M2Command;
    std::shared_ptr<AboutCommand> _AboutCommand;
    std::shared_ptr<getlineCommand> _getLine;
public:
    app();
    ~app();
    void run();
    testWindow* getTest();
    FirstPage* getFirstPage();
    Model2_main* getModel2_main();
};
#endif // APP_H
