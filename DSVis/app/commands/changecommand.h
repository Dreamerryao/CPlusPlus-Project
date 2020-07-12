#ifndef CHANGECOMMAND_H
#define CHANGECOMMAND_H
#include "../../common/etlbase.h"
#include "../../common/Tree.h"
class app;
class changeCommand :public ICommandBase
{
private:
    app* ptrApp;
public:
    changeCommand(app* ptr_App);
    ~changeCommand();
    virtual void SetParameter(const std::any &param);
    virtual void Exec() ;
};

#endif // CHANGECOMMAND_H
