#include "mainwindow.h"

#include <QMenuBar>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(800, 600);


    // set 只能有一个
    // add 可以添加多个
    // ================菜单栏==================
    // 菜单栏最多只有一个
    // menu bar
    QMenuBar* bar = menuBar();
    setMenuBar(bar);
    // create menu
    QMenu* fileMenu = bar->addMenu("File");
    QMenu* editMenu = bar->addMenu("Edit");
    bar->setNativeMenuBar(false);
    // menu options
    QAction* actionNew = fileMenu->addAction("New");
    // 添加分隔符
    fileMenu->addSeparator();
    QAction* actionOpen = fileMenu->addAction("Open");
    QAction* actionExit = fileMenu->addAction("Exit");
    connect(actionExit, &QAction::triggered, this, &MainWindow::close);


    // ================工具栏==================
    QToolBar* toolBar = new QToolBar(this);
    // 默认位置
    addToolBar(Qt::BottomToolBarArea, toolBar);
    // 设置移动 总开关
//    toolBar->setMovable(false);
    // 后期设置 只允许 左右拖拽
    toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::BottomToolBarArea | Qt::RightToolBarArea);
    // 设置浮动
    toolBar->setFloatable(false);
    // 设置内容
    toolBar->addAction(actionNew);
    toolBar->addSeparator();
    toolBar->addAction(actionOpen);
    // toolbar 添加控件
    QPushButton* btn1 = new QPushButton("Exit", this);
    toolBar->addWidget(btn1);
    connect(btn1, &QPushButton::clicked, this, &MainWindow::close);


    // ================状态栏==================
    // 最多一个
    QStatusBar* staBar = new QStatusBar();
    setStatusBar(staBar);
    // 标签控件
    QLabel* label = new QLabel("status:", this);
    staBar->addWidget(label);
    QLabel* label2 = new QLabel("right status:", this);
    staBar->addPermanentWidget(label2);

    // ================浮动窗口,可以有多个==================
    QDockWidget* dockWidget = new QDockWidget("Dock1", this);
    addDockWidget(Qt::RightDockWidgetArea, dockWidget);
    // 设置后期停靠区域
    dockWidget->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);
    // 设置中心部件
    // 只能有一个
    QTextEdit* textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);


}

MainWindow::~MainWindow()
{
}

