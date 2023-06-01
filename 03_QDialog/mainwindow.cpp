#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDialog>
#include <QMessageBox>
#include <QColorDialog>
#include <QFileDialog>
#include <QStandardPaths>
#include <QFontDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->menubar->setNativeMenuBar(false);

    connect(ui->actionNew, &QAction::triggered, this, [=](){
        // 两种对话框
        // 1. 非模态对话框
        // 可以对其他窗口进行操作
//        QDialog* dlg2 = new QDialog(this);
//        dlg2->show();
//        // 关闭后释放空间 否则一直在堆上创建
//        dlg2->setAttribute(Qt::WA_DeleteOnClose);
//        qDebug() << "模态对话框弹出";


        // 2. 模态对话框
        // 不可以对其他窗口进行操作
        // 创建对话框
//        QDialog dlg(this);
//        dlg.resize(200, 100);
//        dlg.exec();
//        // 关闭之后才输出cout  阻塞功能
//        qDebug() << "模态对话框弹出";


        // 3. 消息对话框
        // 错误对话框
//        QMessageBox::critical(this, "Critical", "BAD MAN");

        // 信息对话框
//        QMessageBox::information(this, "info", "Bad Man");
        // 提问对话框
//        if( QMessageBox::Save == QMessageBox::question(this, "Q", "你真的爱她吗", QMessageBox::Save|QMessageBox::Cancel, QMessageBox::Save)) {
//            qDebug() << "爱她";
//        }
        // 警告对话框
//        QMessageBox::warning(this, "warning", "为什么不去");


        // 其他对话框
        // 颜色对话框
//        QColor color = QColorDialog::getColor(QColor(255, 0, 0));
//        qDebug() << color.red() << " " << color.green() << " " << color.blue();
        // 文件对话框
//        QStringList downloadLocations = QStandardPaths::standardLocations(QStandardPaths::DownloadLocation);
//        QString downloadPath = downloadLocations.isEmpty() ? QString() : downloadLocations.first();

//        QString filePath = QFileDialog::getOpenFileName(this, "Open File", "/Users/liu/Downloads/", "*.txt");
//        qDebug() << filePath;

        // 字体对话框
        bool flag;
        QFont font = QFontDialog::getFont(&flag, QFont("华文彩云", 36));
        qDebug() << font.family().toUtf8().data() << " " << font.pointSize() << " " << font.bold() << " " << font.italic();

    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

