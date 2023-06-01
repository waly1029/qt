#include "chooselevelscene.h"
#include <QMenuBar>
#include <QPainter>
#include <QTimer>
#include <QLabel>
#include <QSoundEffect>

ChooseLevelScene::ChooseLevelScene(QWidget *parent)
    : QMainWindow{parent}
{
    // set scene
    setFixedSize(390, 570);

    // set icon
    setWindowIcon(QPixmap(":/res/Coin0001.png"));

    // set title
    setWindowTitle("选择关卡");

    // set menubar
    QMenu* startMenu = menuBar()->addMenu("开始");

    // 设置menubar颜色
    menuBar()->setStyleSheet("QMenuBar { background-color: rgba(255, 200, 0, 0.5); }");

    // create Exit action
    QAction* actionExit = startMenu->addAction("退出");

    // exit game
    connect(actionExit, &QAction::triggered, this, &ChooseLevelScene::close);

    // select level sound
    QSoundEffect* chooseSound = new QSoundEffect(this);
    chooseSound->setSource(QUrl::fromLocalFile(":/res/TapButtonSound.wav"));
    QSoundEffect* backSound = new QSoundEffect(this);
    backSound->setSource(QUrl::fromLocalFile(":/res/BackButtonSound.wav"));

    // return main scene
    backBtn = new MyPushButton(":/res/BackButton.png", ":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(width()-backBtn->width(), height()-backBtn->height());
    connect(backBtn, &MyPushButton::clicked, this, [=](){
        qDebug() << "back btn clicked.";
        // play back sound
        backSound->play();
        // 切换主场景 需要监听返回按钮
        QTimer::singleShot(500, this, [=](){
            emit chooseSceneBack();
        });
    });

    // 创建选择关卡
    for(int i=0; i<20; ++i) {
        MyPushButton* sceneBtn = new MyPushButton(":/res/LevelIcon.png");
        sceneBtn->setParent(this);
        QPoint p((this->width()-210-sceneBtn->width())/2+i%4*70, 130+i/4*70);
        sceneBtn->move(p);

        // 监听按钮点击事件
        connect(sceneBtn, &MyPushButton::clicked, this, [=](){
            // play sound
            chooseSound->play();

            QString str = QString("scene: %1").arg(i+1);
            qDebug() << str;
            // 进入游戏
            play = new PlayScene(i+1);
            // 固定位置
            play->setGeometry(this->geometry());
            this->hide();
            play->show();

            // 监听游戏场景中的返回
            connect(play, &PlayScene::chooseSceneBack, this, [=](){
//                this->show();
                this->setGeometry(play->geometry());
                delete play;
                this->show();
                play = nullptr;
            });
        });

        QLabel* label = new QLabel;
        label->setParent(this);
        label->setFixedSize(sceneBtn->width(), sceneBtn->height());
        label->setText(QString::number(i+1));
        label->move(p);
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        // 设置鼠标穿透
        label->setAttribute(Qt::WA_TransparentForMouseEvents, true);

    }

    // 监听playscene 信号
}

void ChooseLevelScene::paintEvent(QPaintEvent *event) {
    // set bg
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    // set bg title
    pix.load(":/res/Title.png");
    painter.drawPixmap((width()-pix.width())*0.5, 30, pix.width(), pix.height(), pix);
}
