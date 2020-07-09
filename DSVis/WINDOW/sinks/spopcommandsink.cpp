#include "spopcommandsink.h"
#include "../operation.h"

SPopCommandSink::SPopCommandSink(operation *ptr)
{
    _Op = ptr;
}

void SPopCommandSink::OnCommandComplete(const std::string& str, bool bOK)
{
    if(str=="StackPopCommand"){
        if(bOK==false){
            QMessageBox MSG;
            MSG.setWindowTitle(QString("error!"));
            MSG.setText(QString("Pop failed! \n Stack is empty!"));
            MSG.exec();
        }
    }

}
