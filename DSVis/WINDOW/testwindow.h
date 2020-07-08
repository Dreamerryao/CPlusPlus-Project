#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include <QWidget>
#include"../common/etlbase.h"
namespace Ui {
class testWindow;
}

class testWindow : public QWidget
{
    Q_OBJECT

public:
    explicit testWindow(QWidget *parent = 0);
    ~testWindow();
    void setTestCommand(std::shared_ptr<ICommandBase> ptr_test);
    void setCancelCommand(std::shared_ptr<ICommandBase> ptr_cancel);
    void setLabel(const std::string& str);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::testWindow *ui;
    std::shared_ptr<ICommandBase> _testCommand;
    std::shared_ptr<ICommandBase> _getCancel;
};

#endif // TESTWINDOW_H
