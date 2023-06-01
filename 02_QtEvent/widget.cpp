#include "widget.h"
#include "./ui_widget.h"
#include <QTimer>
#include <QPushButton>
#include <QMouseEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 启动定时器
    timerId1 = startTimer(1000); // 参数1  间隔值 单位毫秒
    timerId2 = startTimer(2000);

    QTimer* t = new QTimer(this);
    t->start(500);
    connect(t, &QTimer::timeout, this, [=](){
        static int num = 0;
        ui->label_4->setText(QString::number(num++));
    });

    connect(ui->btn, &QPushButton::clicked, this, [=](){
        if(t->isActive()) {
            t->stop();
            ui->btn->setText("start");
        }
        else {
            t->start();
            ui->btn->setText("pause");
        }
    });

    ui->label->installEventFilter(this);
}


bool Widget::eventFilter(QObject *watched, QEvent *e) {
    if(watched == ui->label) {
        if(e->type() == QEvent::MouseButtonPress) {
            QMouseEvent* event = static_cast<QMouseEvent*>(e);
            QString str = QString("FILTER: x=%1, y=%2").arg(event->position().x()).arg(event->position().y());
            qDebug() << str;
            return true;
        }
    }
    return QWidget::eventFilter(watched, e);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *event) {
    if(event->timerId() == timerId1) {
        static int num = 1;
        ui->label_2->setText(QString::number(num++));
    }
    else if(event->timerId() == timerId2) {
        static int num2 = 0;
        ui->label_3->setText(QString::number(num2+=2));
    }

//    if(ui->label_2->text() == "10")
//        this->close();
}

