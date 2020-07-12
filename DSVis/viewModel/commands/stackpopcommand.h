#ifndef STACKPOPCOMMAND_H
#define STACKPOPCOMMAND_H

#include "../../common/etlbase.h"

class ArrayViewModel;
class StackPopCommand :public ICommandBase
{
private:
    ArrayViewModel* ptr_AVM;
    int oh;
public:
    StackPopCommand(ArrayViewModel* ptr);
    virtual void SetParameter(const std::any &param);
    virtual void Exec() ;
};

#endif // STACKPOPCOMMAND_H
