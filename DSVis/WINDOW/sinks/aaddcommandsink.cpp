#include "aaddcommandsink.h"
#include "../mode1_display.h"
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

