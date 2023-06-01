#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
//    explicit MyPushButton(QWidget *parent = nullptr);
    explicit MyPushButton(QString normalImg, QString pressImg="");

    // 弹跳效果
    void btnUp();
    void btnDown();

    // press and release event
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

private:
    QString normalImgPath;
    QString pressImgPath;
signals:

};

#endif // MYPUSHBUTTON_H
