#include "mode1_display.h"
#include "ui_mode1_display.h"
#include <QRect>
#include <cmath>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
Mode1_display::Mode1_display(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Mode1_display)
{

    ui->setupUi(this);


    _M1CS = std::make_shared<Mode1_displayCommandSink>(Mode1_displayCommandSink(this));

    _OUS =  std::make_shared<OpUpdateSink>(OpUpdateSink(this));

    set_Array(NULL);
    set_Tree(NULL);
    qb=new QVBoxLayout(this);
}

Mode1_display::~Mode1_display()
{
    delete ui;
}

void Mode1_display::show_TQ(){
    if(type==4){
        _QP = new Square(this);
        _QP->resize(100,100);
//        _QP->move(100,100);
        _QP->hide();
    }

}

std::shared_ptr<ICommandNotification> Mode1_display::getM1CS(void){
    return _M1CS;
}

std::shared_ptr<IPropertyNotification> Mode1_display::getOUS(void){

    return _OUS;
}
void Mode1_display::on_pushButton_clicked()
{
    _getCancel->Exec();
}

void Mode1_display::hide_animation_add(){
    _QP->hide();
    if(type==4){
        try {
            _AAC->SetParameter(addText->text().toInt());
            _AAC->Exec();
        } catch (const char *msg) {
            QMessageBox::warning(this, tr("Waring"),tr("Input should be integer"),QMessageBox::Yes);
        }
    }
}
void Mode1_display::hide_animation_pop(){
    _QP->hide();
//    if(type==4){
//       _SPC->Exec();
//    }
}
void Mode1_display::setCancelCommand(const std::shared_ptr<ICommandBase> &ptr_cancel){
    _getCancel=ptr_cancel;
}

void Mode1_display::setLabel(const std::string& str){
//    std::string r = str;
   ui->type->setText(str.c_str());
}
void Mode1_display::set_Array(const std::shared_ptr<ARRAYC> &AC){
    this->_Array = AC;
}
void Mode1_display::set_Tree(const std::shared_ptr<Tree> &TC){
    this->_Tree = TC;

}

void Mode1_display::set_ptrAAC(const std::shared_ptr<ICommandBase> &ptr){
    _AAC = ptr;
}
void Mode1_display::set_ptrADC(const std::shared_ptr<ICommandBase> &ptr){
    _ADC = ptr;
}
void Mode1_display::set_ptrSPC(const std::shared_ptr<ICommandBase> &ptr){
    _SPC = ptr;
}
void Mode1_display::set_ptrQDC(const std::shared_ptr<ICommandBase> &ptr){
    _QDC = ptr;
}

void Mode1_display::set_ptrTIC(const std::shared_ptr<ICommandBase> &ptr){
    _TIC = ptr;
}
void Mode1_display::set_ptrTDC(const std::shared_ptr<ICommandBase> &ptr){
    _TDC = ptr;
}

void Mode1_display::on_add_button_clicked()
{
   if(addText->text()==""){
       QMessageBox::warning(this, tr("Waring"),tr("Input can't empty!"),QMessageBox::Yes);
   }
   else{
       if(type==4){
           //stack动画
           _QP->show();
           _QP->setValue(addText->text().toInt());
           QPropertyAnimation* animation1 = new QPropertyAnimation(_QP, "pos") ;
           animation1->setDuration(500);
           animation1->setStartValue(QPoint(100,100));
           animation1->setEndValue(QPoint(220,100));
           QPropertyAnimation* animation2 = new QPropertyAnimation(_QP, "pos") ;
           animation2->setDuration(700);

           animation2->setStartValue(QPoint(220,100));
           int size =_Array->getSize();
           if(size>=8)
           animation2->setEndValue(QPoint(220,110));
           else
           animation2->setEndValue(QPoint(220,510-50*size));
           QSequentialAnimationGroup *sequGroup = new QSequentialAnimationGroup(this);
           sequGroup->addAnimation(animation1);
           sequGroup->addAnimation(animation2);
           sequGroup->start();
           connect(sequGroup,SIGNAL(finished()),this,SLOT(hide_animation_add()));
       }
       else{
               _AAC->SetParameter(addText->text().toInt());
               _AAC->Exec();
       }
   }
    addText->setText(addText->text()); // convenient for testing
    //addText->setText("");
}

void Mode1_display::on_del_button_clicked()
{
    if(delText->text()==""){
        QMessageBox::warning(this, tr("Waring"),tr("Input can't empty!"),QMessageBox::Yes);
    }
    else{
            _ADC->SetParameter(delText->text().toInt());
            _ADC->Exec();
    }
    delText->setText(delText->text());
}

void Mode1_display::on_pushButton_2_clicked()  //pop
{

     if(type==4){//堆栈动画
         if(_Array->isArrayNull())  QMessageBox::warning(this, tr("Waring"),tr("Stack is empty!"),QMessageBox::Yes);
         else{

             _QP->show();
             int size =_Array->getSize();
             _QP->setValue(_Array->getNumIndex(size-1));
             _SPC->Exec();
             QPropertyAnimation* animation1 = new QPropertyAnimation(_QP, "pos") ;
             animation1->setDuration(500);
             animation1->setStartValue(QPoint(220,100));
             animation1->setEndValue(QPoint(700,100));
             QPropertyAnimation* animation2 = new QPropertyAnimation(_QP, "pos") ;
             if(size>=7){
                 animation2->setDuration(100);
                 animation2->setStartValue(QPoint(220,110));
             }

             else{
                 animation2->setStartValue(QPoint(220,510-50*size));
                 animation2->setDuration((510-50*size-100)*3);
             }

             animation2->setEndValue(QPoint(220,100));

             QSequentialAnimationGroup *sequGroup = new QSequentialAnimationGroup(this);
             sequGroup->addAnimation(animation2);
             sequGroup->addAnimation(animation1);
             sequGroup->start();
             connect(sequGroup,SIGNAL(finished()),this,SLOT(hide_animation_pop()));
         }

     }
}

void Mode1_display::set_treeType(){
    _Tree->type = type;
    _Tree->InitialTree();
}

void Mode1_display::set_arrayType(){
    if(type==6){
        _Array->type=1;
    }
    else{
        _Array->type=0;
    }
    _Array->InitArrayc();
}

void Mode1_display::on_deq_button_clicked()  //dequeue
{
    _QDC->Exec();
}

void Mode1_display::on_Tins_button_clicked(){
    _TIC->SetParameter(addText->text().toInt());
    _TIC->Exec();
}

void Mode1_display::on_Tdel_button_clicked(){
    _TDC->SetParameter(delText->text().toInt());
    _TDC->Exec();
}

void Mode1_display::show_button(){
    QLayoutItem *child;
     while ((child = qb->takeAt(0)) != 0){
            if(child->widget()){
                child->widget()->setParent(NULL);
            }
            delete child;
     }
    if(type==1 || type==2){
        addText=new QLineEdit("",this);
        addText->setGeometry(610,280,160,35);
        delText=new QLineEdit("",this);
        delText->setGeometry(610,380,160,35);
        button1=new QPushButton("",this);
        button1->setGeometry(610,330,160,35);
        button1->setStyleSheet("QPushButton{border-image:url(:/background/images/add.png);}");
        connect(button1,SIGNAL(clicked()),this,SLOT(on_add_button_clicked()));
        button2=new QPushButton("",this);
        button2->setGeometry(610,440,160,35);
        button2->setStyleSheet("QPushButton{border-image:url(:/background/images/delete.png);}");
        connect(button2,SIGNAL(clicked()),this,SLOT(on_del_button_clicked()));
        qb->addWidget(addText);
        qb->addWidget(delText);
        qb->addWidget(button1);
        qb->addWidget(button2);
    }
    else if(type==4){
        addText=new QLineEdit("",this);
        addText->setGeometry(610,330,160,35);
        button1=new QPushButton("",this);
        button1->setGeometry(610,380,160,35);
        connect(button1,SIGNAL(clicked()),this,SLOT(on_add_button_clicked()));
        button1->setStyleSheet("QPushButton{border-image:url(:/background/images/push.png);}");
        button2=new QPushButton("",this);
        button2->setGeometry(610,280,160,35);
        connect(button2,SIGNAL(clicked()),this,SLOT(on_pushButton_2_clicked()));
        button2->setStyleSheet("QPushButton{border-image:url(:/background/images/pop.png);}");
        qb->addWidget(addText);
        qb->addWidget(button1);
        qb->addWidget(button2);
    }else if(type==5){
        addText=new QLineEdit("",this);
        addText->setGeometry(610,330,160,35);
        button1=new QPushButton("",this);
        button1->setGeometry(610,380,160,35);
        connect(button1,SIGNAL(clicked()),this,SLOT(on_add_button_clicked()));
        button1->setStyleSheet("QPushButton{border-image:url(:/background/images/enqueue.png);}");
        button2=new QPushButton("",this);
        button2->setGeometry(610,280,160,35);
        connect(button2,SIGNAL(clicked()),this,SLOT(on_deq_button_clicked()));
        button2->setStyleSheet("QPushButton{border-image:url(:/background/images/dequeue.png);}");
        qb->addWidget(addText);
        qb->addWidget(button1);
        qb->addWidget(button2);
    }else if(type>6){
        addText=new QLineEdit("",this);
        addText->setGeometry(610,280,160,35);
        delText=new QLineEdit("",this);
        delText->setGeometry(610,380,160,35);
        button1=new QPushButton("",this);
        button1->setGeometry(610,330,160,35);
        connect(button1,SIGNAL(clicked()),this,SLOT(on_Tins_button_clicked()));
        button1->setStyleSheet("QPushButton{border-image:url(:/background/images/insert.png);}");
        button2=new QPushButton("",this);
        button2->setGeometry(610,440,160,35);
        connect(button2,SIGNAL(clicked()),this,SLOT(on_Tdel_button_clicked()));
        button2->setStyleSheet("QPushButton{border-image:url(:/background/images/delete.png);}");
        qb->addWidget(addText);
        qb->addWidget(delText);
        qb->addWidget(button1);
        qb->addWidget(button2);
    }else if(type==6){
        addText=new QLineEdit("",this);
        addText->setGeometry(610,280,160,35);
        button1=new QPushButton("",this);
        button1->setGeometry(610,330,160,35);
        connect(button1,SIGNAL(clicked()),this,SLOT(on_add_button_clicked()));
        button1->setStyleSheet("QPushButton{border-image:url(:/background/images/insert.png);}");
        button2=new QPushButton("",this);
        button2->setGeometry(610,380,160,35);
        connect(button2,SIGNAL(clicked()),this,SLOT(on_deq_button_clicked()));
        button2->setStyleSheet("QPushButton{border-image:url(:/background/images/deletemin.png);}");
        qb->addWidget(addText);
        qb->addWidget(button1);
        qb->addWidget(button2);
    }
}
void Mode1_display::paint_array(){
    QPixmap pixmap = QPixmap(":/background/images/hh.png").scaled(this->size());
    QPainter painter(this);
    painter.drawPixmap(this->rect(), pixmap);
    int i;
    int size =_Array->getSize();
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
void Mode1_display::paint_link(){
    QPixmap pixmap = QPixmap(":/background/images/hh.png").scaled(this->size());
    QPainter painter(this);
    painter.drawPixmap(this->rect(), pixmap);
    int i,j;
    int num=0;
    int size =_Array->getSize();
    int h = size/7;
    for(j=0;j<h;j++){
        for(i=0;i<7;i++){
            int wow = _Array->getNumIndex(i+j*7);
            QRect boundingRect;
            painter.drawText(40 + 80 *i,200+80*j,40,40,Qt::AlignCenter,QString::number(wow),&boundingRect);
            QRectF rectangle(40 + 80 *i, 200+80*j, 40, 40);
            painter.drawRoundedRect(rectangle, 5.0, 5.0);
            if(i!=6){
                painter.drawLine(80*(i+1),220+80*j,80*(i+1)+40,220+80*j);
                float x1 = 80*(i+1)+40;
                float y1 = 220+80*j;
                float x2 = 80*(i+1);
                float y2 = 220+80*j;
                float l = 30.0;
                float a = 0.3;
                float x3 = x2 - l * cos(atan2((y2 - y1) , (x2 - x1)) - a);
                float y3 = y2 - l * sin(atan2((y2 - y1) , (x2 - x1)) - a);
                float x4 = x2 - l * sin(atan2((x2 - x1) , (y2 - y1)) - a);
                float y4 = y2 - l * cos(atan2((x2 - x1) , (y2 - y1)) - a);
                painter.drawLine(x1,y1,x3,y3);
                painter.drawLine(x1,y1,x4,y4);
            }
            if(num%7==0&&num!=0){
                painter.drawLine(20,180+80*j,580,180+80*j);
                painter.drawLine(20,180+80*j,20,220+80*j);
                painter.drawLine(20,220+80*j,40,220+80*j);
                painter.drawLine(20,220+80*j,40,220+80*j);
                painter.drawLine(560,140+80*j,580,140+80*j);
                painter.drawLine(580,180+80*j,580,140+80*j);
                float x1 = 80*(i)+40;
                float y1 = 220+80*(j);
                float x2 = 80*(i);
                float y2 = 220+80*(j);
                float l = 30.0;
                float a = 0.3;
                float x3 = x2 - l * cos(atan2((y2 - y1) , (x2 - x1)) - a);
                float y3 = y2 - l * sin(atan2((y2 - y1) , (x2 - x1)) - a);
                float x4 = x2 - l * sin(atan2((x2 - x1) , (y2 - y1)) - a);
                float y4 = y2 - l * cos(atan2((x2 - x1) , (y2 - y1)) - a);
                painter.drawLine(x1,y1,x3,y3);
                painter.drawLine(x1,y1,x4,y4);
            }
            num++;
        }

    }
    for(i=0;i<size%7;i++){
        int wow = _Array->getNumIndex(i+h*7);
        QRect boundingRect;
        painter.drawText(40 + 80 *i,200+80*h,40,40,Qt::AlignCenter,QString::number(wow),&boundingRect);
        QRectF rectangle(40 + 80 *i, 200+80*h, 40, 40);
        painter.drawRoundedRect(rectangle, 5.0, 5.0);
        if(i!=size%7-1){
            painter.drawLine(80*(i+1),220+80*h,80*(i+1)+40,220+80*h);
            float x1 = 80*(i+1)+40;
            float y1 = 220+80*h;
            float x2 = 80*(i+1);
            float y2 = 220+80*h;
            float l = 30.0;
            float a = 0.3;
            float x3 = x2 - l * cos(atan2((y2 - y1) , (x2 - x1)) - a);
            float y3 = y2 - l * sin(atan2((y2 - y1) , (x2 - x1)) - a);
            float x4 = x2 - l * sin(atan2((x2 - x1) , (y2 - y1)) - a);
            float y4 = y2 - l * cos(atan2((x2 - x1) , (y2 - y1)) - a);
            painter.drawLine(x1,y1,x3,y3);
            painter.drawLine(x1,y1,x4,y4);
        }
        if(num%7==0&&num!=0){
            painter.drawLine(20,180+80*j,580,180+80*j);
            painter.drawLine(20,180+80*j,20,220+80*j);
            painter.drawLine(20,220+80*j,40,220+80*j);
            painter.drawLine(20,220+80*j,40,220+80*j);
            painter.drawLine(560,140+80*j,580,140+80*j);
            painter.drawLine(580,180+80*j,580,140+80*j);
            float x1 = 80*(i)+40;
            float y1 = 220+80*h;
            float x2 = 80*(i);
            float y2 = 220+80*h;
            float l = 30.0;
            float a = 0.3;
            float x3 = x2 - l * cos(atan2((y2 - y1) , (x2 - x1)) - a);
            float y3 = y2 - l * sin(atan2((y2 - y1) , (x2 - x1)) - a);
            float x4 = x2 - l * sin(atan2((x2 - x1) , (y2 - y1)) - a);
            float y4 = y2 - l * cos(atan2((x2 - x1) , (y2 - y1)) - a);
            painter.drawLine(x1,y1,x3,y3);
            painter.drawLine(x1,y1,x4,y4);
        }
        num++;
    }
}
void Mode1_display::paint_stack(){
    QPixmap pixmap = QPixmap(":/background/images/hh.png").scaled(this->size());
    QPainter painter(this);
    painter.drawPixmap(this->rect(), pixmap);
    int i;
    int size =_Array->getSize();
    if(size==0){
        painter.drawLine(200,160,200,560);
        painter.drawLine(280,160,280,560);
        painter.drawLine(200,560,280,560);
        float x1 = 280;
        float y1 = 560;
        float x2 = 320;
        float y2 = 560;
        float l = 30.0;
        float a = 0.3;
        float x3 = x2 - l * cos(atan2((y2 - y1) , (x2 - x1)) - a);
        float y3 = y2 - l * sin(atan2((y2 - y1) , (x2 - x1)) - a);
        float x4 = x2 - l * sin(atan2((x2 - x1) , (y2 - y1)) - a);
        float y4 = y2 - l * cos(atan2((x2 - x1) , (y2 - y1)) - a);
        painter.drawLine(x1,y1,x3,y3);
        painter.drawLine(x1,y1,x4,y4);
        painter.drawLine(x1,y1,x2,y2);
        painter.drawText(325,570,tr("SP"));
    }
    else if(size>8){
        painter.drawLine(200,160,200,560);
        painter.drawLine(280,160,280,560);
        for(i=0;i<8;i++){
            int wow = _Array->getNumIndex(size-8+i);
            QRect boundingRect;
            painter.drawText(220, 510-50*i,40,40,Qt::AlignCenter,QString::number(wow),&boundingRect);
            QRectF rectangle(220, 510-50*i, 40, 40);
            painter.drawRoundedRect(rectangle, 5.0, 5.0);
            if(i==7){
                float x1 = 280;
                float y1 = 510-50*i;
                float x2 = 320;
                float y2 = 510-50*i;
                float l = 30.0;
                float a = 0.3;
                float x3 = x2 - l * cos(atan2((y2 - y1) , (x2 - x1)) - a);
                float y3 = y2 - l * sin(atan2((y2 - y1) , (x2 - x1)) - a);
                float x4 = x2 - l * sin(atan2((x2 - x1) , (y2 - y1)) - a);
                float y4 = y2 - l * cos(atan2((x2 - x1) , (y2 - y1)) - a);
                painter.drawLine(x1,y1,x3,y3);
                painter.drawLine(x1,y1,x4,y4);
                painter.drawLine(x1,y1,x2,y2);
                painter.drawText(325,520-50*i,tr("SP"));
            }
        }
    }
    else{
        painter.drawLine(200,160,200,560);
        painter.drawLine(280,160,280,560);
        painter.drawLine(200,560,280,560);
        for(i=0;i<size;i++){
            int wow = _Array->getNumIndex(i);
            QRect boundingRect;
            painter.drawText(220, 510-50*i,40,40,Qt::AlignCenter,QString::number(wow),&boundingRect);
            QRectF rectangle(220, 510-50*i, 40, 40);
            painter.drawRoundedRect(rectangle, 5.0, 5.0);
            if(i==size-1){
                float x1 = 280;
                float y1 = 510-50*i;
                float x2 = 320;
                float y2 = 510-50*i;
                float l = 30.0;
                float a = 0.3;
                float x3 = x2 - l * cos(atan2((y2 - y1) , (x2 - x1)) - a);
                float y3 = y2 - l * sin(atan2((y2 - y1) , (x2 - x1)) - a);
                float x4 = x2 - l * sin(atan2((x2 - x1) , (y2 - y1)) - a);
                float y4 = y2 - l * cos(atan2((x2 - x1) , (y2 - y1)) - a);
                painter.drawLine(x1,y1,x3,y3);
                painter.drawLine(x1,y1,x4,y4);
                painter.drawLine(x1,y1,x2,y2);
                painter.drawText(325,520-50*i,tr("SP"));
            }
        }
    }
}
void Mode1_display::paint_queue(){
    QPixmap pixmap = QPixmap(":/background/images/hh.png").scaled(this->size());
    QPainter painter(this);
    painter.drawPixmap(this->rect(), pixmap);
    int i;
    int size =_Array->getSize();
    painter.drawLine(40,200,580,200);
    painter.drawLine(40,260,580,260);
    if(size<12){
        for(i=0;i<size;i++){
            int wow = _Array->getNumIndex(i);
            QRect boundingRect;
            painter.drawText(40+50*i, 210,40,40,Qt::AlignCenter,QString::number(wow),&boundingRect);
            QRectF rectangle(40+50*i, 210, 40, 40);
            painter.drawRoundedRect(rectangle, 5.0, 5.0);
        }
    }else{
        for(i=0;i<5;i++){
            int wow = _Array->getNumIndex(i);
            QRect boundingRect;
            painter.drawText(40+50*i, 210,40,40,Qt::AlignCenter,QString::number(wow),&boundingRect);
            QRectF rectangle(40+50*i, 210, 40, 40);
            painter.drawRoundedRect(rectangle, 5.0, 5.0);
        }
        QRect boundingRect;
        painter.drawText(40+50*5, 210,40,40,Qt::AlignCenter,"...",&boundingRect);
        QRectF rectangle(40+50*5, 210, 40, 40);
        painter.drawRoundedRect(rectangle, 5.0, 5.0);
        int num=6;
        for(i=size-5;i<size;i++){
            int wow = _Array->getNumIndex(i);
            QRect boundingRect;
            painter.drawText(40+50*num, 210,40,40,Qt::AlignCenter,QString::number(wow),&boundingRect);
            QRectF rectangle(40+50*num, 210, 40, 40);
            painter.drawRoundedRect(rectangle, 5.0, 5.0);
            num++;
        }
    }
}
void Mode1_display::paint_tree(){
    QPixmap pixmap = QPixmap(":/background/images/hh.png").scaled(this->size());
    QPainter painter(this);
    painter.drawPixmap(this->rect(), pixmap);
    std::vector<node*> queue;
    float xp[40];
    float yp[40];
    int hei[40];
    int cal[7]={0,4,2,1,1,1,1};
    int qhead=0;
    node *root=_Tree->getTree();
    if(root!=NULL){
        queue.push_back(root);
        xp[0]=280;
        yp[0]=180;
        hei[0]=0;
        int qsize=0;
        while(qhead<queue.size()){
            root = queue[qhead];
            QRect boundingRect;
            painter.drawText(xp[qhead], yp[qhead],40,40,Qt::AlignCenter,QString::number(root->value),&boundingRect);
            painter.drawEllipse(xp[qhead],yp[qhead],40,40);
            if(root->left!=NULL){
                queue.push_back(root->left);
                qsize++;
                hei[qsize]=hei[qhead]+1;
                xp[qsize]=xp[qhead]-40*cal[hei[qsize]];
                yp[qsize]=yp[qhead]+80;
                painter.drawLine(xp[qhead]+20,yp[qhead]+40,xp[qsize]+20,yp[qsize]);
            }
            if(root->right!=NULL){
                queue.push_back(root->right);
                qsize++;
                hei[qsize]=hei[qhead]+1;
                xp[qsize]=xp[qhead]+40*cal[hei[qsize]];
                yp[qsize]=yp[qhead]+80;
                painter.drawLine(xp[qhead]+20,yp[qhead]+40,xp[qsize]+20,yp[qsize]);
            }
            qhead++;
        }
    }
}
void Mode1_display::paint_RBT(){
    QPixmap pixmap = QPixmap(":/background/images/hh.png").scaled(this->size());
    QPainter painter(this);
    painter.drawPixmap(this->rect(), pixmap);
    std::vector<node*> queue;
    float xp[40];
    float yp[40];
    int hei[40];
    int cal[7]={0,4,2,1,1,1,1};
    int qhead=0;
    node *root=_Tree->getTree();
    if(root!=NULL){
        queue.push_back(root);
        xp[0]=280;
        yp[0]=180;
        hei[0]=0;
        int qsize=0;
        while(qhead<queue.size()){
            root = queue[qhead];
            QRect boundingRect;
            if(root->color==0){
                painter.setPen(QPen(Qt::black,4));
            }else{
                painter.setPen(QPen(Qt::red,4));
            }
            painter.drawText(xp[qhead], yp[qhead],40,40,Qt::AlignCenter,QString::number(root->value),&boundingRect);
            painter.drawEllipse(xp[qhead],yp[qhead],40,40);
            painter.setPen(QPen(Qt::black,1));
            if(root->left!=NULL){
                queue.push_back(root->left);
                qsize++;
                hei[qsize]=hei[qhead]+1;
                xp[qsize]=xp[qhead]-40*cal[hei[qsize]];
                yp[qsize]=yp[qhead]+80;
                painter.drawLine(xp[qhead]+20,yp[qhead]+40,xp[qsize]+20,yp[qsize]);
            }
            if(root->right!=NULL){
                queue.push_back(root->right);
                qsize++;
                hei[qsize]=hei[qhead]+1;
                xp[qsize]=xp[qhead]+40*cal[hei[qsize]];
                yp[qsize]=yp[qhead]+80;
                painter.drawLine(xp[qhead]+20,yp[qhead]+40,xp[qsize]+20,yp[qsize]);
            }
            qhead++;
        }
    }
}
void Mode1_display::paint_heap(){
    QPixmap pixmap = QPixmap(":/background/images/hh.png").scaled(this->size());
    QPainter painter(this);
    painter.drawPixmap(this->rect(), pixmap);
    float xp[40];
    float yp[40];
    int hei[40];
    int cal[7]={4,2,1,1,1,1,1};
    int qf,i;
    int num=_Array->getSize();
    if(num>0){
        xp[1]=280;
        yp[1]=180;
        hei[1]=0;
        QRect boundingRect;
        painter.drawText(xp[1], yp[1],40,40,Qt::AlignCenter,QString::number(_Array->getNumIndex(0)),&boundingRect);
        painter.drawEllipse(xp[1],yp[1],40,40);
        for(i=1;i<num;i++){
            qf=(i+1)/2;
            hei[i+1]=hei[qf]+1;
            if(i%2==1){
                xp[i+1]=xp[qf]-40*cal[hei[qf]];
            }
            else{
                xp[i+1]=xp[qf]+40*cal[hei[qf]];
            }
            yp[i+1]=yp[qf]+80;
            QRect boundingRect;
            painter.drawText(xp[i+1], yp[i+1],40,40,Qt::AlignCenter,QString::number(_Array->getNumIndex(i)),&boundingRect);
            painter.drawEllipse(xp[i+1],yp[i+1],40,40);
            painter.drawLine(xp[qf]+20,yp[qf]+40,xp[i+1]+20,yp[i+1]);
        }
    }
}
void Mode1_display::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QFont font = painter.font();
    font.setPixelSize(20);
    painter.setFont(font);
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QColor(245, 233, 227)));
    setPalette(palette);
    if(type==1){
        paint_array();
    }
    else if(type==2){
        paint_link();
    }
    else if(type==4){//only display the top 8 elements
        paint_stack();
    }
    else if(type==5){
        paint_queue();
    }
    else if(type>6&&type<9){
        paint_tree();
    }
    else if(type==9){
        paint_RBT();
    }
    else if(type==6){
        paint_heap();
    }
}
