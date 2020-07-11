#include "opcommandsink.h"
#include "../mode1_display.h"
OpCommandSink::OpCommandSink(operation *ptr)
{
    _Op = ptr;
}
void OpCommandSink::OnCommandComplete(const std::string& str, bool bOK)
{
    if(str=="ArrayAddCommand"){
        if(bOK==false){
            QMessageBox MSG;
            MSG.setWindowTitle(QString("error!"));
            MSG.exec();

        }
    }
    if(str=="ArrayDelCommand"){
        if(bOK==false){
            QMessageBox MSG;
            MSG.setWindowTitle(QString("error!"));
            MSG.setText(QString("Delete failed! \n Array is empty or the number is not in Array"));
            MSG.exec();
        }
    }
}
