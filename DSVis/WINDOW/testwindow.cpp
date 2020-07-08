#include "testwindow.h"
#include "ui_testwindow.h"

testWindow::testWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::testWindow)
{
    ui->setupUi(this);
}

testWindow::~testWindow()
{
    delete ui;
}
void testWindow::setTestCommand(std::shared_ptr<ICommandBase> ptr_test){
    _testCommand = ptr_test;
}

void testWindow::on_pushButton_clicked()
{
   _testCommand->Exec();
}

void testWindow::setLabel(const std::string& str){
    if(str == "www")
    ui->label_2->setText("wow");
    else ui->label_2->setText("weeee");
}

void testWindow::on_pushButton_2_clicked()
{
    _getCancel->Exec();
}

void testWindow::setCancelCommand(std::shared_ptr<ICommandBase> ptr_cancel){
    _getCancel=ptr_cancel;
}
