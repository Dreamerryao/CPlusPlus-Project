#include <QApplication>
#include "app.h"

app::app()
{
}

app::~app()
{
}

void app::run(){

    _testBC = std::make_shared<testButtonCommand>(this);
    _M1Command = std::make_shared<M1Command>(this);
    _M2Command = std::make_shared<M2Command>(this);
    _AboutCommand = std::make_shared<AboutCommand>(this);
    _getLine=std::make_shared<getlineCommand>(this);


    _testWindow.setTestCommand(std::static_pointer_cast<ICommandBase>(this->_testBC));
    _firstPage.set_ptrM1Command(std::static_pointer_cast<ICommandBase>(this->_M1Command));
    _firstPage.set_ptrM2Command(std::static_pointer_cast<ICommandBase>(this->_M2Command));
    _firstPage.set_ptrAboutCommand(std::static_pointer_cast<ICommandBase>(this->_AboutCommand));
    _Model2_main.setGetCommand(std::static_pointer_cast<ICommandBase>(this->_getLine));

    _firstPage.show();
}

testWindow* app::getTest(){
    return & _testWindow;
}

FirstPage* app::getFirstPage(){
    return & _firstPage;
}

Model2_main * app::getModel2_main(){
    return & _Model2_main;
}
