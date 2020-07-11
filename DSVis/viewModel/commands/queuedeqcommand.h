#ifndef QUEUEDEQCOMMAND_H
#define QUEUEDEQCOMMAND_H

#include "../../common/etlbase.h"

class ArrayViewModel;
class QueueDeqCommand :public ICommandBase
{
private:
    ArrayViewModel* ptr_AVM;
    int oh;
public:
    QueueDeqCommand(ArrayViewModel* ptr);
    virtual void SetParameter(const _new_any_space_::any &param);
    virtual void Exec() ;
};


#endif // QUEUEDEQCOMMAND_H
