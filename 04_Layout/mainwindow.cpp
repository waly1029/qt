#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    showPwd = false;


    connect(ui->lineEdit_2, &QLineEdit::textChanged, this, [=]() {
        if(ui->lineEdit_2->text() != "")
            ui->pushButton_3->setDisabled(false);
        else
            ui->pushButton_3->setDisabled(true);
    });

    connect(ui->pushButton_3, &QPushButton::clicked, this, [=](){
        if(ui->pushButton_3->isEnabled()) {
            showPwd = !showPwd;
            if(showPwd)
                ui->lineEdit_2->setEchoMode(QLineEdit::Normal);
            else
                ui->lineEdit_2->setEchoMode(QLineEdit::Password);
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

