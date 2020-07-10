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
#include "sinks/opupdatesink.h"
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
    std::shared_ptr<IPropertyNotification> getOUS(void);
    void setCancelCommand(std::shared_ptr<ICommandBase> ptr_cancel);
    void setLabel(const std::string& str);
    void paintEvent(QPaintEvent *);
    void set_ptrAAC(std::shared_ptr<ICommandBase> ptr);
    void set_ptrADC(std::shared_ptr<ICommandBase> ptr);
    void set_ptrSPC(std::shared_ptr<ICommandBase> ptr);
    void set_ptrQDC(std::shared_ptr<ICommandBase> ptr);
    void show_button();
    int type;

private slots:
    void on_pushButton_clicked();

    void on_add_button_clicked();

    void on_del_button_clicked();

    void on_pushButton_2_clicked();

    void on_deq_button_clicked();

private:
    Ui::operation *ui;
    std::shared_ptr<ICommandBase> _getCancel;
    std::shared_ptr<ARRAYC> _Array;
    std::shared_ptr<Tree> _Tree;
    std::shared_ptr<AAddCommandSink> _AACS;
    std::shared_ptr<ADelCommandSink> _ADCS;
    std::shared_ptr<SPopCommandSink> _SPCS;
    std::shared_ptr<QDeqCommandSink> _QDCS;
    std::shared_ptr<OpUpdateSink> _OUS;
    std::shared_ptr<ICommandBase> _AAC;
    std::shared_ptr<ICommandBase> _ADC;
    std::shared_ptr<ICommandBase> _SPC;
    std::shared_ptr<ICommandBase> _QDC;
    QPushButton *button1;
    QPushButton *button2;
    QLineEdit *addText;
    QLineEdit *delText;
    QVBoxLayout *qb;
};

#endif // OPERATION_H
