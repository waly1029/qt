#include "mainscene.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 禁止使用macOS默认menubar
    QApplication::setAttribute(Qt::AA_DontUseNativeMenuBar);

    MainScene w;
    w.show();
    return a.exec();
}
