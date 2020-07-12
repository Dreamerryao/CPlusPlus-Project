#ifndef ARRAYNEWCOMMAND_H
#define ARRAYNEWCOMMAND_H

#include "../../common/etlbase.h"

class ArrayViewModel;
class ArrayNewCommand :public ICommandBase
{
private:
    ArrayViewModel* ptr_AVM;
    int oh;
public:
    ArrayNewCommand(ArrayViewModel* ptr);
    virtual void SetParameter(const std::any &param);
    virtual void Exec() ;
};
#endif // ARRAYNEWCOMMAND_H
