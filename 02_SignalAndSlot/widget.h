#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include "student.h"
#include "teacher.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

    teacher* teac;
    student* stud;

    bool subWinSwitch;

    void classIsOver();
//    void isOpened(QWidget* win, QPushButton* btn);
};
#endif // WIDGET_H
