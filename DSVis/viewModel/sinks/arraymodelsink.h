#ifndef ARRAYMODELSINK_H
#define ARRAYMODELSINK_H

#include "../../common/etlbase.h"
class ArrayViewModel;
class ArrayModelSink: public IPropertyNotification
{
public:
    ArrayModelSink(ArrayViewModel* ptr);
    virtual void OnPropertyChanged(const std::string &str) ;
private:
    ArrayViewModel* _AVM;
};

#endif // ARRAYMODELSINK_H
