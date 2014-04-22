#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect_signals();
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    setBoxSize(300, 300);
    loadBitMap();
}

void MainWindow::setBoxSize(int x, int y)
{
    m_box_x = x;
    m_box_y = y;
    ui->label->setFixedWidth(m_box_x);
    ui->label->setFixedHeight(m_box_y);
}

void MainWindow::loadBitMap()
{
    m_background = new QPixmap(m_box_x, m_box_y);
    m_background->fill();
    draw();
//    paintLine(0,0,11,220,QColor(255, 0, 0).rgb());
//    paintLine(299,299,56,30,QColor(255, 0, 0).rgb());
//    draw();
}

void MainWindow::paintPoint(int x, int y)
{
    QImage tmp = m_background->toImage();
    tmp.setPixel(x, y, QColor(0, 0, 255).rgb());
    m_background->convertFromImage(tmp);
}

void MainWindow::paintLine(int x0, int y0, int x1, int y1, uint color)
{
    QImage tmp = m_background->toImage();
    //Bresenham
    int     dx = abs(x1 - x0),
            dy = abs(y1 - y0),
            sx = (x0 < x1) ? 1 : -1,
            sy = (y0 < y1) ? 1 : -1,
            err = dx - dy,
            e2;
    while(x0 != x1 && y0 != y1) {
        tmp.setPixel(x0, y0, color);
        e2 = 2 * err;
        if(e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if(e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }

    m_background->convertFromImage(tmp);
}

void MainWindow::draw()
{
    ui->label->setPixmap(*m_background);
}

void MainWindow::connect_signals()
{
    QObject::connect(ui->label, SIGNAL(mouseMoved()),
                     this, SLOT(mouseMoved()));
    QObject::connect(ui->label, SIGNAL(mousePressed()),
                     this, SLOT(mousePressed()));
    QObject::connect(ui->label, SIGNAL(mouseLeft()),
                     this, SLOT(mouseLeft()));
}

void MainWindow::mouseMoved()
{
    ui->label_2->setText(QString("x = %1, y = %2")
                         .arg(ui->label->x)
                         .arg(ui->label->y));
}

void MainWindow::mousePressed()
{
    ui->label_2->setText(QString("Pressed"));
}

void MainWindow::mouseLeft()
{
    ui->label_2->setText(QString("Left"));
}
