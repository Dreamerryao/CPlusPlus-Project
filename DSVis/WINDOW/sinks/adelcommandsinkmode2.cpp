#include "adelcommandsinkmode2.h"
#include "../model2_main.h"
ADelCommandSinkMode2::ADelCommandSinkMode2(Model2_main *ptr)
{
    _Op = ptr;
}
void ADelCommandSinkMode2::OnCommandComplete(const std::string& str, bool bOK)
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
