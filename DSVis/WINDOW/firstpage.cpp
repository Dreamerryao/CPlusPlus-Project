#include "firstpage.h"
#include "ui_firstpage.h"

FirstPage::FirstPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FirstPage)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("DS Vis"));//title
}

FirstPage::~FirstPage()
{
    delete ui;
}
void FirstPage::set_ptrM1Command(const std::shared_ptr<ICommandBase> &ptrCommand){
    _ptrM1Command=ptrCommand;
}
void FirstPage::set_ptrM2Command(const std::shared_ptr<ICommandBase> &ptrCommand){
    _ptrM2Command=ptrCommand;
}
void FirstPage::set_ptrAboutCommand(const std::shared_ptr<ICommandBase> &ptrCommand){
    _ptrAboutCommand=ptrCommand;
}
void FirstPage::on_m2_button_clicked()
{
    _ptrM2Command->Exec();
}

void FirstPage::on_about_button_clicked()
{
    _ptrAboutCommand->Exec();
}

void FirstPage::on_M1_button_clicked()
{
    _ptrM1Command->Exec();
}
