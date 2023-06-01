#include "widget.h"
#include "./ui_widget.h"

#include <QPushButton>

// Teacher class
// Student class


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 创建对象
    teac = new teacher(this);
    stud = new student(this);

    QPushButton* btn1 = new QPushButton("关闭", this);
    btn1->resize(100, 50);
    btn1->move(this->width()/2, this->height()/2);
    connect(btn1, &QPushButton::clicked, this, &Widget::close);

    // 链接老师 学生
//    connect(teac, &teacher::hungry, stud, &student::treat);
    // 调用下课
//    classIsOver();

    // 链接有参信号和槽
    // 指针-》地址
    // 函数指针-》函数地址
    void(teacher::*teacherSignal)(QString) = &teacher::hungry;
    void(student::*studentSlot)(QString) = &student::treat;

    connect(teac, teacherSignal, stud, studentSlot);
//    classIsOver();

    // 点击按钮下课
    QPushButton* btn2 = new QPushButton("下课", this);
    btn2->resize(100,50);
//    connect(btn2, &QPushButton::clicked, this, &Widget::classIsOver);

    // 无参信号和槽
    void(teacher::*teacherSignal2)(void) = &teacher::hungry;
    void(student::*studentSlot2)(void) = &student::treat;
    connect(teac, teacherSignal2, stud, studentSlot2);

    //信号连接信号
    connect(btn2, &QPushButton::clicked, teac, teacherSignal2);
//    connect(btn2, &QPushButton::clicked, this, &Widget::close);

    // 断开信号
//    disconnect(teac, teacherSignal2, stud, studentSlot2);

    // 拓展
    // 1. 信号可以连接信号
    // 2. 一个信号可以连接多个槽函数
    // 3. 多个信号可以连接同一个槽函数
    // 4. 信号和槽函数的参数必须一一对应
    // 5. 信号和槽的参数个数  是不是要一致？ 信号的参数个数 可以多于 槽函数的参数个数

    // Qt4版本以前的信号和槽的连接方式
    // 无参版本
    // Qt4 底层SIGNAL("hungry")
//    connect(teac, SIGNAL(hungry()), stud, SLOT(treat()));
    // Qt4优点 参数直观； 缺点 类型不做检查


    // lambda表达式
    // = 所以变量
    // btn2指定了某个变量
//    QPushButton* btn3 = new QPushButton;
//    [btn2](){
//        btn3->setText("NNN"); // btn3 看不见
//        btn2->setText("ABC");
//    }();

//    QPushButton* myBtn = new QPushButton(this);
//    QPushButton* myBtn2 = new QPushButton(this);
//    myBtn2->move(150, 150);
//    int m = 10;
    // mutable 修改拷贝传递的值而不是值的本身
//    connect(myBtn, &QPushButton::clicked, this, [m]()mutable {m=100+10; qDebug()<<m;});
//    connect(myBtn2, &QPushButton::clicked, this, [=]() {qDebug()<<m;});
//    qDebug() << m;

//    int r = []()->int { return 1000; }();
//    qDebug() << r;


    // 利用lambda点击关闭窗口
//    QPushButton* myBtn = new QPushButton("lambda", this);
//    myBtn->move(200, 100);
//    connect(myBtn, &QPushButton::clicked, this, [=](){
////        this->close();
////        Widget::close();
////        emit teac->hungry("sasimi");
//        myBtn->setText("WWWW");
//    });

    // lambda表达式最常用 [=]() {}

    // work
    QPushButton* tBtn = new QPushButton("open", this);
//    QPushButton* tBtn2 = new QPushButton("close", this);
    tBtn->move(550, 550);
//    tBtn2->move(550, 570);
    QWidget* subWin = new QWidget();
    subWinSwitch = false;
    connect(tBtn, &QPushButton::clicked, this, [=](){
        subWinSwitch = !subWinSwitch;
        if(subWinSwitch) {
            qDebug() << "subWin opened...";
            tBtn->setText("close");
            subWin->show();
        }
        else{
            qDebug() << "subWin closed...";
            tBtn->setText("open");
            subWin->close();
        }
//        qDebug() << subWinSwitch;
    });

}


void Widget::classIsOver() {
    // 下课 触发 老师饿
//    emit teac->hungry();
    emit teac->hungry("刺身");
}

Widget::~Widget()
{
    delete ui;
}

