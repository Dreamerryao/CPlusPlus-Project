#include "tinscommandsink.h"
#include "../operation.h"

TInsCommandSink::TInsCommandSink(operation *ptr)
{
    _Op = ptr;
}

void TInsCommandSink::OnCommandComplete(const std::string& str, bool bOK)
{
    if(str=="TreeInsCommand"){
        if(bOK==false){
            QMessageBox MSG;
            MSG.setWindowTitle(QString("error!"));
            MSG.exec();

        }
    }

}

