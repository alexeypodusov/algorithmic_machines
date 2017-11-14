#ifndef POSTCOMMANDWIDGET_H
#define POSTCOMMANDWIDGET_H

#include <QHBoxLayout>
#include <QWidget>
#include <ui/BaseCommandWidget.h>
#include <ui/Post/PostCommandString.h>
#include <models/ModelBase.h>
#include <models/ModelPost.h>
#include <QtGui>
#include <QLineEdit>

namespace Ui {
class PostCommandWidget;
}

class PostCommandWidget : public QWidget, BaseCommandWidget
{
    Q_OBJECT

public:
    explicit PostCommandWidget(QWidget *parent, ModelBase *model);
    ~PostCommandWidget();

private:
    ModelPost *model;

    Ui::PostCommandWidget *ui;
    QVBoxLayout *scrollAreaLayout;
    QVBoxLayout *commandStringsLayout;
    QList<QSharedPointer<PostCommandString> > *stringsList;

    void init();

    void addCommandString(int numString);
    void deselectCommand();

    int currentSelectedCommand = -1;

    // BaseCommandWidget interface
    QWidget *getWidget();
    void onAddStringClicked();
    void onDeleteStringClicked();
    void onChangedStatusPlay(StatusPlay statusPlay);
private slots:
    void onCommandTypeChanged(int numberString, PostCommandType type);
    void onTransitionEdited(int numberString, int transition);
    void onSecondTransitionEdited(int numberString, int transition);
    void onCommentEdited(int numberString, QString comment);

    onSelectedCommand(int numberCommand);
};

#endif // POSTCOMMANDWIDGET_H
