#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class myLabel : public QLabel
{
    Q_OBJECT
public:
    explicit myLabel(QWidget *parent = nullptr);

    // 鼠标进入
    void enterEvent(QEnterEvent *event) override;
    // 鼠标离开
    void leaveEvent(QEvent *event) override;


    // press
    void mousePressEvent(QMouseEvent *event) override;
    // release
    void mouseReleaseEvent(QMouseEvent *event) override;
    // move
    void mouseMoveEvent(QMouseEvent *event) override;

    void timerEvent(QTimerEvent *event) override;

    bool event(QEvent* e) override;

signals:

private:
    int timerId;
};

#endif // MYLABEL_H
