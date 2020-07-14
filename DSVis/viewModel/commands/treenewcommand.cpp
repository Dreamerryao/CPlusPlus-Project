#include "treenewcommand.h"
#include "../treeviewmodel.h"

TreeNewCommand::TreeNewCommand(TreeViewModel* ptr)
{
    ptr_TVM= ptr;
}

void TreeNewCommand::SetParameter(const std::any& param)
{
    oh = std::any_cast<int>(param);
}

void TreeNewCommand::Exec()
{
    ptr_TVM->_TreeModel->Tnew();
    ptr_TVM->Fire_OnCommandComplete("TreeNewCommand", true);
}
