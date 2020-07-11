#include "operation.h"
#include "ui_operation.h"
#include <QRect>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
operation::operation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::operation)
{

    ui->setupUi(this);


    _AACS = std::make_shared<AAddCommandSink>(AAddCommandSink(this));
    _ADCS = std::make_shared<ADelCommandSink>(ADelCommandSink(this));
    _SPCS = std::make_shared<SPopCommandSink>(SPopCommandSink(this));
    _QDCS = std::make_shared<QDeqCommandSink>(QDeqCommandSink(this));
    _ARCS = std::make_shared<AReplaceCommandSink>(AReplaceCommandSink(this));
    _ANCS = std::make_shared<ANewCommandSink>(ANewCommandSink(this));
    _TICS = std::make_shared<TInsCommandSink>(TInsCommandSink(this));
    _TDCS = std::make_shared<TDelCommandSink>(TDelCommandSink(this));
    _OUS =  std::make_shared<OpUpdateSink>(OpUpdateSink(this));

    set_Array(NULL);
    set_Tree(NULL);
    qb=new QVBoxLayout(this);
}

operation::~operation()
{
    delete ui;
}

void operation::show_TQ(){
    if(type==4){
        _QP = new Square(this);
        _QP->resize(100,100);
//        _QP->move(100,100);
        _QP->hide();
    }

}
void operation::show_button(){
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
        button1=new QPushButton("add",this);
        button1->setGeometry(610,330,160,35);
        connect(button1,SIGNAL(clicked()),this,SLOT(on_add_button_clicked()));
        button2=new QPushButton("delete",this);
        button2->setGeometry(610,440,160,35);
        connect(button2,SIGNAL(clicked()),this,SLOT(on_del_button_clicked()));
        qb->addWidget(addText);
        qb->addWidget(delText);
        qb->addWidget(button1);
        qb->addWidget(button2);
    }
    else if(type==4){
        addText=new QLineEdit("",this);
        addText->setGeometry(610,330,160,35);
        button1=new QPushButton("push",this);
        button1->setGeometry(610,380,160,35);
        connect(button1,SIGNAL(clicked()),this,SLOT(on_add_button_clicked()));
        button2=new QPushButton("pop",this);
        button2->setGeometry(610,280,160,35);
        connect(button2,SIGNAL(clicked()),this,SLOT(on_pushButton_2_clicked()));
        qb->addWidget(addText);
        qb->addWidget(button1);
        qb->addWidget(button2);
    }else if(type==5){
        addText=new QLineEdit("",this);
        addText->setGeometry(610,330,160,35);
        button1=new QPushButton("enqueue",this);
        button1->setGeometry(610,380,160,35);
        connect(button1,SIGNAL(clicked()),this,SLOT(on_add_button_clicked()));
        button2=new QPushButton("dequque",this);
        button2->setGeometry(610,280,160,35);
        connect(button2,SIGNAL(clicked()),this,SLOT(on_deq_button_clicked()));
        qb->addWidget(addText);
        qb->addWidget(button1);
        qb->addWidget(button2);
    }else if(type>=6){
        addText=new QLineEdit("",this);
        addText->setGeometry(610,280,160,35);
        delText=new QLineEdit("",this);
        delText->setGeometry(610,380,160,35);
        button1=new QPushButton("insert",this);
        button1->setGeometry(610,330,160,35);
        connect(button1,SIGNAL(clicked()),this,SLOT(on_Tins_button_clicked()));
        button2=new QPushButton("delete",this);
        button2->setGeometry(610,440,160,35);
        connect(button2,SIGNAL(clicked()),this,SLOT(on_Tdel_button_clicked()));
        qb->addWidget(addText);
        qb->addWidget(delText);
        qb->addWidget(button1);
        qb->addWidget(button2);
    }
}
std::shared_ptr<ICommandNotification> operation::getAACS(void){

    return std::static_pointer_cast<ICommandNotification>(_AACS);
}
std::shared_ptr<ICommandNotification> operation::getADCS(void){

    return std::static_pointer_cast<ICommandNotification>(_ADCS);
}
std::shared_ptr<ICommandNotification> operation::getSPCS(void){

    return std::static_pointer_cast<ICommandNotification>(_SPCS);
}
std::shared_ptr<ICommandNotification> operation::getQDCS(void){

    return std::static_pointer_cast<ICommandNotification>(_QDCS);
}
std::shared_ptr<ICommandNotification> operation::getARCS(void){

    return std::static_pointer_cast<ICommandNotification>(_ARCS);
}
std::shared_ptr<ICommandNotification> operation::getANCS(void){

    return std::static_pointer_cast<ICommandNotification>(_ANCS);
}

std::shared_ptr<ICommandNotification> operation::getTICS(void){

    return std::static_pointer_cast<ICommandNotification>(_TICS);
}
std::shared_ptr<ICommandNotification> operation::getTDCS(void){

    return std::static_pointer_cast<ICommandNotification>(_TDCS);
}
std::shared_ptr<IPropertyNotification> operation::getOUS(void){

    return std::static_pointer_cast<IPropertyNotification>(_OUS);
}
void operation::on_pushButton_clicked()
{
    _getCancel->Exec();
}

void operation::hide_animation_add(){
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
void operation::hide_animation_pop(){
    _QP->hide();
//    if(type==4){
//       _SPC->Exec();
//    }
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
void operation::set_Tree(std::shared_ptr<Tree> TC){
    this->_Tree = TC;
}

void operation::set_ptrAAC(std::shared_ptr<ICommandBase> ptr){
    _AAC = ptr;
}
void operation::set_ptrADC(std::shared_ptr<ICommandBase> ptr){
    _ADC = ptr;
}
void operation::set_ptrSPC(std::shared_ptr<ICommandBase> ptr){
    _SPC = ptr;
}
void operation::set_ptrQDC(std::shared_ptr<ICommandBase> ptr){
    _QDC = ptr;
}
void operation::set_ptrARC(std::shared_ptr<ICommandBase> ptr){
    _ARC = ptr;
}
void operation::set_ptrANC(std::shared_ptr<ICommandBase> ptr){
    _ANC = ptr;
}
void operation::set_ptrTIC(std::shared_ptr<ICommandBase> ptr){
    _TIC = ptr;
}
void operation::set_ptrTDC(std::shared_ptr<ICommandBase> ptr){
    _TDC = ptr;
}

void operation::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QFont font = painter.font();
    font.setPixelSize(20);
    painter.setFont(font);
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QColor(245, 233, 227)));
    setPalette(palette);
    if(type==1){
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
    else if(type==2){
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
                    float y1 = 220+80*(h-1);
                    float x2 = 80*(i);
                    float y2 = 220+80*(h-1);
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
    else if(type==4){//only display the top 8 elements
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
    }else if(type==5){
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
    }else if(type==7){
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
}

void operation::on_add_button_clicked()
{
   if(addText->text()==""){
       QMessageBox::warning(this, tr("Waring"),tr("Input can't empty!"),QMessageBox::Yes);
   }
   else{
       if(type==4){
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
           try {
               _AAC->SetParameter(addText->text().toInt());
               _AAC->Exec();
           } catch (const char *msg) {
               QMessageBox::warning(this, tr("Waring"),tr("Input should be integer"),QMessageBox::Yes);
           }
       }
   }
    addText->setText(addText->text()); // convenient for testing
    //addText->setText("");
}

void operation::on_del_button_clicked()
{
    if(delText->text()==""){
        QMessageBox::warning(this, tr("Waring"),tr("Input can't empty!"),QMessageBox::Yes);
    }
    else{
        try {
            //replace test
//            std::vector<int> tt;
//            tt.push_back(addText->text().toInt());
//            tt.push_back(delText->text().toInt());

//            _ARC->SetParameter(tt);
//            _ARC->Exec();
        //New test
//            _ANC->SetParameter(delText->text().toInt());
//            _ANC->Exec();
            _ADC->SetParameter(delText->text().toInt());
            _ADC->Exec();
        } catch (const char *msg) {
            QMessageBox::warning(this, tr("Waring"),tr("Input should be integer"),QMessageBox::Yes);
        }
    }
    delText->setText(delText->text());
}

void operation::on_pushButton_2_clicked()  //pop
{

     if(type==4){
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

void operation::on_deq_button_clicked()  //dequeue
{
    _QDC->Exec();
}

void operation::on_Tins_button_clicked(){
    _TIC->SetParameter(addText->text().toInt());
    _TIC->Exec();
}

void operation::on_Tdel_button_clicked(){
    _TDC->SetParameter(delText->text().toInt());
    _TDC->Exec();
}
