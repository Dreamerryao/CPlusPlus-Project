#include "mode2_displaycommandsink.h"
#include "../model2_main.h"
Mode2_displayCommandSink::Mode2_displayCommandSink(Model2_main *ptr)
{
    _Op = ptr;
}
void Mode2_displayCommandSink::OnCommandComplete(const std::string& str, bool bOK)
{
    if(str=="ArrayAddCommand"){
        if(bOK==false){
            QMessageBox MSG;
            MSG.setWindowTitle(QString("error!"));
            MSG.exec();

        }
    }
    else if(str=="ArrayDelCommand"){
        if(bOK==false){
            QMessageBox MSG;
            MSG.setWindowTitle(QString("error!"));
            MSG.setText(QString("Delete failed! \n Array is empty or the number is not in Array"));
            MSG.exec();
        }
    }
    else if(str=="ArrayNewCommand"){
        if(bOK==false){
            QMessageBox MSG;
            MSG.setWindowTitle(QString("error!"));
            MSG.exec();

        }
    }
    else if(str=="QueueDeqCommand"){
        if(bOK==false){
            QMessageBox MSG;
            MSG.setWindowTitle(QString("error!"));
            MSG.setText(QString("Dequeue failed! \n Queue is empty!"));
            MSG.exec();
        }
    }
    else if(str=="StackPopCommand"){
        if(bOK==false){
            QMessageBox MSG;
            MSG.setWindowTitle(QString("error!"));
            MSG.setText(QString("Pop failed! \n Stack is empty!"));
            MSG.exec();
        }
    }
    else if(str=="TreeDelCommand"){
        if(bOK==false){
            QMessageBox MSG;
            MSG.setWindowTitle(QString("error!"));
            MSG.setText(QString("Delete failed! \n Tree is empty or the number is not in Tree"));
            MSG.exec();
        }
    }
    else if(str=="TreeInsCommand"){
        if(bOK==false){
            QMessageBox MSG;
            MSG.setWindowTitle(QString("error!"));
            MSG.exec();

        }
    }
    else if(str=="ArrayReplaceCommand"){
        if(bOK==false){
            QMessageBox MSG;
            MSG.setWindowTitle(QString("error!"));
            MSG.setText(QString("Replace failed! \n Index Error"));
            MSG.exec();
        }
    }
    else if(str=="ArrayNewCommand"){
        if(bOK==false){
            QMessageBox MSG;
            MSG.setWindowTitle(QString("error!"));
            MSG.exec();

        }
    }

}
