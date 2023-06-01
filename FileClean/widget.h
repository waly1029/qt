#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileSystemModel>
#include <QItemSelectionModel>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    QFileSystemModel* fileModel;
    QItemSelectionModel* selectionModel;

    void connectSignalsAndSlots();
    void viewFile(const QString&);
    void onDeleteButtonClicked();
    void showSourceDir(const QString&);
    void init(const QString&);

    bool isImgFile(const QString&);
};
#endif // WIDGET_H
