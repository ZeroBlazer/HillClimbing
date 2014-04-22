#ifndef MYQLABEL_H
#define MYQLABEL_H

#include <QLabel>
#include <QMouseEvent>
#include <QDebug>
#include <QEvent>

#include <iostream>
using namespace std;

class myQLabel : public QLabel
{
    Q_OBJECT
public:
    explicit myQLabel(QWidget *parent = 0);

    void mouseMoveEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent *ev);
    void leaveEvent(QEvent *ev);

signals:
    void mouseMoved();
    void mousePressed();
    void mouseLeft();

public:
    int x,
        y;
};

#endif // MYQLABEL_H
