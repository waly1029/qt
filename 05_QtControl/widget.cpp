#include "widget.h"
#include "./ui_widget.h"
#include <QListWidgetItem>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // list widget
//    QListWidgetItem* item = new QListWidgetItem("关关雎鸠");
//    // 放入一行list widget
//    ui->listWidget->addItem(item);
//    item->setTextAlignment(Qt::AlignHCenter);
    // 放入多行
    // QStringList List<String>
    QStringList list;
    list << "关关雎鸠" << "窈窕淑女" << "君子好逑";
    ui->listWidget->addItems(list);

}

Widget::~Widget()
{
    delete ui;
}

