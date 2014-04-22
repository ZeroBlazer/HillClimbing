#include "myqlabel.h"

myQLabel::myQLabel(QWidget *parent) :
    QLabel(parent)
{
    this->setMouseTracking(true);
}

void myQLabel::mouseMoveEvent(QMouseEvent *ev)
{
    x = ev->x();
    y = ev->y();
    emit mouseMoved();
}

void myQLabel::mousePressEvent(QMouseEvent *ev)
{
    emit mousePressed();
}

void myQLabel::leaveEvent(QEvent *ev)
{
    emit mouseLeft();
}
