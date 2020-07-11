#include "mode1_display.h"
#include "ui_mode1_display.h"
#include <QRect>
operation::operation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::operation)
{

    ui->setupUi(this);
    _OCS = std::make_shared<OpCommandSink>(OpCommandSink(this));
//    _AACS = std::make_shared<AAddCommandSink>(AAddCommandSink(this));
//    _ADCS = std::make_shared<ADelCommandSink>(ADelCommandSink(this));
    _OUS =  std::make_shared<OpUpdateSink>(OpUpdateSink(this));
    set_Array(NULL);
}

operation::~operation()
{
    delete ui;
}
//std::shared_ptr<ICommandNotification> operation::getAACS(void){

//    return _AACS;
//}
//std::shared_ptr<ICommandNotification> operation::getADCS(void){

//    return _ADCS;
//}
std::shared_ptr<ICommandNotification> operation::getOCS(void){

    return _OCS;
}
std::shared_ptr<IPropertyNotification> operation::getOUS(void){

    return _OUS;
}
void operation::on_pushButton_clicked()
{
    _getCancel->Exec();
}

void operation::setCancelCommand(std::shared_ptr<ICommandBase> ptr_cancel){
    _getCancel=ptr_cancel;
}

void operation::setLabel(const std::string& str){
//    std::string r = str;
   ui->type->setText(str.c_str());
}
void operation::set_Array(std::shared_ptr<ARRAYC> AC){
    this->_Array = AC;
}

void operation::set_ptrAAC(std::shared_ptr<ICommandBase> ptr){
    _AAC = ptr;
}
void operation::set_ptrADC(std::shared_ptr<ICommandBase> ptr){
    _ADC = ptr;
}
void operation::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QFont font = painter.font();
    font.setPixelSize(20);
    painter.setFont(font);
    int size =_Array->getSize();
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QColor(245, 233, 227)));
    setPalette(palette);
    int i;
    int h = size/7;
    for(int j=0;j<h;j++){
    for(i=0;i<7;i++){
        int wow = _Array->getNumIndex(i+j*7);
        QRect boundingRect;
        painter.drawText(40 + 80 *i,200+80*j,40,40,Qt::AlignCenter,QString::number(wow),&boundingRect);
        QRectF rectangle(40 + 80 *i, 200+80*j, 40, 40);
        painter.drawRoundedRect(rectangle, 5.0, 5.0);
    }
    }
    for(i=0;i<size%7;i++){
        int wow = _Array->getNumIndex(i+h*7);
        QRect boundingRect;
        painter.drawText(40 + 80 *i,200+80*h,40,40,Qt::AlignCenter,QString::number(wow),&boundingRect);

        QRectF rectangle(40 + 80 *i, 200+80*h, 40, 40);
        painter.drawRoundedRect(rectangle, 5.0, 5.0);
    }


}

void operation::on_add_button_clicked()
{
   if(ui->addLineEdit->text()==""){
       QMessageBox::warning(this, tr("Waring"),tr("Input can't empty!"),QMessageBox::Yes);
   }
   else{
           _AAC->SetParameter(ui->addLineEdit->text().toInt());
           _AAC->Exec();

   }

}

void operation::on_del_button_clicked()
{
    if(ui->delText->text()==""){
        QMessageBox::warning(this, tr("Waring"),tr("Input can't empty!"),QMessageBox::Yes);
    }
    else{
            _ADC->SetParameter(ui->delText->text().toInt());
            _ADC->Exec();

    }
}
