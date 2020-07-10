#ifndef OPUPDATESINK_H
#define OPUPDATESINK_H


#include"../../common/etlbase.h"

class operation;
class OpUpdateSink: public IPropertyNotification
{
public:
    OpUpdateSink(operation *ptr);
    virtual void OnPropertyChanged(const std::string& str);

private:
   operation * _Op;
};


#endif // OPUPDATESINK_H
