#include "arrayreplacecommand.h"
#include "../arrayviewmodel.h"

ArrayReplaceCommand::ArrayReplaceCommand(ArrayViewModel* ptr)
{
    ptr_AVM= ptr;
}
void ArrayReplaceCommand::SetParameter(const _new_any_space_::any& param)
{
    oh = -1;
    newValue = 0;
    std::string coor = _new_any_space_::any_cast<std::string>(param);
    int i = 0;
    //TODO change this
    while (i < coor.size()){
        if(coor[i] >= '0' && coor[i] <= '9'){
            if(oh == -1)
                oh= coor[i] - '0' + 0;
            else
                newValue = coor[i] - '0' + 0;
        }
        else if(coor[i] == ' '){
            ;
        }
        i++;
    }
}

void ArrayReplaceCommand::Exec()
{
    if(ptr_AVM->Exec_ARep_command(oh,newValue))
    ptr_AVM->Fire_OnCommandComplete("ArrayReplaceCommand", true);
    else
    ptr_AVM->Fire_OnCommandComplete("ArrayReplaceCommand", false);
}
