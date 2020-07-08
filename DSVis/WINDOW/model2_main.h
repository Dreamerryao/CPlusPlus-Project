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
    void setGetCommand(std::shared_ptr<ICommandBase> ptr_get);

private slots:
    void on_text_blockCountChanged(int newBlockCount);

private:
    Ui::Model2_main *ui;
    std::shared_ptr<ICommandBase> _getCommand;

};

#endif // MODEL2_MAIN_H
