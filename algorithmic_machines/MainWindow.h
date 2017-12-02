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
    void receiveMessage(MessageType messageType, QString text, QString title);
    void onChangedStatusPlay(StatusPlay statusPlay);
    void onChangeEnableCommandButtons(bool backEnable, bool forwardEnable);

    void on_pushButtonAddString_clicked();

    void on_pushButtonDeleteString_clicked();

    void on_actionPlay_triggered();

    void on_actionNextStep_triggered();

    void on_actionPause_triggered();

    void on_actionStop_triggered();

    void on_actionReverseStep_triggered();

    void on_backCommandButton_clicked();

    void on_forwardCommandButton_clicked();


private:
    Ui::MainWindow *ui;
    void initHardCode();

    AbstractFactory *factory;
    ModelBase *model;

    QList<QSharedPointer<BaseCommandWidget> >* commandWidgetList;
    QList<QSharedPointer<BaseWorkAreaWidget> >* workAreaWidgetList;

    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

signals:
     void keyPressSignal(QKeyEvent *event);
     void keyReleaseSignal(QKeyEvent *event);
};

#endif // MAINWINDOW_H
