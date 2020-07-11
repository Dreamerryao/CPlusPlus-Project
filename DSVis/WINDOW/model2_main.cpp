#include "model2_main.h"
#include "ui_model2_main.h"
#include <QTextBlock>
#include <qdebug.h>
#include <QRect>
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
void Model2_main::on_text_blockCountChanged(int newBlockCount)
{
    getLine();
}

void Model2_main::getLine(){
    QTextDocument* doc=ui->text->document () ;
    int cnt=doc->blockCount ();
    _NowCodeText = doc->findBlockByNumber(cnt-2).text();
     qDebug() << "--cout--" << endl <<_NowCodeText<<endl ;
     QString displayT = "Processing Code: "+_NowCodeText;
    ui->test->setText(displayT);
}

void Model2_main::on_pushButton_clicked()
{
    _getCancel->Exec();
}
void Model2_main::setCancelCommand(const std::shared_ptr<ICommandBase> &ptr_cancel){
    _getCancel=ptr_cancel;
}
