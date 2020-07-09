#ifndef ARRAYDELCOMMAND_H
#define ARRAYDELCOMMAND_H

#include "../../common/etlbase.h"

class ArrayViewModel;
class ArrayDelCommand :public ICommandBase
{
private:
    ArrayViewModel* ptr_AVM;
    int oh;
public:
   ArrayDelCommand(ArrayViewModel* ptr);
    virtual void SetParameter(const _new_any_space_::any &param);
    virtual void Exec() ;
};

#endif // ARRAYDELCOMMAND_H
