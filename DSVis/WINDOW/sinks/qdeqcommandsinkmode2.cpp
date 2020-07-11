#include "qdeqcommandsinkmode2.h"
#include "../model2_main.h"
QDeqCommandSinkMode2::QDeqCommandSinkMode2(Model2_main *ptr)
{
    _Op = ptr;
}

void QDeqCommandSinkMode2::OnCommandComplete(const std::string& str, bool bOK)
{
    if(str=="QueueDeqCommand"){
        if(bOK==false){
            QMessageBox MSG;
            MSG.setWindowTitle(QString("error!"));
            MSG.setText(QString("Dequeue failed! \n Queue is empty!"));
            MSG.exec();
        }
    }

}
