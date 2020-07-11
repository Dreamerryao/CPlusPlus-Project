#ifndef Mode1_display_H
#define Mode1_display_H

#include <QMainWindow>
#include"memory"
#include<qpainter.h>
#include "QMouseEvent"
#include"../common/etlbase.h"
#include"../common/ArrayC.h"
#include"../common/Tree.h"
#include "sinks/mode1_displaycommandsink.h"
#include "sinks/opupdatesink.h"

#include "square.h"
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>


namespace Ui {
class Mode1_display;
}

class Mode1_display : public QMainWindow
{
    Q_OBJECT

public:
    explicit Mode1_display(QWidget *parent = nullptr);
    ~Mode1_display();
    void set_Array(const std::shared_ptr<ARRAYC> &AC);
    std::shared_ptr<ICommandNotification> getM1CS(void);
    void set_Tree(const std::shared_ptr<Tree> &TC);

    std::shared_ptr<IPropertyNotification> getOUS(void);
    void setCancelCommand(const std::shared_ptr<ICommandBase> &ptr_cancel);
    void setLabel(const std::string& str);
    void paintEvent(QPaintEvent *);
    void set_ptrAAC(const std::shared_ptr<ICommandBase> &ptr);
    void set_ptrADC(const std::shared_ptr<ICommandBase> &ptr);
    void set_ptrSPC(const std::shared_ptr<ICommandBase> &ptr);
    void set_ptrQDC(const std::shared_ptr<ICommandBase> &ptr);
    void set_ptrTIC(const std::shared_ptr<ICommandBase> &ptr);
    void set_ptrTDC(const std::shared_ptr<ICommandBase> &ptr);
    void set_treeType();
    void set_arrayType();
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
    Ui::Mode1_display *ui;
    std::shared_ptr<ICommandBase> _getCancel;
    std::shared_ptr<ARRAYC> _Array;
    std::shared_ptr<Tree> _Tree;
    std::shared_ptr<Mode1_displayCommandSink>_M1CS;
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

#endif // Mode1_display_H
