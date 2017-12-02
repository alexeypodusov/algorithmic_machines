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

class PostCommandWidget : public BaseCommandWidget
{
    Q_OBJECT
public:
    explicit PostCommandWidget(ModelBase *model);
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

    void goToCommandByNumber(int num);

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
    void onSelectedCommand(int numberCommand, int prevCommand);
    void onNumStringClicked(int transitionNum, int senderNum);

};

#endif // POSTCOMMANDWIDGET_H
