#include "student.h"
#include <QDebug>

student::student(QObject *parent)
    : QObject{parent}
{

}

void student::treat() {
    qDebug() << "请客吃饭";
}

void student::treat(QString foodName) {
    // QString -> char*
    // 先转成QByteArray    .toUtf8()
    // 再转char*           .data()
    qDebug() << "请吃" << foodName.toUtf8().data();
//    qDebug() << "请吃" << foodName;
}
