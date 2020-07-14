#ifndef MODEL2_MAIN_H
#define MODEL2_MAIN_H

#include <QWidget>
#include"memory"
#include<qpainter.h>
#include"../common/etlbase.h"
#include"../common/ArrayC.h"
#include"../common/Tree.h"
#include "sinks/mode2_displaycommandsink.h"
#include "sinks/mode2updatesink.h"
namespace Ui {
class Model2_main;
}


class Model2_main : public QWidget
{
    Q_OBJECT

public:
    explicit Model2_main(QWidget *parent = nullptr);
    ~Model2_main();
    void set_Array(const std::shared_ptr<ARRAYC> &AC);
    std::shared_ptr<ICommandNotification> getM2CS(void);
    void set_Tree(const std::shared_ptr<Tree> &TC);
    std::shared_ptr<IPropertyNotification> getM2US(void);

    void getLine();
    void setCancelCommand(const std::shared_ptr<ICommandBase> &ptr_cancel);
    void process_text();
    void paintEvent(QPaintEvent *);
    void set_ptrAAC(const std::shared_ptr<ICommandBase> &ptr);
    void set_ptrADC(const std::shared_ptr<ICommandBase> &ptr);
    void set_ptrSPC(const std::shared_ptr<ICommandBase> &ptr);
    void set_ptrQDC(const std::shared_ptr<ICommandBase> &ptr);
    void set_ptrTIC(const std::shared_ptr<ICommandBase> &ptr);
    void set_ptrTDC(const std::shared_ptr<ICommandBase> &ptr);
    void set_ptrARC(const std::shared_ptr<ICommandBase> &ptr);
    void set_ptrANC(const std::shared_ptr<ICommandBase> &ptr);
    void set_ptrTNC(const std::shared_ptr<ICommandBase> &ptr);
    void set_treeType();
    void set_arrayType();
    int type;
    void paint_array();
    void paint_link();
    void paint_tree();
    void paint_RBT();
    void paint_heap();
    void paint_stack();
    void paint_queue();

private slots:
    void on_text_blockCountChanged(int newBlockCount);

    void on_pushButton_clicked();

private:
    QString _NowCodeText;
    std::string _type;
    std::string _value;
    std::string _op;
    bool _isOK;
    int _a;
    int _b;
    Ui::Model2_main *ui;
    std::shared_ptr<ICommandBase> _getCancel;
    std::shared_ptr<ARRAYC> _Array;
    std::shared_ptr<Tree> _Tree;
    std::shared_ptr<Mode2_displayCommandSink>_M2CS;
    std::shared_ptr<Mode2UpdateSink> _M2US;
    std::shared_ptr<ICommandBase> _AAC;
    std::shared_ptr<ICommandBase> _ADC;
    std::shared_ptr<ICommandBase> _SPC;
    std::shared_ptr<ICommandBase> _QDC;
    std::shared_ptr<ICommandBase> _TIC;
    std::shared_ptr<ICommandBase> _TDC;
    std::shared_ptr<ICommandBase> _ANC;
    std::shared_ptr<ICommandBase> _ARC;
    std::shared_ptr<ICommandBase> _TNC;
};

#endif // MODEL2_MAIN_H
