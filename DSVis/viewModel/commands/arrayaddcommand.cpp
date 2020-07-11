#include "arrayaddcommand.h"
#include "../arrayviewmodel.h"
ArrayAddCommand::ArrayAddCommand(ArrayViewModel* ptr)
{
    ptr_AVM= ptr;
}
void ArrayAddCommand::SetParameter(const _new_any_space_::any& param)
{
    oh = _new_any_space_::any_cast<int>(param);
}

void ArrayAddCommand::Exec()
{
    ptr_AVM->_ArrayModel->add(oh);
    ptr_AVM->Fire_OnCommandComplete("ArrayAddCommand", true);
}
