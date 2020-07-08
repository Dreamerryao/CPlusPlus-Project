#include "operation.h"
#include "ui_operation.h"
#include <QRect>
operation::operation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::operation)
{

    ui->setupUi(this);
    _AACS = std::make_shared<AAddCommandSink>(AAddCommandSink(this));
    _OUS =  std::make_shared<OpUpdateSink>(OpUpdateSink(this));
    set_Array(NULL);
}

operation::~operation()
{
    delete ui;
}
std::shared_ptr<ICommandNotification> operation::getAACS(void){

    return std::static_pointer_cast<ICommandNotification>(_AACS);
}
std::shared_ptr<IPropertyNotification> operation::getOUS(void){

    return std::static_pointer_cast<IPropertyNotification>(_OUS);
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
    this->resize(600, 600);
//    QString s = QString::number(size);
//    ui->type->setText(s);
    ui->type->move(600/2-150,0);
    ui->pushButton->move(0,600-600/9);
    for(i=0;i<size;i++){
        int wow = _Array->getNumIndex(i);
        QRect boundingRect;
        painter.drawText(40 + 80 *i,200,40,40,Qt::AlignCenter,QString::number(wow),&boundingRect);
//        QPen pen;
//        pen.setWidth(7);
//        pen.setBrush(QColor(150, 150, 150));
//        painter.setPen(pen);
//        painter.setPen(pen);
//        painter.setBrush(Qt::black);
//        painter.setRenderHint(QPainter::Antialiasing, true);
        QRectF rectangle(40 + 80 *i, 200, 40, 40);
        painter.drawRoundedRect(rectangle, 5.0, 5.0);
    }


}
