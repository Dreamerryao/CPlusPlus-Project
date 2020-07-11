#include "anewcommandsink.h"
#include "../operation.h"
ANewCommandSink::ANewCommandSink(operation *ptr)
{
    _Op = ptr;
}
void ANewCommandSink::OnCommandComplete(const std::string& str, bool bOK)
{
    if(str=="ArrayNewCommand"){
        if(bOK==false){
            QMessageBox MSG;
            MSG.setWindowTitle(QString("error!"));
            MSG.exec();

        }
    }

}
