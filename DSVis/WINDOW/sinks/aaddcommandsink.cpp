#include "aaddcommandsink.h"
#include "../operation.h"
AAddCommandSink::AAddCommandSink(operation *ptr)
{
    _Op = ptr;
}
void AAddCommandSink::OnCommandComplete(const std::string& str, bool bOK)
{
    if(str=="ArrayAddCommand"){
        if(bOK==false){
            QMessageBox MSG;
            MSG.setWindowTitle(QString("error!"));
            MSG.exec();

        }
    }

}

