#include "treeinscommand.h"
#include "../treeviewmodel.h"

TreeInsCommand::TreeInsCommand(TreeViewModel* ptr)
{
    ptr_TVM= ptr;
}

void TreeInsCommand::SetParameter(const std::any& param)
{
    oh = std::any_cast<int>(param);
}

void TreeInsCommand::Exec()
{
    ptr_TVM->_TreeModel->ins(oh);
    ptr_TVM->Fire_OnCommandComplete("TreeInsCommand", true);
}

