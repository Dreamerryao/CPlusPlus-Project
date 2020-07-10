#ifndef M1COMMAND_H
#define M1COMMAND_H
#include "../../common/etlbase.h"

class app;
class M1Command :public ICommandBase
{
private:
    app* ptrApp;
public:
    M1Command(app* ptr_App);
    ~M1Command();
    virtual void SetParameter(const _new_any_space_::any &param);
    virtual void Exec() ;
};

#endif // M1COMMAND_H
