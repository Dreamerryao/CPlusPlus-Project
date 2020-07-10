#ifndef ARRAYMODEL_H
#define ARRAYMODEL_H
#include "../common/ArrayC.h"
#include <memory>
#include "../common/etlbase.h"

class ArrayModel: public Proxy_PropertyNotification<ArrayModel>, public Proxy_CommandNotification<ArrayModel>
{
public:
    ArrayModel();
    ~ArrayModel(){}
    std::shared_ptr<ARRAYC> getArrayc();
    void add(int a);
    int del(int a);
private:
    std::shared_ptr<ARRAYC> _Array;
};

#endif // ARRAYMODEL_H
