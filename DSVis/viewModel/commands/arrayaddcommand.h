#ifndef ARRAYADDCOMMAND_H
#define ARRAYADDCOMMAND_H

#include "../../common/etlbase.h"

class ArrayViewModel;
class ArrayAddCommand :public ICommandBase
{
private:
    ArrayViewModel* ptr_AVM;
    int oh;
public:
    ArrayAddCommand(ArrayViewModel* ptr);
    virtual void SetParameter(const _new_any_space_::any &param);
    virtual void Exec() ;
};

#endif // ARRAYADDCOMMAND_H
