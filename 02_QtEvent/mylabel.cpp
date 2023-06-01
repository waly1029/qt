#include "mylabel.h"
#include <QMouseEvent>

myLabel::myLabel(QWidget *parent)
    : QLabel{parent}
{
    // 设置鼠标追踪
    setMouseTracking(true);
}

void myLabel::timerEvent(QTimerEvent *event) {
    static int num = 1;
    setText(QString::number(num++));
}

// 鼠标进入
void myLabel::enterEvent(QEnterEvent *event) {
    qDebug() << "enter...";
    timerId = startTimer(1);
}
// 鼠标离开
void myLabel::leaveEvent(QEvent *event) {
    qDebug() << "leave...";
    killTimer(timerId);
}


// move
void myLabel::mouseMoveEvent(QMouseEvent *event) {
    qDebug() << "move";
//    if(event->buttons() & Qt::LeftButton) {
//        QString str = QString("x=%1, y=%2").arg(event->position().x()).arg(event->position().y());
//        QString str2 = QString("x=%1, y=%2").arg(event->globalPosition().x()).arg(event->globalPosition().y());
//        qDebug() << str << str2;
//    }
}
// press
void myLabel::mousePressEvent(QMouseEvent *event) {
    qDebug() << "press";
//    if(event->button() == Qt::LeftButton) {
        QString str = QString("x=%1, y=%2").arg(event->position().x()).arg(event->position().y());
        QString str2 = QString("x=%1, y=%2").arg(event->globalPosition().x()).arg(event->globalPosition().y());
        qDebug() << str << str2;
//    }
}
// release
void myLabel::mouseReleaseEvent(QMouseEvent *event) {
    qDebug() << "release";
}

bool myLabel::event(QEvent* e) {
    // 用户拦截 不建议
    if(e->type() == QEvent::MouseButtonPress) {
        QMouseEvent* event = static_cast<QMouseEvent*>(e);
        QString str = QString("EVENT: x=%1, y=%2").arg(event->position().x()).arg(event->position().y());
        qDebug() << str;
        return true;
    }
    return QLabel::event(e);
}

