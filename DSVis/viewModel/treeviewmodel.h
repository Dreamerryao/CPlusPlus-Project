#ifndef TREEVIEWMODEL_H
#define TREEVIEWMODEL_H
#include "../model/treemodel.h"
#include "../common/etlbase.h"
#include "sinks/treemodelsink.h"
#include "commands/treeinscommand.h"
#include "commands/treedelcommand.h"
#include "commands/treenewcommand.h"

class TreeViewModel:public Proxy_PropertyNotification<TreeViewModel>,
        public Proxy_CommandNotification<TreeViewModel>
{
public:
    TreeViewModel();
    ~TreeViewModel(){}
    void setTreeModel(const std::shared_ptr<TreeModel> &TM);
    std::shared_ptr<Tree> getTree();
    std::shared_ptr<ICommandBase> getTreeInsCommand();
    std::shared_ptr<ICommandBase> getTreeDelCommand();
    std::shared_ptr<ICommandBase> getTreeNewCommand();
    std::shared_ptr<TreeModel> _TreeModel;
private:

    std::shared_ptr<TreeModelSink> _TMSink;
    std::shared_ptr<TreeInsCommand> _TIC;
    std::shared_ptr<TreeDelCommand> _TDC;
    std::shared_ptr<TreeNewCommand> _TNC;
};

#endif // TREEVIEWMODEL_H
