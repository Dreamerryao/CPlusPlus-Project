#include "model2_main.h"
#include "ui_model2_main.h"
#include <sstream>
#include <cmath>
#include <QTextBlock>
#include<qpainter.h>
#include <QRect>
Model2_main::Model2_main(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Model2_main)
{
    ui->setupUi(this);
    _M2CS = std::make_shared<Mode2_displayCommandSink>(Mode2_displayCommandSink(this));
    _M2US =  std::make_shared<Mode2UpdateSink>(Mode2UpdateSink(this));
    set_Array(NULL);
    set_Tree(NULL);
}

Model2_main::~Model2_main()
{
    delete ui;
}

std::shared_ptr<ICommandNotification> Model2_main::getM2CS(void){
    return _M2CS;
}

std::shared_ptr<IPropertyNotification> Model2_main::getM2US(void){

    return _M2US;
}

void Model2_main::set_Array(const std::shared_ptr<ARRAYC> &AC){
    this->_Array = AC;
}
void Model2_main::set_Tree(const std::shared_ptr<Tree> &TC){
    this->_Tree = TC;

}


void Model2_main::set_ptrAAC(const std::shared_ptr<ICommandBase> &ptr){
    _AAC = ptr;
}
void Model2_main::set_ptrADC(const std::shared_ptr<ICommandBase> &ptr){
    _ADC = ptr;
}
void Model2_main::set_ptrSPC(const std::shared_ptr<ICommandBase> &ptr){
    _SPC = ptr;
}
void Model2_main::set_ptrQDC(const std::shared_ptr<ICommandBase> &ptr){
    _QDC = ptr;
}

void Model2_main::set_ptrTIC(const std::shared_ptr<ICommandBase> &ptr){
    _TIC = ptr;
}
void Model2_main::set_ptrTDC(const std::shared_ptr<ICommandBase> &ptr){
    _TDC = ptr;
}
void Model2_main::set_ptrANC(const std::shared_ptr<ICommandBase> &ptr){
    _ANC = ptr;
}
void Model2_main::set_ptrTNC(const std::shared_ptr<ICommandBase> &ptr){
    _TNC = ptr;
}
void Model2_main::set_ptrARC(const std::shared_ptr<ICommandBase> &ptr){
    _ARC = ptr;
}
void Model2_main::set_treeType(){
    _Tree->type = type;
    //_Tree->InitialTree();
    //_Tree->newtree();
}

void Model2_main::set_arrayType(){
    if(type==6){
        _Array->type=1;
    }
    else{
        _Array->type=0;
    }
    //_Array->InitArrayc();
    //_Array->takeClear();
}

void Model2_main::on_text_blockCountChanged(int newBlockCount)
{
    getLine();
}

void Model2_main::getLine(){
    QTextDocument* doc=ui->text->document () ;
    int cnt=doc->blockCount ();
    _NowCodeText = doc->findBlockByNumber(cnt-2).text();
     QString displayT = "Processing Code: "+_NowCodeText;
    ui->test->setText(displayT);
    if(_NowCodeText!=""){
        process_text();
        if(_isOK){
            if(_op=="new"){
                if(_type=="array"){
                    set_arrayType();
                    _ANC->SetParameter(_a);
                    _ANC->Exec();
                }
                else if(type>1&&type<7){
                    set_arrayType();
                    _ANC->SetParameter(0);
                    _ANC->Exec();
                }
                else if(type>=7&&type<=9){
                    set_treeType();
                    _TNC->Exec();
                }
            }
            else if(_op=="add"){
                _AAC->SetParameter(_a);
                _AAC->Exec();
            }
            else if(_op=="delete"){
                if(type<7){
                    _ADC->SetParameter(_a);
                    _ADC->Exec();
                }
                else{
                    _TDC->SetParameter(_a);
                    _TDC->Exec();
                }
            }
            else if(_op=="replace"){
                   std::vector<int> hh;
                   hh.push_back(_a);
                   hh.push_back(_b);
                   _ARC->SetParameter(hh);
                   _ARC->Exec();
            }
            else if(_op=="push"){
                _AAC->SetParameter(_a);
                _AAC->Exec();
            }
            else if(_op=="pop"){
                _SPC->Exec();
            }
            else if(_op=="enqueue"){
                _AAC->SetParameter(_a);
                _AAC->Exec();
            }
            else if(_op=="dequeue"){
                _QDC->Exec();
            }
            else if(_op=="deletemin"){
                _QDC->Exec();
            }
            else if(_op=="insert"){
                if(_type=="heap"){
                    _AAC->SetParameter(_a);
                    _AAC->Exec();
                }
                else{
                    _TIC->SetParameter(_a);
                    _TIC->Exec();
                }
            }
        }
        else{
            QMessageBox MSG;
            MSG.setWindowTitle(QString("Warning!"));
            MSG.setText(QString("Your input is illegal"));
            MSG.exec();
        }
    }

    _op = "";
}

void Model2_main::process_text(){
        std::string line = _NowCodeText.toStdString();
        std::vector<std::string> res;
        std::string result;
        _isOK=true; //是否解析成功
//        QString type; //当前操作类型 上述为"Array"
//        QString value;  //当前操作变量  上述为"a"
//        QString op;  //操作类型  "new,add,delete,replace"
        _a = 0;
        _b = 0;
        std::string::size_type pos;
        std::stringstream input(line);

        while(input>>result)
            res.push_back(result);
        if(res.size()>=3){
            _isOK=false;
        }
        else{
            if(res.size()==2){
                _type=res[0];
                _op="new";
                if(_type=="array"){
                    type = 1;
                    pos=res[1].find("[");
//                    cout<<res[1]<<endl;
                    if(pos==-1){
                        _isOK=false;
                    }
                    else{
                        _value=res[1].substr(0,pos);
                        std::string rest;
                        rest=res[1].substr(pos);
                        int last=rest.length();
                        pos=rest.find("]");
                        if(pos!=last-1){
                            _isOK=false;
                        }
                        else{
                            std::string number=rest.substr(1,last-2);
                            int i;
                            for(i=0;i<number.length();i++){
                                if(number[i]<'0'||number[i]>'9'){
                                    _isOK=false;
                                }
                            }
                            _a=atoi(number.c_str());
                        }
                    }
                }
                else if(_type=="link"){
                    type = 2;
                    _value=res[1];
                }
                else if(_type=="stack"){
                    type=4;
                    _value=res[1];
                }
                else if(_type=="queue"){
                    type=5;
                    _value=res[1];
                }
                else if(_type=="heap"){
                    type=6;
                    _value=res[1];
                }
                else if(_type=="BST"){
                    type=7;
                    _value=res[1];
                }
                else if(_type=="AVL"){
                    type=8;
                    _value=res[1];
                }
                else if(_type=="RBT"){
                    type=9;
                    _value=res[1];
                }
                else{
                    _isOK=false;
                }
            }
            else if(res.size()==1){
                pos=res[0].find(".");
                if(pos==0){
                    _isOK=false;
                }
                std::string val;
                val=res[0].substr(0,pos);
                if(_value!=val){
                    _isOK=false;
                }
                std::string rst=res[0].substr(pos+1);
                pos=rst.find("(");
                int flagop=0;
                if(pos==-1){
                    if(rst=="pop"&&_type=="stack"){
                        _op=rst;
                        flagop=1;
                    }
                    else if(rst=="deletemin"&&_type=="heap"){
                        _op=rst;
                        flagop=1;
                    }
                    else if(rst=="dequeue"&&_type=="queue"){
                        _op=rst;
                        flagop=1;
                    }
                    else{
                        _isOK=false;
                    }
                }
                else{
                    _op=rst.substr(0,pos);
                    std::string rt=rst.substr(pos);
                    pos=rt.find(")");
                    if(pos!=rt.length()-1&&flagop==0){
                        _isOK=false;
                    }
                    else{
                        rt=rt.substr(1,rt.length()-2);
                    }
                    if(_op=="add"&&(_type=="array"||_type=="link")){
                        for(int i=0;i<rt.length();i++){
                            if(rt[i]<'0'||rt[i]>'9'){
                                _isOK=false;
                            }
                        }
                        _a=atoi(rt.c_str());
                    }
                    else if(_op=="delete"){
                       //qDebug() <<QString::fromStdString(_type) <<endl ;
                        if(_type=="heap"||_type=="stack"||_type=="queue"){
                            _isOK=false;
                        }
                        for(int i=0;i<rt.length();i++){
                            if(rt[i]<'0'||rt[i]>'9'){
                                _isOK=false;
                            }
                        }
                        _a=atoi(rt.c_str());
                    }
                    else if(_op=="insert"){
                        if(_type=="array"&&_type=="link"&&_type=="queue"&&_type=="stack"){
                            _isOK=false;
                        }
                        for(int i=0;i<rt.length();i++){
                            if(rt[i]<'0'||rt[i]>'9'){
                                _isOK=false;
                            }
                        }
                        _a=atoi(rt.c_str());
                    }
                    else if(_op=="push"&&_type=="stack"){
                        for(int i=0;i<rt.length();i++){
                            if(rt[i]<'0'||rt[i]>'9'){
                                _isOK=false;
                            }
                        }
                        _a=atoi(rt.c_str());
                    }
                    else if(_op=="enqueue"&&_type=="queue"){
                        for(int i=0;i<rt.length();i++){
                            if(rt[i]<'0'||rt[i]>'9'){
                                _isOK=false;
                            }
                        }
                        _a=atoi(rt.c_str());
                    }
                    else if(_op=="replace"){
                        if(_type!="array"){
                            _isOK=false;
                        }
                        std::string number1,number2;
                        pos=rt.find(",");
                        number1=rt.substr(0,pos);
                        number2=rt.substr(pos+1);
                        int i;
                        for(i=0;i<number1.length();i++){
                            if(number1[i]<'0'||number1[i]>'9'){
                                _isOK=false;
                            }
                        }
                        _a=atoi(number1.c_str());
                        for(i=0;i<number2.length();i++){
                            if(number2[i]<'0'||number2[i]>'9'){
                                _isOK=false;
                            }
                        }
                        _b=atoi(number2.c_str());
                    }
                    else{
                        _isOK=false;
                    }
                }
            }
            else{
                _isOK=false;
            }
        }


}

void Model2_main::on_pushButton_clicked()
{
    _getCancel->Exec();
}
void Model2_main::setCancelCommand(const std::shared_ptr<ICommandBase> &ptr_cancel){
    _getCancel=ptr_cancel;
}

void Model2_main::paint_array(){
    QPainter painter(this);
    int i;
    int size =_Array->getSize();
    int h = size/7;
    for(int j=0;j<h;j++){
    for(i=0;i<7;i++){
        int wow = _Array->getNumIndex(i+j*7);
        QRect boundingRect;
        painter.drawText(500 + 80 *i,200+80*j,40,40,Qt::AlignCenter,QString::number(wow),&boundingRect);
        QRectF rectangle(500 + 80 *i, 200+80*j, 40, 40);
        painter.drawRoundedRect(rectangle, 5.0, 5.0);
    }
    }
    for(i=0;i<size%7;i++){
        int wow = _Array->getNumIndex(i+h*7);
        QRect boundingRect;
        painter.drawText(500 + 80 *i,200+80*h,40,40,Qt::AlignCenter,QString::number(wow),&boundingRect);
        QRectF rectangle(500 + 80 *i, 200+80*h, 40, 40);
        painter.drawRoundedRect(rectangle, 5.0, 5.0);
    }
}
void Model2_main::paint_link(){
    QPainter painter(this);
    int i,j;
    int num=0;
    int size =_Array->getSize();
    int h = size/7;
    for(j=0;j<h;j++){
        for(i=0;i<7;i++){
            int wow = _Array->getNumIndex(i+j*7);
            QRect boundingRect;
            painter.drawText(500 + 80 *i,200+80*j,40,40,Qt::AlignCenter,QString::number(wow),&boundingRect);
            QRectF rectangle(500 + 80 *i, 200+80*j, 40, 40);
            painter.drawRoundedRect(rectangle, 5.0, 5.0);
            if(i!=6){
                painter.drawLine(80*(i+1)+460,220+80*j,80*(i+1)+500,220+80*j);
                float x1 = 80*(i+1)+500;
                float y1 = 220+80*j;
                float x2 = 80*(i+1)+460;
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
                painter.drawLine(480,180+80*j,1060,180+80*j);
                painter.drawLine(480,180+80*j,480,220+80*j);
                painter.drawLine(480,220+80*j,500,220+80*j);
                painter.drawLine(1020,140+80*j,1060,140+80*j);
                painter.drawLine(1060,180+80*j,1060,140+80*j);
                float x1 = 80*(i)+500;
                float y1 = 220+80*(h-1);
                float x2 = 80*(i)+460;
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
        painter.drawText(500 + 80 *i,200+80*h,40,40,Qt::AlignCenter,QString::number(wow),&boundingRect);
        QRectF rectangle(500 + 80 *i, 200+80*h, 40, 40);
        painter.drawRoundedRect(rectangle, 5.0, 5.0);
        if(i!=size%7-1){
            painter.drawLine(460+80*(i+1),220+80*h,80*(i+1)+500,220+80*h);
            float x1 = 80*(i+1)+500;
            float y1 = 220+80*h;
            float x2 = 80*(i+1)+460;
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
            painter.drawLine(480,180+80*j,1040,180+80*j);
            painter.drawLine(480,180+80*j,480,220+80*j);
            painter.drawLine(480,220+80*j,500,220+80*j);
            painter.drawLine(480,220+80*j,480,220+80*j);
            painter.drawLine(1020,140+80*j,1040,140+80*j);
            painter.drawLine(1040,180+80*j,1040,140+80*j);
            float x1 = 80*(i)+500;
            float y1 = 220+80*h;
            float x2 = 80*(i)+460;
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
void Model2_main::paint_stack(){
    QPainter painter(this);
    int i;
    int size =_Array->getSize();
    if(size==0){
        painter.drawLine(660,160,660,560);
        painter.drawLine(740,160,740,560);
        painter.drawLine(660,560,740,560);
        float x1 = 740;
        float y1 = 560;
        float x2 = 780;
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
        painter.drawText(785,570,tr("SP"));
    }
    else if(size>8){
        painter.drawLine(660,160,660,560);
        painter.drawLine(740,160,740,560);
        for(i=0;i<8;i++){
            int wow = _Array->getNumIndex(size-8+i);
            QRect boundingRect;
            painter.drawText(680, 510-50*i,40,40,Qt::AlignCenter,QString::number(wow),&boundingRect);
            QRectF rectangle(680, 510-50*i, 40, 40);
            painter.drawRoundedRect(rectangle, 5.0, 5.0);
            if(i==7){
                float x1 = 740;
                float y1 = 510-50*i;
                float x2 = 780;
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
                painter.drawText(785,520-50*i,tr("SP"));
            }
        }
    }
    else{
        painter.drawLine(660,160,660,560);
        painter.drawLine(740,160,740,560);
        painter.drawLine(660,560,740,560);
        for(i=0;i<size;i++){
            int wow = _Array->getNumIndex(i);
            QRect boundingRect;
            painter.drawText(680, 510-50*i,40,40,Qt::AlignCenter,QString::number(wow),&boundingRect);
            QRectF rectangle(680, 510-50*i, 40, 40);
            painter.drawRoundedRect(rectangle, 5.0, 5.0);
            if(i==size-1){
                float x1 = 740;
                float y1 = 510-50*i;
                float x2 = 780;
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
                painter.drawText(785,520-50*i,tr("SP"));
            }
        }
    }
}
void Model2_main::paint_queue(){
    QPainter painter(this);
    int i;
    int size =_Array->getSize();
    painter.drawLine(500,200,1040,200);
    painter.drawLine(500,260,1040,260);
    if(size<12){
        for(i=0;i<size;i++){
            int wow = _Array->getNumIndex(i);
            QRect boundingRect;
            painter.drawText(500+50*i, 210,40,40,Qt::AlignCenter,QString::number(wow),&boundingRect);
            QRectF rectangle(500+50*i, 210, 40, 40);
            painter.drawRoundedRect(rectangle, 5.0, 5.0);
        }
    }else{
        for(i=0;i<5;i++){
            int wow = _Array->getNumIndex(i);
            QRect boundingRect;
            painter.drawText(500+50*i, 210,40,40,Qt::AlignCenter,QString::number(wow),&boundingRect);
            QRectF rectangle(500+50*i, 210, 40, 40);
            painter.drawRoundedRect(rectangle, 5.0, 5.0);
        }
        QRect boundingRect;
        painter.drawText(500+50*5, 210,40,40,Qt::AlignCenter,"...",&boundingRect);
        QRectF rectangle(500+50*5, 210, 40, 40);
        painter.drawRoundedRect(rectangle, 5.0, 5.0);
        int num=6;
        for(i=size-5;i<size;i++){
            int wow = _Array->getNumIndex(i);
            QRect boundingRect;
            painter.drawText(500+50*num, 210,40,40,Qt::AlignCenter,QString::number(wow),&boundingRect);
            QRectF rectangle(500+50*num, 210, 40, 40);
            painter.drawRoundedRect(rectangle, 5.0, 5.0);
            num++;
        }
    }
}
void Model2_main::paint_tree(){
    QPainter painter(this);
    std::vector<node*> queue;
    float xp[40];
    float yp[40];
    int hei[40];
    int cal[7]={0,4,2,1,1,1,1};
    int qhead=0;
    node *root=_Tree->getTree();
    if(root!=NULL){
        queue.push_back(root);
        xp[0]=740;
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
void Model2_main::paint_RBT(){
     QPainter painter(this);
    std::vector<node*> queue;
    float xp[40];
    float yp[40];
    int hei[40];
    int cal[7]={0,4,2,1,1,1,1};
    int qhead=0;
    node *root=_Tree->getTree();
    if(root!=NULL){
        queue.push_back(root);
        xp[0]=740;
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
void Model2_main::paint_heap(){
    QPainter painter(this);
    float xp[40];
    float yp[40];
    int hei[40];
    int cal[7]={4,2,1,1,1,1,1};
    int qf,i;
    int num=_Array->getSize();
    if(num>0){
        xp[1]=740;
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
void Model2_main::paintEvent(QPaintEvent *){
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
