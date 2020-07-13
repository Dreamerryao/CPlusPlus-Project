#include "stackpopcommand.h"
#include "../arrayviewmodel.h"

StackPopCommand::StackPopCommand(ArrayViewModel* ptr)
{
    ptr_AVM= ptr;
}

void StackPopCommand::SetParameter(const std::any& param)
{
    oh = std::any_cast<int>(param);
}

void StackPopCommand::Exec()
{
    ptr_AVM->Fire_OnCommandComplete("StackPopCommand", ptr_AVM->_ArrayModel->pop());

}
