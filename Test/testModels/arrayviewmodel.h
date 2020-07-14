#ifndef ARRAYVIEWMODEL_H
#define ARRAYVIEWMODEL_H
#include "arraymodel.h"
#include "etlbase.h"

class ArrayViewModel:public Proxy_PropertyNotification<ArrayViewModel>,
        public Proxy_CommandNotification<ArrayViewModel>
{
public:
    ArrayViewModel();
    ~ArrayViewModel(){}
    void setArrayModel(const std::shared_ptr<ArrayModel> &AM);
    std::shared_ptr<ARRAYC> getArray();
    std::shared_ptr<ArrayModel> _ArrayModel;

private:

};

#endif // ARRAYVIEWMODEL_H
