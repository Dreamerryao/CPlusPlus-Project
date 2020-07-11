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

    ptr_AVM->Fire_OnCommandComplete("ArrayDelCommand", ptr_AVM->_ArrayModel->del(oh));

}
