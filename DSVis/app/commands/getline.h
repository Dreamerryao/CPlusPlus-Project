#ifndef GETLINE_H
#define GETLINE_H
#include "../../common/etlbase.h"

class app;
class getlineCommand: public ICommandBase
{
public:
     getlineCommand(app *ptr_App);
     ~getlineCommand(){}
     virtual void SetParameter(const _new_any_space_::any& param){}
     virtual void Exec();
private:
     app* ptrApp;
};

#endif // GETLINE_H
