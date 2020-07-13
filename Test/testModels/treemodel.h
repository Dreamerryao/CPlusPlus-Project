#ifndef TREEMODEL_H
#define TREEMODEL_H

#include "Tree.h"
#include <memory>
#include "etlbase.h"

class TreeModel: public Proxy_PropertyNotification<TreeModel>, public Proxy_CommandNotification<TreeModel>
{
public:
    TreeModel();
    ~TreeModel(){}
    std::shared_ptr<Tree> getTree();
    void ins(int a);
    int del(int a);
private:
    std::shared_ptr<Tree> _Tree;
};

#endif // TREEMODEL_H
