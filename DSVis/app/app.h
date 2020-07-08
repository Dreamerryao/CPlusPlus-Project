#ifndef APP_H
#define APP_H

#include "../WINDOW/testwindow.h"
#include "../WINDOW/mainwindow.h"
#include "commands/testbuttoncommand.h"
class app
{
private:
    testWindow _testWindow;
    MainWindow _mainWindow;
    std::shared_ptr<testButtonCommand> _testBC;
public:
    app();
    ~app();
    void run();
    testWindow* getTest();

};
#endif // APP_H
