#ifndef OPERATION_H
#define OPERATION_H

#include <QMainWindow>
#include"memory"
#include<qpainter.h>
#include "QMouseEvent"
#include"../common/etlbase.h"
#include"../common/ArrayC.h"
#include "sinks/opupdatesink.h"
#include "sinks/opcommandsink.h"

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
//    std::shared_ptr<ICommandNotification> getAACS(void);
//    std::shared_ptr<ICommandNotification> getADCS(void);
    std::shared_ptr<ICommandNotification> getOCS(void);
    std::shared_ptr<IPropertyNotification> getOUS(void);
    void setCancelCommand(std::shared_ptr<ICommandBase> ptr_cancel);
    void setLabel(const std::string& str);
    void paintEvent(QPaintEvent *);
    void set_ptrAAC(std::shared_ptr<ICommandBase> ptr);
    void set_ptrADC(std::shared_ptr<ICommandBase> ptr);
    int type;

private slots:
    void on_pushButton_clicked();


    void on_add_button_clicked();

    void on_del_button_clicked();

private:
    Ui::operation *ui;
    std::shared_ptr<ICommandBase> _getCancel;
    std::shared_ptr<ARRAYC> _Array;
//    std::shared_ptr<AAddCommandSink> _AACS;
//    std::shared_ptr<ADelCommandSink> _ADCS;
    std::shared_ptr<OpCommandSink> _OCS;
    std::shared_ptr<OpUpdateSink> _OUS;
    std::shared_ptr<ICommandBase> _AAC;
    std::shared_ptr<ICommandBase> _ADC;
};

#endif // OPERATION_H
