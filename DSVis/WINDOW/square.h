#ifndef SQUARE_H
#define SQUARE_H
#include <QGraphicsItem>
#include <QWidget>

class Square : public QWidget//, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Square(QWidget* parent = 0);

    virtual void paintEvent(QPaintEvent* event);
    void setValue(int t);
private:
    std::string _Text;
    int m_value;
};

#endif // SQUARE_H
