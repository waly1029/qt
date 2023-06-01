#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    ui->actionNew->setIcon(QIcon("None"));
    // 添加Qt资源 : + 前缀名 + 文件名
    ui->actionNew->setIcon(QIcon(":/love_protection_custody_concern_humanity_care_icon.ico"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

