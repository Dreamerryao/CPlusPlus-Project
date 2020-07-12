#include "queuedeqcommand.h"
#include "../arrayviewmodel.h"

QueueDeqCommand::QueueDeqCommand(ArrayViewModel* ptr)
{
    ptr_AVM= ptr;
}

void QueueDeqCommand::SetParameter(const std::any& param)
{
    oh = std::any_cast<int>(param);
}

void QueueDeqCommand::Exec()
{
    ptr_AVM->Fire_OnCommandComplete("QueueDeqCommand", ptr_AVM->_ArrayModel->deq());

}

