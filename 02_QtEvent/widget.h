#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    // 定时器事件
    void timerEvent(QTimerEvent *event) override;


    bool eventFilter(QObject *watched, QEvent *event) override;

private:
    Ui::Widget *ui;
    int timerId1;
    int timerId2;
};
#endif // WIDGET_H
