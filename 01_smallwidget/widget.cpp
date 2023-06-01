#include "widget.h"
#include "./ui_widget.h"
#include "smallform.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // get
    connect(ui->btn_get, &QPushButton::clicked, this, [=](){
        qDebug() << ui->widget->getNum();
    });

    // set
    connect(ui->btn_set, &QPushButton::clicked, this, [=](){
        ui->widget->setNum(50);
    });
}

Widget::~Widget()
{
    delete ui;
}

