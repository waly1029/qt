#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include <QSoundEffect>
#include "mycoin.h"

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
//    explicit PlayScene(QWidget *parent = nullptr);
    explicit PlayScene(int);

private:
    int index;
    int gameArray[4][4];

    MyCoin* coinBtn[4][4];
    QSoundEffect* backSound;
    QSoundEffect* winSound;
    QSoundEffect* coinSound;

    void init();
    void paintEvent(QPaintEvent *event);
    void _setMenu();
    void _setBackBtn();
    void _setLevelNum();
    void _setCoin();
    void _setSound();

    // 是否胜利
    bool isWin;
signals:
    // 告诉chooselevelscene
    void chooseSceneBack();
};

#endif // PLAYSCENE_H
