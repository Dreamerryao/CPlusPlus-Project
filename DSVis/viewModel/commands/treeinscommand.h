#ifndef TREEINSCOMMAND_H
#define TREEINSCOMMAND_H
#include "../../common/etlbase.h"

class TreeViewModel;
class TreeInsCommand :public ICommandBase
{
private:
    TreeViewModel* ptr_TVM;
    int oh;
public:
    TreeInsCommand(TreeViewModel* ptr);
    virtual void SetParameter(const _new_any_space_::any &param);
    virtual void Exec() ;
};

#endif // TREEINSCOMMAND_H
