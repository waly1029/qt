#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include "mypushbutton.h"
#include "playscene.h"

class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);

private:
    MyPushButton* backBtn;
    PlayScene* play;

    void paintEvent(QPaintEvent *event);
signals:
    // 自定义信号告诉主场景
    void chooseSceneBack();
};

#endif // CHOOSELEVELSCENE_H
