#ifndef OPERATION_H
#define OPERATION_H

#include <QMainWindow>
#include"../common/etlbase.h"
namespace Ui {
class operation;
}

class operation : public QMainWindow
{
    Q_OBJECT

public:
    explicit operation(QWidget *parent = nullptr);
    ~operation();
    void setCancelCommand(std::shared_ptr<ICommandBase> ptr_cancel);

private slots:
    void on_pushButton_clicked();

private:
    Ui::operation *ui;
    std::shared_ptr<ICommandBase> _getCancel;
};

#endif // OPERATION_H
