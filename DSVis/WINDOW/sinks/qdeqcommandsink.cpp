#include "qdeqcommandsink.h"
#include "../operation.h"
QDeqCommandSink::QDeqCommandSink(operation *ptr)
{
    _Op = ptr;
}

void QDeqCommandSink::OnCommandComplete(const std::string& str, bool bOK)
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
