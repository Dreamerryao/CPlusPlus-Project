#ifndef M2COMMAND_H
#define M2COMMAND_H
#include "../../common/etlbase.h"

class app;
class M2Command :public ICommandBase
{
private:
    app* ptrApp;
public:
    M2Command(app* ptr_App);
    ~M2Command();
    virtual void SetParameter(const _new_any_space_::any &param);
    virtual void Exec() ;
};

#endif // M2COMMAND_H
