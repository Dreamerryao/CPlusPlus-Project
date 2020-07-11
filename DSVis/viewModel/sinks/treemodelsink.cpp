#include "treemodelsink.h"
#include "../treeviewmodel.h"

TreeModelSink::TreeModelSink(TreeViewModel *ptr)
{
    _TVM = ptr;
}

void TreeModelSink::OnPropertyChanged(const std::string &str){
    _TVM ->Fire_OnPropertyChanged(str);
}
