#include "treemodel.h"
TreeModel::TreeModel()
{
    _Tree = std::make_shared<Tree>();
}

std::shared_ptr<Tree> TreeModel::getTree(){
    return _Tree;
}

void TreeModel::ins(int a){
    _Tree->Ins(a);
    Fire_OnPropertyChanged("TreeModel");
}

int TreeModel::del(int a){
    int res = 0;
    if(!(_Tree->isTreeNull()))
    res = _Tree->Del(a);
    Fire_OnPropertyChanged("TreeModel");
    return res;
}
