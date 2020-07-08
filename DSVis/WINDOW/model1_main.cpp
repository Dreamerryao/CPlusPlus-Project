#include "model1_main.h"
#include "ui_model1_main.h"

model1_main::model1_main(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::model1_main)
{
    ui->setupUi(this);
}

model1_main::~model1_main()
{
    delete ui;
}

void model1_main::setCancelCommand(std::shared_ptr<ICommandBase> ptr_cancel){
    _getCancel=ptr_cancel;
}
void model1_main::on_pushButton_10_clicked()
{
    _getCancel->Exec();
}

void model1_main::setChangeCommand(std::shared_ptr<ICommandBase> ptr_change){
    _getChange=ptr_change;
}

void model1_main::on_pushButton_clicked()
{
    type=1;
    _getChange->Exec();
}

void model1_main::on_pushButton_2_clicked()
{
    type=2;
    _getChange->Exec();
}

void model1_main::on_pushButton_3_clicked()
{

    _getChange->Exec();
    type=3;
}

void model1_main::on_pushButton_4_clicked()
{
   type=4;
    _getChange->Exec();
}

void model1_main::on_pushButton_5_clicked()
{
    type=5;
    _getChange->Exec();
}

void model1_main::on_pushButton_6_clicked()
{
    type=6;
    _getChange->Exec();
}

void model1_main::on_pushButton_7_clicked()
{
    type=7;
    _getChange->Exec();
}

void model1_main::on_pushButton_8_clicked()
{
    type=8;
    _getChange->Exec();
}

void model1_main::on_pushButton_9_clicked()
{
    type=9;
    _getChange->Exec();
}
