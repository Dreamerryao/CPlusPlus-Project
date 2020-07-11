#include "aaddcommandsinkmode2.h"
#include "../model2_main.h"
AAddCommandSinkMode2::AAddCommandSinkMode2(Model2_main *ptr)
{
    _Op = ptr;
}
void AAddCommandSinkMode2::OnCommandComplete(const std::string& str, bool bOK)
{
    if(str=="ArrayAddCommand"){
        if(bOK==false){
            QMessageBox MSG;
            MSG.setWindowTitle(QString("error!"));
            MSG.exec();

        }
    }

}
