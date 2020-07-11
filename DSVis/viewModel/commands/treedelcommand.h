#ifndef TREEDELCOMMAND_H
#define TREEDELCOMMAND_H

#include "../../common/etlbase.h"

class TreeViewModel;
class TreeDelCommand :public ICommandBase
{
private:
    TreeViewModel* ptr_TVM;
    int oh;
public:
    TreeDelCommand(TreeViewModel* ptr);
    virtual void SetParameter(const _new_any_space_::any &param);
    virtual void Exec() ;
};

#endif // TREEDELCOMMAND_H


