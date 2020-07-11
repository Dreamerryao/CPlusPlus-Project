#ifndef APP_H
#define APP_H

#include"../model/arraymodel.h"
#include "../model/treemodel.h"
#include "../viewModel/arrayviewmodel.h"
#include"../viewModel/treeviewmodel.h"

#include "../WINDOW/firstpage.h"
#include "../WINDOW/model2_main.h"
#include "../WINDOW/model1_main.h"
#include "../WINDOW/about.h"
#include "../WINDOW/mode1_display.h"

#include "commands/m1command.h"
#include "commands/m2command.h"
#include "commands/aboutcommand.h"
#include "commands/cancelcommand.h"
#include "commands/changecommand.h"
class app
{
private:
    //view 界面
    Model2_main _Model2_main;
    model1_main _Model1_main;
    FirstPage _firstPage;
    about _aboutPage;
    Mode1_display _Mode1_displayP;

    //model
    std::shared_ptr<ArrayModel> model;
    std::shared_ptr<TreeModel> Tmodel;
    //viewModel
    std::shared_ptr<TreeViewModel> Tviewmodel;
    std::shared_ptr<ArrayViewModel> viewmodel;
    //界面跳转相关命令
    std::shared_ptr<M1Command> _M1Command;
    std::shared_ptr<M2Command> _M2Command;
    std::shared_ptr<AboutCommand> _AboutCommand;
    std::shared_ptr<cancelCommand> _cancelCommand;
    std::shared_ptr<changeCommand> _changeCommand;

public:
    app();
    ~app();
    void run();
    FirstPage* getFirstPage();
    Model2_main* getModel2_main();
    model1_main* getModel1_main();
    about* getAbout();
    Mode1_display* getOp();
};
#endif // APP_H
