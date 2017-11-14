#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QHBoxLayout>
#include <QListWidget>
#include <QMainWindow>
#include <factories/AbstractFactory.h>
#include <ui/Post/PostCommandWidget.h>
#include <ui/BaseWorkAreaWidget.h>
#include <QMessageBox>
#include <ui/MessageType.h>
#include <models/ModelBase.h>

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

    void on_pushButtonDeleteString_clicked();

    void on_actionPlay_triggered();

    void receiveMessage(MessageType messageType, QString text, QString title);
    void onChangedStatusPlay(StatusPlay statusPlay);

private:
    Ui::MainWindow *ui;

    void initHardCode();

    AbstractFactory *factory;
    ModelBase *model;

    QList<QSharedPointer<BaseCommandWidget> >* commandWidgetList;
    QList<QSharedPointer<BaseWorkAreaWidget> >* workAreaWidgetList;
};

#endif // MAINWINDOW_H
