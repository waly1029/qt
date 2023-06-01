#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class student : public QObject
{
    Q_OBJECT
public:
    explicit student(QObject *parent = nullptr);

    // 槽函数
    // 需要声明 需要实现
    // 可以有参数  可以重载
    void treat();

    void treat(QString foodName);
signals:

};

#endif // STUDENT_H
