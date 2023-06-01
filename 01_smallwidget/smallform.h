#ifndef SMALLFORM_H
#define SMALLFORM_H

#include <QWidget>

namespace Ui {
class SmallForm;
}

class SmallForm : public QWidget
{
    Q_OBJECT

public:
    explicit SmallForm(QWidget *parent = nullptr);
    ~SmallForm();

    void setNum(int num);
    int getNum();
private:
    Ui::SmallForm *ui;
};

#endif // SMALLFORM_H
