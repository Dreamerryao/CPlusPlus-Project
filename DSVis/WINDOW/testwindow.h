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
    //加这个
    void setTestCommand(std::shared_ptr<ICommandBase> ptr_test);
    void setLabel(const std::string& str);
private slots:
    void on_pushButton_clicked();

private:
    Ui::testWindow *ui;
    //加这个
    std::shared_ptr<ICommandBase> _testCommand;
};

#endif // TESTWINDOW_H
