#include "tinscommandsinkmode2.h"
#include "../model2_main.h"

TInsCommandSinkMode2::TInsCommandSinkMode2(Model2_main *ptr)
{
    _Op = ptr;
}

void TInsCommandSinkMode2::OnCommandComplete(const std::string& str, bool bOK)
{
    if(str=="TreeInsCommand"){
        if(bOK==false){
            QMessageBox MSG;
            MSG.setWindowTitle(QString("error!"));
            MSG.exec();

        }
    }

}
