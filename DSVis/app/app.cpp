#include <QApplication>
#include "app.h"

app::app()
{
}

app::~app()
{
}

void app::run(){

    //_testBC = std::make_shared<testButtonCommand>(this);
    //_testWindow.setTestCommand(std::static_pointer_cast<ICommandBase>(this->_testBC));
    //_testWindow.show();
    _mainWindow.show();
}

testWindow* app::getTest(){
    return & _testWindow;
}
