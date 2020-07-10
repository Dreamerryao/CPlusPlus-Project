// qgrprogressbar.h
#ifndef QGRPROGRESSBAR_H
#define QGRPROGRESSBAR_H
#include <QGraphicsItem>
#include <QWidget>

class QGRProgressBar : public QWidget//, public QGraphicsRectItem
{
    Q_OBJECT
    Q_PROPERTY(double value
               READ value WRITE setValue
               NOTIFY valueChanged)
public:
    QGRProgressBar(QWidget* parent = 0);

    void setValue(const double& v);
    double value() const;

    virtual void paintEvent(QPaintEvent* event);

signals:
    void valueChanged();

private:
    double m_value;
};

#endif // QGRPROGRESSBAR_H
