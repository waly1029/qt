#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include <QSoundEffect>
#include "mypushbutton.h"
#include "chooselevelscene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainScene; }
QT_END_NAMESPACE

class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();

private:
    Ui::MainScene *ui;
    MyPushButton* startBtn;
    ChooseLevelScene* chooseScene;
    QSoundEffect* startSound;

    void init();
    void connectSignalsAndSlots();
    void paintEvent(QPaintEvent *event);
    void _setStartBtn();
    void _setChooseScene();
    void _setSound();
};
#endif // MAINSCENE_H
