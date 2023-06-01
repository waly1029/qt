#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // tree widget
    // 设置水平头部
    ui->treeWidget->setHeaderLabels(QStringList()<<"Hero"<<"Info");
    //
    QTreeWidgetItem* itemStrength = new QTreeWidgetItem(QStringList()<<"Strength");
    // 加载顶层节点
    ui->treeWidget->addTopLevelItem(itemStrength);
    QTreeWidgetItem* itemInt = new QTreeWidgetItem(QStringList()<<"Intellgent");
    // 加载顶层节点
    ui->treeWidget->addTopLevelItem(itemInt);
    QTreeWidgetItem* itemSpeed = new QTreeWidgetItem(QStringList()<<"Speed");
    // 加载顶层节点
    ui->treeWidget->addTopLevelItem(itemSpeed);
    // 子节点
    for(int i=0; i<9; ++i) {
        QStringList info;
        QString hero = "Hero" + QString::number(i+1);
        info << hero;
        QTreeWidgetItem* heroInfo = new QTreeWidgetItem(info<<"Lonnnnnnnnnnnnnnnnnnnnnnng text.");
        int level = i/3;

        if(level==0)
            itemStrength->addChild(heroInfo);
        if(level==1)
            itemInt->addChild(heroInfo);
        if(level==2)
            itemSpeed->addChild(heroInfo);
    }

}

Widget::~Widget()
{
    delete ui;
}

