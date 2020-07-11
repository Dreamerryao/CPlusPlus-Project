#ifndef MODEL1_MAIN_H
#define MODEL1_MAIN_H

#include <QMainWindow>
#include"../common/etlbase.h"
namespace Ui {
class model1_main;
}

class model1_main : public QMainWindow
{
    Q_OBJECT

public:
    explicit model1_main(QWidget *parent = nullptr);
    void setCancelCommand(const std::shared_ptr<ICommandBase> &ptr_cancel);
    void setChangeCommand(const std::shared_ptr<ICommandBase> &ptr_change);
    ~model1_main();
    int type;
    std::string TT;

private slots:
    void on_pushButton_10_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::model1_main *ui;
    std::shared_ptr<ICommandBase> _getCancel;
    std::shared_ptr<ICommandBase> _getChange;
};

#endif // MODEL1_MAIN_H
