#include "queuedeqcommand.h"
#include "../arrayviewmodel.h"

QueueDeqCommand::QueueDeqCommand(ArrayViewModel* ptr)
{
    ptr_AVM= ptr;
}

void QueueDeqCommand::SetParameter(const _new_any_space_::any& param)
{
    oh = _new_any_space_::any_cast<int>(param);
}

void QueueDeqCommand::Exec()
{
    ptr_AVM->Fire_OnCommandComplete("QueueDeqCommand", ptr_AVM->_ArrayModel->deq());

}

