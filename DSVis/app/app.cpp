#include <QApplication>
#include "app.h"

app::app()
{
}

app::~app()
{
}

void app::run(){

    //绑定model和viewmodel
    model = std::make_shared<ArrayModel>();
    viewmodel = std::make_shared<ArrayViewModel>();
    viewmodel->setArrayModel(model);

    //绑定operationPage的命令以及结构
    _operationP.set_ptrAAC(viewmodel->getArrayAddCommand());
    _operationP.set_ptrADC(viewmodel->getArrayDelCommand());
    _operationP.set_Array(viewmodel->getArray());

    //绑定viewmodel的notification
//    viewmodel->AddCommandNotification(_operationP.getAACS());
//    viewmodel->AddCommandNotification(_operationP.getADCS());
    viewmodel->AddCommandNotification(_operationP.getOCS());
    viewmodel->AddPropertyNotification(_operationP.getOUS());


    //通过make_shared指针构造Command
    _M1Command = std::make_shared<M1Command>(this);
    _M2Command = std::make_shared<M2Command>(this);
    _AboutCommand = std::make_shared<AboutCommand>(this);
    _cancelCommand=std::make_shared<cancelCommand>(this);
    _changeCommand=std::make_shared<changeCommand>(this);


    //set command
    //_testWindow.setTestCommand(std::static_pointer_cast<ICommandBase>(this->_testBC));
    _firstPage.set_ptrM1Command(this->_M1Command);
    _firstPage.set_ptrM2Command(this->_M2Command);
    _firstPage.set_ptrAboutCommand(this->_AboutCommand);
    _Model1_main.setChangeCommand(this->_changeCommand);
    _aboutPage.set_ptrCancel(this->_cancelCommand);
    _Model1_main.setCancelCommand(this->_cancelCommand);
    _Model2_main.setCancelCommand(this->_cancelCommand);
    _operationP.setCancelCommand(this->_cancelCommand);

    _firstPage.show();
}


FirstPage* app::getFirstPage(){
    return & _firstPage;
}

Model2_main * app::getModel2_main(){
    return & _Model2_main;
}

model1_main * app::getModel1_main(){
    return & _Model1_main;
}

about* app::getAbout(){
    return & _aboutPage;
}

operation* app::getOp(){
    return & _operationP;
}
