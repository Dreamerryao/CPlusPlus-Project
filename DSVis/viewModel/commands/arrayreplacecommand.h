#ifndef ARRAYREPLACECOMMAND_H
#define ARRAYREPLACECOMMAND_H


#include "../../common/etlbase.h"

class ArrayViewModel;
class ArrayReplaceCommand :public ICommandBase
{
private:
    ArrayViewModel* ptr_AVM;
    int oh;
    int newValue;
public:
    ArrayReplaceCommand(ArrayViewModel* ptr);
    virtual void SetParameter(const std::any &param);
    virtual void Exec() ;
};

#endif // ARRAYREPLACECOMMAND_H
