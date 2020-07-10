#include "arraydelcommand.h"
#include "../arrayviewmodel.h"

ArrayDelCommand::ArrayDelCommand(ArrayViewModel* ptr)
{
    ptr_AVM= ptr;
}
void ArrayDelCommand::SetParameter(const _new_any_space_::any& param)
{
    oh = _new_any_space_::any_cast<int>(param);
}

void ArrayDelCommand::Exec()
{
    if(ptr_AVM->Exec_Adel_command(oh))
    ptr_AVM->Fire_OnCommandComplete("ArrayDelCommand", true);
    else
    ptr_AVM->Fire_OnCommandComplete("ArrayDelCommand", false);
}
