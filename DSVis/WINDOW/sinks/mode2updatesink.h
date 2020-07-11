#ifndef OPUPDATESINKMODE2_H
#define OPUPDATESINKMODE2_H
#include"../../common/etlbase.h"
#include "qmessagebox.h"
class Model2_main;
class Mode2UpdateSink: public IPropertyNotification
{
public:
    Mode2UpdateSink(Model2_main *ptr);
    virtual void OnPropertyChanged(const std::string& str);

private:
   Model2_main * _Op;
};
#endif // OPUPDATESINKMODE2_H
