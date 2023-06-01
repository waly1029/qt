#include "widget.h"
#include "./ui_widget.h"
#include <QFileDialog>
#include <QFile>
#include <QStringDecoder>
#include <QFileInfo>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->btn, &QPushButton::clicked, this,
        [=](){
            QString path = QFileDialog::getOpenFileName(this, "打开文件", "/Users/liu/Downloads/");
            ui->lineEdit->setText(path);

            // 编码格式
//            QStringDecoder* codec = QStringDecoder::code
            // 读取内容放入textEdit
            // QFile默认支持是utf-8
//            QFile file(path);
//            // 设置打开方式
//            file.open(QIODevice::ReadOnly);
////            QByteArray array = file.readAll();
//            QByteArray array;

//            while(!file.atEnd())
//                array += file.readLine();//按行读取
//            // 放入textEdit
//            ui->textEdit->setText(array);

//            file.close();

//            // 写文件
//            file.open(QIODevice::Append);//追加方式写入
//            file.write("append");
//            file.close();

            // QFileInfo
            QFileInfo info(path);
            qDebug() << info.size();
            qDebug() << info.suffix();
            qDebug() << info.fileName();
            qDebug() << info.filePath();
            qDebug() << info.birthTime().toString("yyyy/MM/dd hh:mm:ss");
            qDebug() << info.lastModified().toString("yyyy/MM/dd hh:mm:ss");
        }
    );
}

Widget::~Widget()
{
    delete ui;
}

