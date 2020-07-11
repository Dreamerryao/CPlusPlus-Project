#include "arrayreplacecommand.h"
#include "../arrayviewmodel.h"

ArrayReplaceCommand::ArrayReplaceCommand(ArrayViewModel* ptr)
{
    ptr_AVM= ptr;
}
void ArrayReplaceCommand::SetParameter(const _new_any_space_::any& param)
{
    oh = -1;
    newValue = 0;
    std::vector<int> hh = _new_any_space_::any_cast<std::vector<int>>(param);
    oh = hh[0];
    newValue = hh[1];
}

void ArrayReplaceCommand::Exec()
{
    ptr_AVM->Fire_OnCommandComplete("ArrayReplaceCommand", ptr_AVM->_ArrayModel->replace(oh,newValue));

}
