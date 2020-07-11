#include <QApplication>
#include "app.h"

app::app()
{
}

app::~app()
{
}

void app::run(){

    model = std::make_shared<ArrayModel>();
    Tmodel = std::make_shared<TreeModel>();


    viewmodel = std::make_shared<ArrayViewModel>();
    viewmodel->setArrayModel(model);
    Tviewmodel = std::make_shared<TreeViewModel>();
    Tviewmodel->setTreeModel(Tmodel);

    _operationP.set_ptrAAC(viewmodel->getArrayAddCommand());
    _operationP.set_ptrADC(viewmodel->getArrayDelCommand());
    _operationP.set_ptrSPC(viewmodel->getStackPopCommand());
    _operationP.set_ptrQDC(viewmodel->getQueueDeqCommand());
    _operationP.set_ptrTIC(Tviewmodel->getTreeInsCommand());
    _operationP.set_ptrTDC(Tviewmodel->getTreeDelCommand());
    _operationP.set_Array(viewmodel->getArray());
    _operationP.set_Tree(Tviewmodel->getTree());

    viewmodel->AddCommandNotification(_operationP.getAACS());
    viewmodel->AddCommandNotification(_operationP.getADCS());
    viewmodel->AddCommandNotification(_operationP.getSPCS());
    viewmodel->AddCommandNotification(_operationP.getQDCS());
    viewmodel->AddPropertyNotification(_operationP.getOUS());

    Tviewmodel->AddCommandNotification(_operationP.getTICS());
    Tviewmodel->AddCommandNotification(_operationP.getTDCS());
    Tviewmodel->AddPropertyNotification(_operationP.getOUS());



    _testBC = std::make_shared<testButtonCommand>(this);
    _M1Command = std::make_shared<M1Command>(this);
    _M2Command = std::make_shared<M2Command>(this);
    _AboutCommand = std::make_shared<AboutCommand>(this);
    _getLine=std::make_shared<getlineCommand>(this);
    _cancelCommand=std::make_shared<cancelCommand>(this);
    _changeCommand=std::make_shared<changeCommand>(this);

    //_testWindow.setTestCommand(std::static_pointer_cast<ICommandBase>(this->_testBC));
    _firstPage.set_ptrM1Command(std::static_pointer_cast<ICommandBase>(this->_M1Command));
    _firstPage.set_ptrM2Command(std::static_pointer_cast<ICommandBase>(this->_M2Command));
    _firstPage.set_ptrAboutCommand(std::static_pointer_cast<ICommandBase>(this->_AboutCommand));
    _Model2_main.setGetCommand(std::static_pointer_cast<ICommandBase>(this->_getLine));
    _Model1_main.setChangeCommand(std::static_pointer_cast<ICommandBase>(this->_changeCommand));
    _aboutPage.set_ptrCancel(std::static_pointer_cast<ICommandBase>(this->_cancelCommand));
    //_testWindow.setCancelCommand(std::static_pointer_cast<ICommandBase>(this->_cancelCommand1));
    _Model1_main.setCancelCommand(std::static_pointer_cast<ICommandBase>(this->_cancelCommand));
    _Model2_main.setCancelCommand(std::static_pointer_cast<ICommandBase>(this->_cancelCommand));
    _operationP.setCancelCommand(std::static_pointer_cast<ICommandBase>(this->_cancelCommand));

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

model1_main * app::getModel1_main(){
    return & _Model1_main;
}

about* app::getAbout(){
    return & _aboutPage;
}

operation* app::getOp(){
    return & _operationP;
}
