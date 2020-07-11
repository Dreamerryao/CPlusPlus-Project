#ifndef MODEL2_MAIN_H
#define MODEL2_MAIN_H

#include <QWidget>
#include"../common/etlbase.h"
namespace Ui {
class Model2_main;
}

class Model2_main : public QWidget
{
    Q_OBJECT

public:
    explicit Model2_main(QWidget *parent = nullptr);
    ~Model2_main();
    void getLine();
    void setCancelCommand(const std::shared_ptr<ICommandBase> &ptr_cancel);

private slots:
    void on_text_blockCountChanged(int newBlockCount);

    void on_pushButton_clicked();

private:
    QString _NowCodeText;
    Ui::Model2_main *ui;
    std::shared_ptr<ICommandBase> _getCancel;

};

#endif // MODEL2_MAIN_H
