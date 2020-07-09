#include "adelcommandsink.h"
#include "../operation.h"
ADelCommandSink::ADelCommandSink(operation *ptr)
{
    _Op = ptr;
}
void ADelCommandSink::OnCommandComplete(const std::string& str, bool bOK)
{
    if(str=="ArrayDelCommand"){
        if(bOK==false){
            QMessageBox MSG;
            MSG.setWindowTitle(QString("error!"));
            MSG.setText(QString("Delete failed! \n Array is empty or the number is not in Array"));
            MSG.exec();
        }
    }

}
