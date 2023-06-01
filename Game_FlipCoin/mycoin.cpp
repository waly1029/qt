#include "mycoin.h"

//MyCoin::MyCoin(QWidget *parent)
//    : QWidget{parent}
//{

//}

MyCoin::MyCoin(QString btnImg)
{
    QPixmap pix;
    bool ret = pix.load(btnImg);
    if(!ret) {
        QString str = QString("图片 %1 加载失败").arg(btnImg);
        qDebug() << str;
    }
    this->setFixedSize(pix.width(), pix.height());
    this->setStyleSheet("QPushButton{border: 0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(), pix.height()));

    this->isAnimating = false;
    this->isWin = false;

    this->timer1 = new QTimer(this);
    this->timer2 = new QTimer(this);
    this->min = 1;
    this->max = 8;

    connect(timer1, &QTimer::timeout, this, [=](){
        QPixmap pix;
        QString str = QString(":/res/Coin000%1.png").arg(this->min++);
        pix.load(str);

        this->setFixedSize(pix.width(), pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));

        if(this->min > this->max) {
            this->min = 1;
            timer1->stop();
            this->isAnimating = false;
        }
    });
    connect(timer2, &QTimer::timeout, this, [=](){
        QPixmap pix;
        QString str = QString(":/res/Coin000%1.png").arg(this->max--);
        pix.load(str);

        this->setFixedSize(pix.width(), pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));

        if(this->min > this->max) {
            this->max = 8;
            timer2->stop();
            this->isAnimating = false;
        }
    });
}

void MyCoin::changeFlag() {
    if(this->flag) {
        timer1->start(30);
        this->flag = false;
        this->isAnimating = true;
    }
    else{
        timer2->start(30);
        this->flag = true;
        this->isAnimating = true;
    }
}

void MyCoin::mousePressEvent(QMouseEvent *e) {
    if(this->isAnimating || this->isWin)
        return;
    else
        QPushButton::mousePressEvent(e);
}
