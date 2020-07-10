#ifndef TREEVIEWMODEL_H
#define TREEVIEWMODEL_H
#include "../model/treemodel.h"
#include "../common/etlbase.h"
#include "sinks/treemodelsink.h"
#include "commands/treeinscommand.h"
#include "commands/treedelcommand.h"

class TreeViewModel:public Proxy_PropertyNotification<TreeViewModel>,
        public Proxy_CommandNotification<TreeViewModel>
{
public:
    TreeViewModel();
    ~TreeViewModel(){}
    void setTreeModel(std::shared_ptr<TreeModel> TM);
    std::shared_ptr<Tree> getTree();
    std::shared_ptr<ICommandBase> getTreeInsCommand();
    void Exec_TIns_command(int I);
    std::shared_ptr<ICommandBase> getTreeDelCommand();
    int Exec_TDel_command(int I);
private:
    std::shared_ptr<TreeModel> _TreeModel;
    std::shared_ptr<TreeModelSink> _TMSink;
    std::shared_ptr<TreeInsCommand> _TIC;
    std::shared_ptr<TreeDelCommand> _TDC;
};

#endif // TREEVIEWMODEL_H
