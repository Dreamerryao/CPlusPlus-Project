#include "tdelcommandsink.h"
#include "../operation.h"
TDelCommandSink::TDelCommandSink(operation *ptr)
{
    _Op = ptr;
}

void TDelCommandSink::OnCommandComplete(const std::string& str, bool bOK)
{
    if(str=="TreeDelCommand"){
        if(bOK==false){
            QMessageBox MSG;
            MSG.setWindowTitle(QString("error!"));
            MSG.setText(QString("Delete failed! \n Tree is empty or the number is not in Tree"));
            MSG.exec();
        }
    }

}
