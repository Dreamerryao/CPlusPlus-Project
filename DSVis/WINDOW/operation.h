#ifndef OPERATION_H
#define OPERATION_H

#include <QMainWindow>
#include"memory"
#include<qpainter.h>
#include "QMouseEvent"
#include"../common/etlbase.h"
#include"../common/ArrayC.h"
#include"../common/Tree.h"
#include "sinks/aaddcommandsink.h"
#include "sinks/adelcommandsink.h"
#include "sinks/spopcommandsink.h"
#include "sinks/qdeqcommandsink.h"
#include "sinks/tinscommandsink.h"
#include "sinks/tdelcommandsink.h"
#include "sinks/anewcommandsink.h"
#include "sinks/opupdatesink.h"
#include "sinks/areplacecommandsink.h"
#include "square.h"
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>


namespace Ui {
class operation;
}

class operation : public QMainWindow
{
    Q_OBJECT

public:
    explicit operation(QWidget *parent = nullptr);
    ~operation();
    void set_Array(std::shared_ptr<ARRAYC> AC);
    std::shared_ptr<ICommandNotification> getAACS(void);
    std::shared_ptr<ICommandNotification> getADCS(void);
    std::shared_ptr<ICommandNotification> getSPCS(void);
    std::shared_ptr<ICommandNotification> getQDCS(void);
    void set_Tree(std::shared_ptr<Tree> TC);
    std::shared_ptr<ICommandNotification> getTICS(void);
    std::shared_ptr<ICommandNotification> getTDCS(void);
    std::shared_ptr<IPropertyNotification> getOUS(void);
    void setCancelCommand(std::shared_ptr<ICommandBase> ptr_cancel);
    void setLabel(const std::string& str);
    void paintEvent(QPaintEvent *);
    void set_ptrAAC(std::shared_ptr<ICommandBase> ptr);
    void set_ptrADC(std::shared_ptr<ICommandBase> ptr);
    void set_ptrSPC(std::shared_ptr<ICommandBase> ptr);
    void set_ptrQDC(std::shared_ptr<ICommandBase> ptr);
    void set_ptrTIC(std::shared_ptr<ICommandBase> ptr);
    void set_ptrTDC(std::shared_ptr<ICommandBase> ptr);
    void set_treeType();
    void show_button();
    void show_TQ();
    int type;

private slots:
    void on_pushButton_clicked();

    void on_add_button_clicked();

    void on_del_button_clicked();

    void on_pushButton_2_clicked();

    void on_deq_button_clicked();

    void on_Tins_button_clicked();

    void on_Tdel_button_clicked();

    void hide_animation_add();
    void hide_animation_pop();


private:
    Ui::operation *ui;
    std::shared_ptr<ICommandBase> _getCancel;
    std::shared_ptr<ARRAYC> _Array;
    std::shared_ptr<Tree> _Tree;
    //Tree _Tree;
    std::shared_ptr<AAddCommandSink> _AACS;
    std::shared_ptr<ADelCommandSink> _ADCS;
    std::shared_ptr<SPopCommandSink> _SPCS;
    std::shared_ptr<QDeqCommandSink> _QDCS;
    std::shared_ptr<TInsCommandSink> _TICS;
    std::shared_ptr<TDelCommandSink> _TDCS;
    std::shared_ptr<OpUpdateSink> _OUS;
    std::shared_ptr<ICommandBase> _AAC;
    std::shared_ptr<ICommandBase> _ADC;
    std::shared_ptr<ICommandBase> _SPC;
    std::shared_ptr<ICommandBase> _QDC;
    std::shared_ptr<ICommandBase> _TIC;
    std::shared_ptr<ICommandBase> _TDC;
    QPushButton *button1;
    QPushButton *button2;
    QLineEdit *addText;
    QLineEdit *delText;
    QVBoxLayout *qb;
    Square *_QP;
};

#endif // OPERATION_H
