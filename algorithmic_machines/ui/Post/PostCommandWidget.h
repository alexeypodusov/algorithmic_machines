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

    init();

    void addCommandString(int numString);
    void deselectCommand();

    int currentSelectedCommand = -1;

    // BaseCommandWidget interface
    QWidget *getWidget();
    onAddStringClicked();
    onDeleteStringClicked();
    void onChangedStatusPlay(ModelBase::StatusPlay statusPlay);
private slots:
    onCommandTypeChanged(int numberString, PostModelCommand::CommandType type);
    onTransitionEdited(int numberString, int transition);
    onSecondTransitionEdited(int numberString, int transition);
    onCommentEdited(int numberString, QString comment);

    onSelectedCommand(int numberCommand);
};

#endif // POSTCOMMANDWIDGET_H
