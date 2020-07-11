#ifndef OPUPDATESINK_H
#define OPUPDATESINK_H


#include"../../common/etlbase.h"

class Mode1_display;
class OpUpdateSink: public IPropertyNotification
{
public:
    OpUpdateSink(Mode1_display *ptr);
    virtual void OnPropertyChanged(const std::string& str);

private:
   Mode1_display * _Op;
};


#endif // OPUPDATESINK_H
