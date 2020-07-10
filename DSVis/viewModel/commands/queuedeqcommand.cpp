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
    if(ptr_AVM->Exec_Qdeq_command())
    ptr_AVM->Fire_OnCommandComplete("QueueDeqCommand", true);
    else
    ptr_AVM->Fire_OnCommandComplete("QueueDeqCommand", false);
}

