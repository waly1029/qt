#ifndef RWIDGET_H
#define RWIDGET_H

#include <QWidget>

namespace Ui {
class RWidget;
}

class RWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RWidget(QWidget *parent = nullptr);
    ~RWidget();

private:
    Ui::RWidget *ui;
};

#endif // RWIDGET_H
