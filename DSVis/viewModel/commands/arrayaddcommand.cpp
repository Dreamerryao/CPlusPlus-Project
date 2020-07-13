#include "arrayaddcommand.h"
#include "../arrayviewmodel.h"
ArrayAddCommand::ArrayAddCommand(ArrayViewModel* ptr)
{
    ptr_AVM= ptr;
}
void ArrayAddCommand::SetParameter(const std::any& param)
{
    oh = std::any_cast<int>(param);
}

void ArrayAddCommand::Exec()
{
    ptr_AVM->_ArrayModel->add(oh);
    ptr_AVM->Fire_OnCommandComplete("ArrayAddCommand", true);
}
