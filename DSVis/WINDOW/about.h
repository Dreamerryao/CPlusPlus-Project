#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>
#include"../common/etlbase.h"
namespace Ui {
class about;
}

class about : public QDialog
{
    Q_OBJECT

public:
    explicit about(QWidget *parent = nullptr);
    ~about();
    void set_ptrCancel(const std::shared_ptr<ICommandBase> &ptrcancel);

private slots:
    void on_cancel_clicked();

private:
    Ui::about *ui;
    std::shared_ptr<ICommandBase> _ptrCancel;
};

#endif // ABOUT_H
