#ifndef TREENEWCOMMAND_H
#define TREENEWCOMMAND_H
#include "../../common/etlbase.h"

class TreeViewModel;
class TreeNewCommand :public ICommandBase
{
private:
    TreeViewModel* ptr_TVM;
    int oh;
public:
    TreeNewCommand(TreeViewModel* ptr);
    virtual void SetParameter(const std::any &param);
    virtual void Exec() ;
};
#endif // TREENEWCOMMAND_H
