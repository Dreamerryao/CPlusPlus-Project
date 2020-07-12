#include "arraydelcommand.h"
#include "../arrayviewmodel.h"

ArrayDelCommand::ArrayDelCommand(ArrayViewModel* ptr)
{
    ptr_AVM= ptr;
}
void ArrayDelCommand::SetParameter(const std::any& param)
{
    oh = std::any_cast<int>(param);
}

void ArrayDelCommand::Exec()
{

    ptr_AVM->Fire_OnCommandComplete("ArrayDelCommand", ptr_AVM->_ArrayModel->del(oh));

}
