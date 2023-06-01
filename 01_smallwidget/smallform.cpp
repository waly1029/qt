#include "smallform.h"
#include "ui_smallform.h"

SmallForm::SmallForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SmallForm)
{
    ui->setupUi(this);

    // QSpinBox 移动 QSlider跟着移动
//    connect(ui->doubleSpinBox, &QDoubleSpinBox::valueChanged, this, [=](){
//        ui->horizontalSlider->setValue(ui->doubleSpinBox->value());
//    });
//    connect(ui->horizontalSlider, &QSlider::valueChanged, this, [=](){
//        ui->doubleSpinBox->setValue(ui->horizontalSlider->value());
//    });
    // 6.0 可以不用写函数指针
    // 作为练习
    void(QSpinBox::* spSignal)(int) = &QSpinBox::valueChanged;
    connect(ui->spinBox, spSignal, ui->horizontalSlider, &QSlider::setValue);
    connect(ui->horizontalSlider, &QSlider::valueChanged, ui->spinBox, &QSpinBox::setValue);


}

void SmallForm::setNum(int num) {
    ui->spinBox->setValue(num);
}
int SmallForm::getNum() {
    return ui->spinBox->value();
}

SmallForm::~SmallForm()
{
    delete ui;
}
