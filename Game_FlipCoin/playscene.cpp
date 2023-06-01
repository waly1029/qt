#include "playscene.h"
#include <QMenuBar>
#include <QPainter>
#include <QTimer>
#include <QLabel>
#include <QFontDatabase>
#include <QPropertyAnimation>
#include "mypushbutton.h"
#include "mycoin.h"
#include "dataconfig.h"

//PlayScene::PlayScene(QWidget *parent)
//    : QMainWindow{parent}
//{

//}
PlayScene::PlayScene(int levelNum)
{
    QString str = QString("enter scene:%1").arg(levelNum);
    qDebug() << str;
    index = levelNum;

    init();

}

void PlayScene::init() {
    setFixedSize(390, 570);
    setWindowIcon(QPixmap(":/res/Coin0001.png"));
    setWindowTitle("翻金币");

    _setSound();
    _setMenu();
    _setBackBtn();
    _setLevelNum();
    _setCoin();
}

void PlayScene::_setMenu() {
    QMenu* startMenu = menuBar()->addMenu("开始");
    QAction* exitAction = startMenu->addAction("退出");
    connect(exitAction, &QAction::triggered, this, &PlayScene::close);

}

void PlayScene::_setBackBtn() {
    MyPushButton* backBtn = new MyPushButton(":/res/BackButton.png", ":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width() - backBtn->width(), this->height() - backBtn->height());

    connect(backBtn, &MyPushButton::clicked, this, [=](){
        // back btn sound
        backSound->play();
        QTimer::singleShot(500, this, [=](){
            emit this->chooseSceneBack();
        });
    });
}

void PlayScene::_setLevelNum() {
    QLabel* label = new QLabel;
    label->setParent(this);
    QFont font;
//    QFontDatabase database;
//    for(const QString& f: database.families())
//        qDebug() << f;
    font.setFamily("Libian SC");
    font.setPointSize(30);
    QString str = QString("Level: %1").arg(this->index);
    label->setText(str);
    label->setFont(font);
    label->setStyleSheet("QLabel{ color: black; }");
    label->setGeometry(50, this->height()-50, 120 , 50);
}

void PlayScene::_setCoin() {
//    dataConfig dc;
    dataConfig config;
    for(int i=0; i<4; ++i) {
        for(int j=0; j<4; ++j) {
            this->gameArray[i][j] = config.mData[this->index][i][j];
        }
    }
    // 显示胜利图片
    QLabel* winLabel = new QLabel;
    winLabel->setParent(this);
    QPixmap tmpPix;
    tmpPix.load(":/res/LevelCompletedDialogBg.png");
    winLabel->setGeometry(0, 0, tmpPix.width(), tmpPix.height());
    winLabel->setPixmap(tmpPix);
    winLabel->move(QPoint((this->width()-tmpPix.width())*0.5, -tmpPix.height()));

    for(int i=0; i<4; ++i) {
        for(int j=0; j<4; ++j) {
            QLabel* label = new QLabel;
            QPixmap pix(":/res/BoardNode.png");
            label->setGeometry(0,0,pix.width(),pix.height());
            label->setPixmap(pix);
            label->setParent(this);
            label->move((this->width()-4*pix.width())/2+i*pix.width(), 200+j*50);

            // 创建硬币
            QString str;
//            if(dc.mData[this->index][i][j] == 1) {
//                str = QString(":/res/Coin0001.png");
//            }
//            else if(dc.mData[this->index][i][j] == 0)
//                str = QString(":/res/Coin0008.png");

            if(this->gameArray[i][j]==1)
                str = QString(":/res/Coin0001.png");
            else if(this->gameArray[i][j]==0)
                str = QString(":/res/Coin0008.png");
            MyCoin* coin = new MyCoin(str);
            coin->setParent(this);
            coin->move((this->width()-4*pix.width())/2+i*pix.width()+2, 200+j*50+2);
            // 金币属性赋值
            coin->posX = i;
            coin->posY = j;
            coin->flag = this->gameArray[i][j];
            // 将金币放入二维数组
            coinBtn[i][j] = coin;
            // 点击金币翻转
            connect(coin, &MyCoin::clicked, this, [=](){
                // coin flip sound
                coinSound->play();
                // 防止胜利后利用间隙卡bug====全部禁用
                for(int i=0; i<4; ++i){
                    for(int j=0; j<4; ++j){
                        this->coinBtn[i][j]->isWin = true;
                    }
                }
                coin->changeFlag();
                this->gameArray[i][j] = this->gameArray[i][j]==0?1:0;
                // 周围翻转
                QTimer::singleShot(300, this, [=](){
                    if(coin->posX+1 <= 3) // 右侧
                    {
                        coinBtn[coin->posX+1][coin->posY]->changeFlag();
                        this->gameArray[i+1][j] = this->gameArray[i+1][j]==0?1:0;
                    }
                    if(coin->posX-1 >= 0) // 左侧
                    {
                        coinBtn[coin->posX-1][coin->posY]->changeFlag();
                        this->gameArray[i-1][j] = this->gameArray[i-1][j]==0?1:0;
                    }
                    if(coin->posY-1 >= 0) // 上侧
                    {
                        coinBtn[coin->posX][coin->posY-1]->changeFlag();
                        this->gameArray[i][j-1] = this->gameArray[i][j-1]==0?1:0;
                    }
                    if(coin->posY+1 <= 3) // 下侧
                    {
                        coinBtn[coin->posX][coin->posY+1]->changeFlag();
                        this->gameArray[i][j+1] = this->gameArray[i][j+1]==0?1:0;
                    }

                    // 防止胜利后利用间隙卡bug====全部开启
                    for(int i=0; i<4; ++i){
                        for(int j=0; j<4; ++j){
                            this->coinBtn[i][j]->isWin = false;
                        }
                    }

                    // 判断是否胜利
                    this->isWin = true;
                    for(int i=0; i<4; ++i) {
                        for(int j=0; j<4; ++j) {
                            if(coinBtn[i][j]->flag == false) {
                                this->isWin = false;
                                break;
                            }
                        }
                    }

                    if(this->isWin) {
                        qDebug() << "is win";
                        // play win sound
                        winSound->play();
                        for(int i=0; i<4; i++)
                            for(int j=0; j<4; j++)
                                coinBtn[i][j]->isWin = true;
                        // 显示胜利图片
                        QPropertyAnimation* anim = new QPropertyAnimation(winLabel, "geometry");
                        anim->setDuration(1000);
                        // 开始位置
                        anim->setStartValue(QRect(winLabel->x(), winLabel->y(), winLabel->width(), winLabel->height()));
                        // 结束位置
                        anim->setEndValue(QRect(winLabel->x(), winLabel->y()+120, winLabel->width(), winLabel->height()));
                        // 动画曲线
                        anim->setEasingCurve(QEasingCurve::OutBounce);
                        anim->start();
                    }
                });


            });

        }
    }
}

void PlayScene::_setSound() {
    backSound = new QSoundEffect(this);
    backSound->setSource(QUrl::fromLocalFile(":/res/BackButtonSound.wav"));
    winSound = new QSoundEffect(this);
    winSound->setSource(QUrl::fromLocalFile(":/res/LevelWinSound.wav"));
    coinSound = new QSoundEffect(this);
    coinSound->setSource(QUrl::fromLocalFile(":/res/ConFlipSound.wav"));
}
void PlayScene::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    pix.load(":/res/Title.png");
    pix = pix.scaled(pix.width()*.5, pix.height()*.5);
    painter.drawPixmap(10, 30, pix.width(), pix.height(), pix);
}
