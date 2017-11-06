#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QHBoxLayout>
#include <QListWidget>
#include <QMainWindow>
#include <factories/AbstractFactory.h>
#include <ui/Post/PostCommandWidget.h>
#include <ui/BaseWorkAreaWidget.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void on_pushButtonAddString_clicked();

private:
    Ui::MainWindow *ui;

    initHardCode();

    AbstractFactory *factory;
    ModelBase *model;

    QList<QSharedPointer<BaseCommandWidget> >* commandWidgetList;
    QList<QSharedPointer<BaseWorkAreaWidget> >* workAreaWidgetList;

};

#endif // MAINWINDOW_H
