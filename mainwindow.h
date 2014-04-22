#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "myqlabel.h"
#include <QPixmap>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void init();
    void setBoxSize(int x, int y);
    void loadBitMap();
    void paintPoint(int x, int y);
    void paintLine(int x0, int y0, int x1, int y1, uint color);
    void draw();

private:
    void connect_signals();

public slots:
    void mouseMoved();
    void mousePressed();
    void mouseLeft();

private:
    int m_box_x,
        m_box_y;
    QPixmap *m_background;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
