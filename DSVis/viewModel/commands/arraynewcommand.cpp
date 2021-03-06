#include "arraynewcommand.h"
#include "../arrayviewmodel.h"

ArrayNewCommand::ArrayNewCommand(ArrayViewModel* ptr)
{
    ptr_AVM= ptr;
}
void ArrayNewCommand::SetParameter(const std::any& param)
{
    oh = std::any_cast<int>(param);
}

void ArrayNewCommand::Exec()
{
    ptr_AVM->_ArrayModel->Anew(oh);
    ptr_AVM->Fire_OnCommandComplete("ArrayNewCommand", true);
}
