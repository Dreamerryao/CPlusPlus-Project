#include "treeinscommand.h"
#include "../treeviewmodel.h"

TreeInsCommand::TreeInsCommand(TreeViewModel* ptr)
{
    ptr_TVM= ptr;
}

void TreeInsCommand::SetParameter(const _new_any_space_::any& param)
{
    oh = _new_any_space_::any_cast<int>(param);
}

void TreeInsCommand::Exec()
{
    ptr_TVM->Exec_Tins_command(oh);
    ptr_TVM->Fire_OnCommandComplete("TreeInsCommand", true);
}

