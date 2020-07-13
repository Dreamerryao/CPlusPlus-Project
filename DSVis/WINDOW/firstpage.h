#ifndef FIRSTPAGE_H
#define FIRSTPAGE_H

#include <QMainWindow>
#include"../common/etlbase.h"
namespace Ui {
class FirstPage;
}

class FirstPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit FirstPage(QWidget *parent = nullptr);
    void set_ptrM1Command(const std::shared_ptr<ICommandBase> &ptrCommand);
    void set_ptrM2Command(const std::shared_ptr<ICommandBase> &ptrCommand);
    void set_ptrAboutCommand(const std::shared_ptr<ICommandBase> &ptrCommand);
    ~FirstPage();

private slots:


    void on_m2_button_clicked();

    void on_about_button_clicked();

    void on_M1_button_clicked();

private:
    Ui::FirstPage *ui;
    std::shared_ptr<ICommandBase> _ptrM1Command;
    std::shared_ptr<ICommandBase> _ptrM2Command;
    std::shared_ptr<ICommandBase> _ptrAboutCommand;
};

#endif // FIRSTPAGE_H
