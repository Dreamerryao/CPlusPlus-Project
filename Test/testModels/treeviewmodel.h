#ifndef TREEVIEWMODEL_H
#define TREEVIEWMODEL_H
#include "treemodel.h"
#include "etlbase.h"


class TreeViewModel:public Proxy_PropertyNotification<TreeViewModel>,
        public Proxy_CommandNotification<TreeViewModel>
{
public:
    TreeViewModel();
    ~TreeViewModel(){}
    void setTreeModel(const std::shared_ptr<TreeModel> &TM);
    std::shared_ptr<Tree> getTree();
    std::shared_ptr<TreeModel> _TreeModel;
private:
};

#endif // TREEVIEWMODEL_H
