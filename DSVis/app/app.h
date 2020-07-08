#ifndef APP_H
#define APP_H

#include "../WINDOW/testwindow.h"
#include "commands/testbuttoncommand.h"
class app
{
private:
    testWindow _testWindow;
    std::shared_ptr<testButtonCommand> _testBC;
public:
    app();
    ~app();
    void run();
    testWindow* getTest();

};
#endif // APP_H
