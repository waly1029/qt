#include "widget.h"
#include "./ui_widget.h"
#include <QPainter>
#include <QRect>
#include <QTimer>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QTimer* t = new QTimer(this);
    flag = 1;
    connect(ui->btn, &QPushButton::clicked, this, [=](){
        if(t->isActive()) {
            t->stop();
        } else
            t->start(5);
    });
    connect(t, &QTimer::timeout, this, [=](){
        if(flag==1)
            posX += 1;
        else
            posX -= 1;
        update();
    });
}

void Widget::paintEvent(QPaintEvent *event) {
//    // this 指定的是绘图的设备
//    QPainter painter(this);

//    // 设置画笔
//    QPen pen(QColor(255, 0, 0));
//    pen.setWidth(4);
//    pen.setStyle(Qt::DashLine);
//    painter.setPen(pen);
//    // 画线
//    painter.drawLine(QPoint(0, 0), QPoint(100, 100));
//    // brush
//    QBrush brush(Qt::cyan);
//    brush.setStyle(Qt::Dense7Pattern);
//    painter.setBrush(brush);
//    // 画圆
////    painter.rotate(15);
//    painter.drawEllipse(QPoint(100, 100), 100, 50);
//    // 矩形
//    painter.drawRect(QRect(100, 100, 150, 50));
//    // 文字
//    painter.drawText(QRect(250, 150, 150, 50), "爱");


    //===============================高级设置===================================
//    QPainter painter(this);
//    QPen pen(QColor(255, 0, 0));
//    pen.setWidth(4);
//    painter.setPen(pen);
////    painter.drawEllipse(QPoint(100, 100), 100, 100);
////    // 抗锯齿 效率低
////    painter.setRenderHint(QPainter::Antialiasing, true);
////    painter.drawEllipse(QPoint(200, 100), 100, 100);
//    painter.drawRect(QRect(20, 20, 50, 50));

//    // 画家移动了起始点
//    painter.translate(100, 0);
//    // 保存画家状态
//    painter.save();
//    painter.drawRect(QRect(20, 20, 50, 50));
//    painter.translate(100, 0);
//    // 还原保存状态
//    painter.restore();
//    painter.drawRect(QRect(100, 20, 50, 50));

    // 画资源图片
    QPainter painter(this);
    if(posX > this->width()-128)
        flag = 2;
    else if(posX == 0)
        flag = 1;
    painter.drawPixmap(posX, 20, QPixmap(":/love_protection_custody_concern_humanity_care_icon.ico"));

}

Widget::~Widget()
{
    delete ui;
}

