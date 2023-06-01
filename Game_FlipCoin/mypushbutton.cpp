#include "mypushbutton.h"
#include <QPixmap>
#include <QPropertyAnimation>

//MyPushButton::MyPushButton(QWidget *parent)
//    : QPushButton{parent}
//{

//}
MyPushButton::MyPushButton(QString normalImg, QString pressImg):
    normalImgPath(normalImg),
    pressImgPath(pressImg)
{

    QPixmap pixMap;
    bool ret = pixMap.load(normalImg);
    if(!ret) {
        qDebug() << "load normal image failed.";
        return;
    }

    // set image size
    this->setFixedSize(pixMap.width(), pixMap.height());
    // set 不规则图片样式
    this->setStyleSheet("QPushButton{border: 0px;}");
    this->setIcon(pixMap);
    // set 图标size
    this->setIconSize(QSize(pixMap.width(), pixMap.height()));


}

void MyPushButton::btnUp() {

        setEnabled(false);

        QPropertyAnimation* anim = new QPropertyAnimation(this, "geometry");
        anim->setDuration(200);
        // 起始位置
        anim->setStartValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));
        // 结束位置
        anim->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));
        // 设置弹跳曲线
        anim->setEasingCurve(QEasingCurve::OutBounce);
        // start
        anim->start();

        connect(anim, &QPropertyAnimation::finished, this, [=](){
            setEnabled(true);
        });
}
void MyPushButton::btnDown() {

        setEnabled(false);
        QPropertyAnimation* anim = new QPropertyAnimation(this, "geometry");
        anim->setDuration(200);
        // 起始位置
        anim->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
        // 结束位置
        anim->setEndValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));
        // 设置弹跳曲线
        anim->setEasingCurve(QEasingCurve::OutBounce);
        // start
        anim->start();

        connect(anim, &QPropertyAnimation::finished, this, [=](){
            setEnabled(true);
        });
}

void MyPushButton::mousePressEvent(QMouseEvent *e) {
    if(pressImgPath!="") {
        QPixmap pixMap;
        bool ret = pixMap.load(pressImgPath);
        if(!ret) {
            qDebug() << "load press image failed.";
            return;
        }

        // set image size
        this->setFixedSize(pixMap.width(), pixMap.height());
        // set 不规则图片样式
        this->setStyleSheet("QPushButton{border: 0px;}");
        this->setIcon(pixMap);
        // set 图标size
        this->setIconSize(QSize(pixMap.width(), pixMap.height()));
    }
    // 让父类执行其他操作
    return QPushButton::mousePressEvent(e);
}
void MyPushButton::mouseReleaseEvent(QMouseEvent *e) {
    // 切换成初始图片
    if(pressImgPath!="") {
        QPixmap pixMap;
        bool ret = pixMap.load(normalImgPath);
        if(!ret) {
            qDebug() << "load press image failed.";
            return;
        }

        // set image size
        this->setFixedSize(pixMap.width(), pixMap.height());
        // set 不规则图片样式
        this->setStyleSheet("QPushButton{border: 0px;}");
        this->setIcon(pixMap);
        // set 图标size
        this->setIconSize(QSize(pixMap.width(), pixMap.height()));
    }
    // 让父类执行其他操作
    return QPushButton::mouseReleaseEvent(e);
}
