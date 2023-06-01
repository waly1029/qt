#include "mainscene.h"
#include "./ui_mainscene.h"
#include <QPainter>
#include <QTimer>

MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);

    init();
    connectSignalsAndSlots();
}

void MainScene::init() {
    // 设置main window属性
    setFixedSize(390, 570);
    setWindowTitle("翻金币");
    setWindowIcon(QIcon(":/res/Coin0001.png"));

    // 设置menubar颜色
    ui->menubar->setStyleSheet("QMenuBar { background-color: rgba(255, 200, 0, 0.5); }");

    // set sound
    _setSound();

    // set start button
    _setStartBtn();

    // set chooseScene
    _setChooseScene();
}

void MainScene::_setStartBtn() {
    startBtn = new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(QPoint(width()/2 - startBtn->width()/2, height() - startBtn->height()*1.5));

}

void MainScene::connectSignalsAndSlots() {
    // 退出按钮
    connect(ui->actionExit, &QAction::triggered, this, &MainScene::close);

    // startBtn
    connect(startBtn, &QPushButton::clicked, this, [=](){
//        qDebug() << "start btn clicked.";
        // 播放开始音效
        startSound->play();
        // 弹起特效
        startBtn->btnDown();
        startBtn->btnUp();

        // 延时进入
        QTimer::singleShot(400, this, [=](){
            // 进入choose scene
            // 固定位置
            chooseScene->setGeometry(this->geometry());
            hide();
            chooseScene->show();
        });
    });

    // 监听choosescene发送的信号
    connect(chooseScene, &ChooseLevelScene::chooseSceneBack, this, [=](){
        this->setGeometry(chooseScene->geometry());
        show();
        chooseScene->hide();
    });
}

void MainScene::_setChooseScene() {
    chooseScene = new ChooseLevelScene(this);
}

void MainScene::paintEvent(QPaintEvent *event) {
    // set bg
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    // set bg title
    pix.load(":/res/Title.png");
    // scale 缩放
    pix = pix.scaled(pix.width()*0.5, pix.height()*0.5);
    painter.drawPixmap(10, 30, pix);
}

void MainScene::_setSound() {
    startSound = new QSoundEffect(this);
    startSound->setSource(QUrl::fromLocalFile(":/res/TapButtonSound.wav"));
}

MainScene::~MainScene()
{
    delete ui;
    delete startBtn;
}

