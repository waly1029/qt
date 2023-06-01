#include "rwidget.h"
#include "ui_rwidget.h"

RWidget::RWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RWidget)
{
    ui->setupUi(this);
}

RWidget::~RWidget()
{
    delete ui;
}
