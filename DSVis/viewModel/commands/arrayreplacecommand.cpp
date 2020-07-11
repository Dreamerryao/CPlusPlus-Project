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
    std::vector<int> hh = _new_any_space_::any_cast<std::vector<int>>(param);
//    std::string coor = _new_any_space_::any_cast<std::string>(param);
    oh = hh[0];
    newValue = hh[1];
}

void ArrayReplaceCommand::Exec()
{
    if(ptr_AVM->Exec_ARep_command(oh,newValue))
    ptr_AVM->Fire_OnCommandComplete("ArrayReplaceCommand", true);
    else
    ptr_AVM->Fire_OnCommandComplete("ArrayReplaceCommand", false);
}
