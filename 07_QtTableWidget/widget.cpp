#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // tableWidget
    // 设置列
    ui->tableWidget->setColumnCount(3);
    // 设置水平表头
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"name"<<"sex"<<"age");
    // 设置行数
    ui->tableWidget->setRowCount(5);
    // 设置正文
//    ui->tableWidget->setItem(0, 0, new QTableWidgetItem("King"));
    QStringList nameList;
    nameList << "King" << "Knight" << "Solider" << "Queen" << "Witch";
    QList<QString> sexList;
    sexList << "F" << "F" << "F" << "M" << "M";
    for(int i=0; i<5; ++i) {
        int col = 0;
        ui->tableWidget->setItem(i, col++, new QTableWidgetItem(nameList[i]));
        ui->tableWidget->setItem(i, col++, new QTableWidgetItem(sexList.at(i)));
        ui->tableWidget->setItem(i, col++, new QTableWidgetItem(QString::number(18+i)));
    }
}

Widget::~Widget()
{
    delete ui;
}

