#include "anewcommandsink.h"
#include "../model2_main.h"
ANewCommandSink::ANewCommandSink(Model2_main *ptr)
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
