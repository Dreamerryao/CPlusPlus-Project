#include "testwidget.h"

// qgrprogressbar.cpp
#include <QPainter>
#include <QDebug>

QGRProgressBar::QGRProgressBar(QWidget* parent) :
    QWidget(parent),
    m_value(0)
{

}

void QGRProgressBar::setValue(const double &v)
{
    m_value = v;
    repaint();
    emit valueChanged();
}

double QGRProgressBar::value() const
{
    return m_value;
}

void QGRProgressBar::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRectF r(0, 0, rect().width()-1, rect().height()-1);
    painter.drawRect(r);

    int i = (double)(rect().height()) / 100 * m_value;
    QRect rv(0, rect().height()-1 - i, rect().width()-1, rect().height()-1);
    painter.fillRect(rv, QColor(255, 0, 0));

}
