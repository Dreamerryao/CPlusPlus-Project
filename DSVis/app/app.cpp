#include <QApplication>
#include "app.h"

app::app()
{
}

app::~app()
{
}

void app::run(){

    //model初始化
    model = std::make_shared<ArrayModel>();
    Tmodel = std::make_shared<TreeModel>();

    //viewModel初始化，绑定model
    viewmodel = std::make_shared<ArrayViewModel>();
    viewmodel->setArrayModel(model);
    Tviewmodel = std::make_shared<TreeViewModel>();
    Tviewmodel->setTreeModel(Tmodel);

    //debug重绘绑定指针问题

    //对Mode1的展示界面进行命令的绑定，如array add command
    _Mode1_displayP.set_ptrAAC(viewmodel->getArrayAddCommand());
    _Mode1_displayP.set_ptrADC(viewmodel->getArrayDelCommand());
    _Mode1_displayP.set_ptrSPC(viewmodel->getStackPopCommand());
    _Mode1_displayP.set_ptrQDC(viewmodel->getQueueDeqCommand());
    _Mode1_displayP.set_ptrTIC(Tviewmodel->getTreeInsCommand());
    _Mode1_displayP.set_ptrTDC(Tviewmodel->getTreeDelCommand());
    _Mode1_displayP.set_Array(viewmodel->getArray());
    _Mode1_displayP.set_Tree(Tviewmodel->getTree());

     _Model2_main.set_ptrAAC(viewmodel->getArrayAddCommand());
     _Model2_main.set_ptrADC(viewmodel->getArrayDelCommand());
     _Model2_main.set_ptrSPC(viewmodel->getStackPopCommand());
     _Model2_main.set_ptrQDC(viewmodel->getQueueDeqCommand());
     _Model2_main.set_ptrTIC(Tviewmodel->getTreeInsCommand());
     _Model2_main.set_ptrTDC(Tviewmodel->getTreeDelCommand());
     _Model2_main.set_ptrANC(viewmodel->getArrayNewCommand());
     _Model2_main.set_ptrTNC(Tviewmodel->getTreeNewCommand());
     _Model2_main.set_ptrARC(viewmodel->getArrayReplaceCommand());
     _Model2_main.set_Array(viewmodel->getArray());
     _Model2_main.set_Tree(Tviewmodel->getTree());


    //ViewModel 添加notification
    viewmodel->AddCommandNotification(_Mode1_displayP.getM1CS());
    viewmodel->AddPropertyNotification(_Mode1_displayP.getOUS());
    Tviewmodel->AddCommandNotification(_Mode1_displayP.getM1CS());
    Tviewmodel->AddPropertyNotification(_Mode1_displayP.getOUS());

    viewmodel->AddCommandNotification(_Model2_main.getM2CS());
    viewmodel->AddPropertyNotification(_Model2_main.getM2US());
    Tviewmodel->AddCommandNotification(_Model2_main.getM2CS());
    Tviewmodel->AddPropertyNotification(_Model2_main.getM2US());


    //界面跳转相关命令
    _M1Command = std::make_shared<M1Command>(this);
    _M2Command = std::make_shared<M2Command>(this);
    _AboutCommand = std::make_shared<AboutCommand>(this);
    _cancelCommand=std::make_shared<cancelCommand>(this);
    _changeCommand=std::make_shared<changeCommand>(this);

    //firstPage绑定 转到 Mode1,Mode2,About界面的命令
    _firstPage.set_ptrM1Command(this->_M1Command);
    _firstPage.set_ptrM2Command(this->_M2Command);
    _firstPage.set_ptrAboutCommand(this->_AboutCommand);

    //mode1_main绑定 转到Mode1_display界面的命令
    _Model1_main.setChangeCommand(this->_changeCommand);

    //返回FirstPage命令
    _aboutPage.set_ptrCancel(this->_cancelCommand);
    _Model1_main.setCancelCommand(this->_cancelCommand);
    _Model2_main.setCancelCommand(this->_cancelCommand);
    _Mode1_displayP.setCancelCommand(this->_cancelCommand);

    //显示初始界面
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

Mode1_display* app::getOp(){
    return & _Mode1_displayP;
}
