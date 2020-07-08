#ifndef TESTBUTTONCOMMAND_H
#define TESTBUTTONCOMMAND_H
#include "../../common/etlbase.h"

class app;
class testButtonCommand: public ICommandBase
{
public:
     testButtonCommand(app *ptr_App);
     ~testButtonCommand(){}
     virtual void SetParameter(const _new_any_space_::any& param){}
     virtual void Exec();
private:
     app* ptrApp;
};

#endif // TESTBUTTONCOMMAND_H
