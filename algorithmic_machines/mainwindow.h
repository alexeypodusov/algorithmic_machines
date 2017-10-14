#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QHBoxLayout>
#include <QListWidget>
#include <QMainWindow>
#include <factories/abstractfactory.h>
#include <ui/Post/postcommandwidget.h>
#include <ui/baseworkareawidget.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    Ui::MainWindow *ui;

    initHardCode();

    AbstractFactory *factory;
    ModelBase *model;

    QList<QSharedPointer<BaseCommandWidget>>* commandWidgetList;
    QList<QSharedPointer<BaseWorkAreaWidget>>* workAreaWidgetList;

};

#endif // MAINWINDOW_H
