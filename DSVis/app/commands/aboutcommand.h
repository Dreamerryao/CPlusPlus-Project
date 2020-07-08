#ifndef ABOUTCOMMAND_H
#define ABOUTCOMMAND_H
#include "../../common/etlbase.h"

class app;
class AboutCommand :public ICommandBase
{
private:
    app* ptrApp;
public:
    AboutCommand(app* ptr_App);
    ~AboutCommand();
    virtual void SetParameter(const _new_any_space_::any &param);
    virtual void Exec() ;
};

#endif // ABOUTCOMMAND_H