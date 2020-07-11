#include "tdelcommandsinkmode2.h"
#include "../model2_main.h"
TDelCommandSinkMode2::TDelCommandSinkMode2(Model2_main *ptr)
{
    _Op = ptr;
}

void TDelCommandSinkMode2::OnCommandComplete(const std::string& str, bool bOK)
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
