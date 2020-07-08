#include "operation.h"
#include "ui_operation.h"

operation::operation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::operation)
{

    ui->setupUi(this);
}

operation::~operation()
{
    delete ui;
}

void operation::on_pushButton_clicked()
{
    _getCancel->Exec();
}

void operation::setCancelCommand(std::shared_ptr<ICommandBase> ptr_cancel){
    _getCancel=ptr_cancel;
}

void operation::on_pushButton_2_clicked()
{
    QString str=QString::number(type);
    ui->type->setText(str);
}
