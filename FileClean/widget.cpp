#include "widget.h"
#include "./ui_widget.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QDir>
#include <QTreeView>
#include <QDesktopServices>
#include <QImageReader>
#include <QFileIconProvider>
#include <QSplitter>
#include <QPropertyAnimation>
#include <QDockWidget>
#include <QFileDialog>
#include "rwidget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QString sourceFolderPath = "/Users/liu/Downloads/";
    init(sourceFolderPath);
    showSourceDir(sourceFolderPath);
    connectSignalsAndSlots();
}

void Widget::init(const QString& sourceFolderPath)
{


    fileModel = new QFileSystemModel(this);
    ui->lineEdit_SourcePath->setText(sourceFolderPath);

}

void Widget::showSourceDir(const QString& sourceFolderPath)
{
    fileModel->setRootPath(sourceFolderPath);
    ui->sourceTreeView->setModel(fileModel);
    ui->sourceTreeView->setRootIndex(fileModel->index(sourceFolderPath));
    ui->sourceTreeView->setColumnWidth(0, 200);
    ui->sourceTreeView->setSortingEnabled(true);
    ui->sourceTreeView->setSelectionMode(QAbstractItemView::ExtendedSelection);
}

void Widget::connectSignalsAndSlots()
{
    // 删除选中文件
    connect(ui->btn_del, &QPushButton::clicked, this, &Widget::onDeleteButtonClicked);
    // 显示当前选中文件
    // 如果是图片显示缩略图
    // 如果是视频显示第一帧
    connect(ui->sourceTreeView->selectionModel(), &QItemSelectionModel::selectionChanged, this,
        [=](const QItemSelection& selected, const QItemSelection& deselected){
            if(!selected.isEmpty()){
                QModelIndex selectedIndex = selected.indexes().first();
                QString filePath = fileModel->filePath(selectedIndex);
                viewFile(filePath);
            }
        }
    );

    // 根据路径显示treeview刷新内容
    connect(ui->lineEdit_SourcePath, &QLineEdit::textChanged, this, [=](){
        qDebug() << ui->lineEdit_SourcePath->text();
        QString text = ui->lineEdit_SourcePath->text();
        QDir dir(text);
        if(dir.exists()) {
            fileModel->setRootPath(text);
            ui->sourceTreeView->setRootIndex(fileModel->index(text));
        }
    });

    connect(ui->btn_SourcePath, &QPushButton::clicked, this,[=](){
        QString path = QFileDialog::getExistingDirectory(this, "open file", "/Users/liu/Downloads/");
        ui->lineEdit_SourcePath->setText(path);
    });

}

void Widget::onDeleteButtonClicked()
{
    QItemSelectionModel* selectionModel = ui->sourceTreeView->selectionModel();
    if(selectionModel && fileModel){
        QModelIndexList selectedIndexes = selectionModel->selectedIndexes();

        for(const QModelIndex &index: selectedIndexes) {
            if(index.column()==0) {
                viewFile(fileModel->filePath(index));
                qDebug() << "File deleted" << fileModel->filePath(index);
            }
        }
    }
}


void Widget::viewFile(const QString& filePath) {
    QFileInfo fileInfo(filePath);
    if(fileInfo.isDir())
        return;
    else if(isImgFile(filePath)) {
        QImage image(filePath);
        QPixmap scaledPixmap = QPixmap::fromImage(image).scaled(ui->label_thumbImg->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        ui->label_thumbImg->setPixmap(scaledPixmap);
        ui->label_thumbImg->setAlignment(Qt::AlignCenter);
    }
    else {
        QFileIconProvider iconProvider;
        QIcon icon = iconProvider.icon(fileInfo);
        QList<QSize> availableSizes = icon.availableSizes();
        QPixmap pixmap = icon.pixmap(availableSizes.first());
        ui->label_thumbImg->setPixmap(pixmap);
    }

}


bool Widget::isImgFile(const QString& filePath) {
    QImageReader imgReader(filePath);
    qDebug() << filePath;
    return imgReader.canRead();
}

Widget::~Widget()
{
    delete ui;
}
