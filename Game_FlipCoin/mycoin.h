#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>
#include <QTimer>

class MyCoin : public QPushButton
{
    Q_OBJECT
public:
//    explicit MyCoin(QWidget *parent = nullptr);
    // 显示金币或者银币路径
    MyCoin(QString btnImg);

    int posX;
    int posY;
    bool flag;

    // 改变标志
    void changeFlag();
    QTimer* timer1;  // 正->反
    QTimer* timer2;  // 反->正

    int min;
    int max;

    bool isAnimating;

    // 重写按下
    void mousePressEvent(QMouseEvent *e);

    bool isWin;

signals:

};

#endif // MYCOIN_H
