#include "areplacecommandsink.h"
#include "../operation.h"
AReplaceCommandSink::AReplaceCommandSink(operation *ptr)
{
    _Op = ptr;
}
void AReplaceCommandSink::OnCommandComplete(const std::string& str, bool bOK)
{
    if(str=="ArrayReplaceCommand"){
        if(bOK==false){
            QMessageBox MSG;
            MSG.setWindowTitle(QString("error!"));
            MSG.setText(QString("Replace failed! \n Index Error"));
            MSG.exec();
        }
    }

}
