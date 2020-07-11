#include "spopcommandsinkmode2.h"
#include "../model2_main.h"
SPopCommandSinkMode2::SPopCommandSinkMode2(Model2_main *ptr)
{
    _Op = ptr;
}

void SPopCommandSinkMode2::OnCommandComplete(const std::string& str, bool bOK)
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
