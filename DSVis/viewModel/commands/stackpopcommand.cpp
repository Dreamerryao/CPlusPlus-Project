#include "stackpopcommand.h"
#include "../arrayviewmodel.h"

StackPopCommand::StackPopCommand(ArrayViewModel* ptr)
{
    ptr_AVM= ptr;
}

void StackPopCommand::SetParameter(const _new_any_space_::any& param)
{
    oh = _new_any_space_::any_cast<int>(param);
}

void StackPopCommand::Exec()
{
    if(ptr_AVM->Exec_Spop_command(oh))
    ptr_AVM->Fire_OnCommandComplete("StackPopCommand", true);
    else
    ptr_AVM->Fire_OnCommandComplete("StackPopCommand", false);
}
