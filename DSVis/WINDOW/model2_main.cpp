#include "model2_main.h"
#include "ui_model2_main.h"
#include <sstream>
#include <QTextBlock>
#include <qdebug.h>
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
void Model2_main::set_ptrARC(const std::shared_ptr<ICommandBase> &ptr){
    _ARC = ptr;
}
void Model2_main::set_treeType(){
    _Tree->type = type;
    _Tree->InitialTree();
}

void Model2_main::set_arrayType(){
    if(type==6){
        _Array->type=1;
    }
    else{
        _Array->type=0;
    }
    _Array->InitArrayc();
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
    if(_NowCodeText!=""){
        process_text();
        qDebug() << _isOK <<QString::fromStdString(_op) <<_a<<endl ;
        if(_isOK){
            if(_op=="new"){
                _ANC->SetParameter(_a);
                _ANC->Exec();
            }
            else if(_op=="add"){
                _AAC->SetParameter(_a);
                _AAC->Exec();
            }
            else if(_op=="delete"){
                _ADC->SetParameter(_a);
                _ADC->Exec();
            }
            else if(_op=="replace"){
                   std::vector<int> hh;
                   hh.push_back(_a);
                   hh.push_back(_b);
                   _ARC->SetParameter(hh);
                   _ARC->Exec();
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

                }
                else{
                    _isOK=false;
                }
            }
            else if(res.size()==1){
                pos=res[0].find(".");
                _value=res[0].substr(0,pos);
                std::string rst=res[0].substr(pos+1);
                pos=rst.find("(");
                if(pos==-1){
                    _isOK=false;
                }
                else{
                    _op=rst.substr(0,pos);
                    std::string rt=rst.substr(pos);
                    pos=rt.find(")");
                    if(pos!=rt.length()-1){
                        _isOK=false;
                    }
                    else{
                        rt=rt.substr(1,rt.length()-2);
                    }
                    if(_op=="add"||_op=="delete"){
                        int i;
                        for(i=0;i<rt.length();i++){
                            if(rt[i]<'0'||rt[i]>'9'){
                                _isOK=false;
                            }
                        }
                        _a=atoi(rt.c_str());
                    }
                    else if(_op=="replace"){
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


void Model2_main::paintEvent(QPaintEvent *){
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
        qDebug() << "--cout--" << size<<endl ;
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
//        type = 0;
    }
}
