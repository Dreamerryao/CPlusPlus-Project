#include "model2_main.h"
#include "ui_model2_main.h"
#include <QTextBlock>
Model2_main::Model2_main(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Model2_main)
{
    ui->setupUi(this);
}

Model2_main::~Model2_main()
{
    delete ui;
}
void Model2_main::setGetCommand(std::shared_ptr<ICommandBase> ptr_get){
    _getCommand=ptr_get;
}
void Model2_main::on_text_blockCountChanged(int newBlockCount)
{
    _getCommand->Exec();
}

void Model2_main::getLine(){
    QTextDocument* doc=ui->text->document () ;
    int cnt=doc->blockCount ();
    QTextBlock textLine=doc->findBlockByNumber(cnt-2) ;
    QString tstr=textLine.text();
    ui->test->setText(tstr);
}

void Model2_main::on_pushButton_clicked()
{
    _getCancel->Exec();
}
void Model2_main::setCancelCommand(std::shared_ptr<ICommandBase> ptr_cancel){
    _getCancel=ptr_cancel;
}
