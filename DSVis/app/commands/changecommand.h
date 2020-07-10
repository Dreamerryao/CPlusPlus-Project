#ifndef CHANGECOMMAND_H
#define CHANGECOMMAND_H
#include "../../common/etlbase.h"

class app;
class changeCommand :public ICommandBase
{
private:
    app* ptrApp;
public:
    changeCommand(app* ptr_App);
    ~changeCommand();
    virtual void SetParameter(const _new_any_space_::any &param);
    virtual void Exec() ;
};

#endif // CHANGECOMMAND_H
