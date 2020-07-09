#include "model1_main.h"
#include "ui_model1_main.h"

model1_main::model1_main(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::model1_main)
{
    TT = "";
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
    TT = "Array";
    type=1;
    _getChange->Exec();
}

void model1_main::on_pushButton_2_clicked()
{
    TT = "Link";
    type=2;
    _getChange->Exec();
}

void model1_main::on_pushButton_3_clicked()
{
     TT = "Matrix";
     type=3;
    _getChange->Exec();

}

void model1_main::on_pushButton_4_clicked()
{
    TT="Stack";
    type=4;
    _getChange->Exec();
}

void model1_main::on_pushButton_5_clicked()
{
    TT="Queue";
    type=5;
    _getChange->Exec();
}

void model1_main::on_pushButton_6_clicked()
{
    TT="Heap";
    type=6;
    _getChange->Exec();
}

void model1_main::on_pushButton_7_clicked()
{
    TT="Bianry search tree";
    type=7;
    _getChange->Exec();
}

void model1_main::on_pushButton_8_clicked()
{
    TT="Avl tree";
    type=8;
    _getChange->Exec();
}

void model1_main::on_pushButton_9_clicked()
{
    TT="Red black tree";
    type=9;
    _getChange->Exec();
}
