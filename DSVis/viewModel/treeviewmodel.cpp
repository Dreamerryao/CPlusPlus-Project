#include "treeviewmodel.h"
#include "sinks/treemodelsink.h"

TreeViewModel::TreeViewModel()
{
    _TMSink = std::make_shared<TreeModelSink>(this);
    _TIC = std::make_shared<TreeInsCommand>(this);
    _TDC = std::make_shared<TreeDelCommand>(this);
    _TNC = std::make_shared<TreeNewCommand>(this);
}

void TreeViewModel::setTreeModel(const std::shared_ptr<TreeModel> &TM){
    _TreeModel = TM;
    _TreeModel->AddPropertyNotification(std::static_pointer_cast<IPropertyNotification>(_TMSink));
}

std::shared_ptr<Tree> TreeViewModel::getTree(){
    return _TreeModel->getTree();
}

std::shared_ptr<ICommandBase> TreeViewModel::getTreeInsCommand(){
    return std::static_pointer_cast<ICommandBase>(_TIC);
}


std::shared_ptr<ICommandBase> TreeViewModel::getTreeDelCommand(){
    return std::static_pointer_cast<ICommandBase>(_TDC);
}

std::shared_ptr<ICommandBase> TreeViewModel::getTreeNewCommand(){
    return std::static_pointer_cast<ICommandBase>(_TNC);
}
