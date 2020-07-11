#include "mode1_displaycommandsink.h"

#include "../mode1_display.h"
Mode1_displayCommandSink::Mode1_displayCommandSink(Mode1_display *ptr)
{
    _Op = ptr;
}
void Mode1_displayCommandSink::OnCommandComplete(const std::string& str, bool bOK)
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

}
