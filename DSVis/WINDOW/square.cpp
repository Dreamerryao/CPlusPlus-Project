#include "square.h"

#include <QPainter>
#include <QDebug>

Square::Square(QWidget* parent) :
    QWidget(parent),
    m_value(0)
{

}

void Square::setValue(int t){
    m_value = t;
}
void Square::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QFont font = painter.font();
    font.setPixelSize(20);
    painter.setFont(font);
//    QRectF r(0, 0, 40,40);
    QRect boundingRect;
    painter.drawText(0, 0,40,40,Qt::AlignCenter,QString::number(m_value),&boundingRect);
    QRectF rectangle(0, 0, 40, 40);
    painter.drawRoundedRect(rectangle, 5.0, 5.0);

}
