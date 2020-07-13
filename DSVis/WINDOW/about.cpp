#include "about.h"
#include "ui_about.h"

about::about(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);
}

about::~about()
{
    delete ui;
}

void about::set_ptrCancel(const std::shared_ptr<ICommandBase> &ptrcancel){
    _ptrCancel=ptrcancel;
}

void about::on_cancel_clicked()
{
    _ptrCancel->Exec();
}
