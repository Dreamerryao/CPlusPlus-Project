#include "treeviewmodel.h"


TreeViewModel::TreeViewModel()
{
}

void TreeViewModel::setTreeModel(const std::shared_ptr<TreeModel> &TM){
    _TreeModel = TM;
}

std::shared_ptr<Tree> TreeViewModel::getTree(){
    return _TreeModel->getTree();
}


