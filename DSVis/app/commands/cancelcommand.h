#ifndef CANCELCOMMAND_H
#define CANCELCOMMAND_H
#include "../../common/etlbase.h"

class app;
class cancelCommand :public ICommandBase
{
private:
    app* ptrApp;
public:
    cancelCommand(app* ptr_App);
    ~cancelCommand();
    virtual void SetParameter(const _new_any_space_::any &param);
    virtual void Exec() ;
};
#endif // CANCELCOMMAND_H
