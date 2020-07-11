#ifndef TREEMODELSINK_H
#define TREEMODELSINK_H

#include "../../common/etlbase.h"
class TreeViewModel;
class TreeModelSink: public IPropertyNotification
{
public:
    TreeModelSink(TreeViewModel* ptr);
    virtual void OnPropertyChanged(const std::string &str) ;
private:
    TreeViewModel* _TVM;
};

#endif // TREEMODELSINK_H
