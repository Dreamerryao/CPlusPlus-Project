#include "treedelcommand.h"
#include "../treeviewmodel.h"
TreeDelCommand::TreeDelCommand(TreeViewModel* ptr)
{
    ptr_TVM= ptr;
}

void TreeDelCommand::SetParameter(const _new_any_space_::any& param)
{
    oh = _new_any_space_::any_cast<int>(param);
}

void TreeDelCommand::Exec()
{
    if(ptr_TVM->Exec_Tdel_command(oh))
    ptr_TVM->Fire_OnCommandComplete("TreeDelCommand", true);
    else
    ptr_TVM->Fire_OnCommandComplete("TreeDelCommand", false);
}

