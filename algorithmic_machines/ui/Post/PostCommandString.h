#ifndef POSTCOMMANDSTRING_H
#define POSTCOMMANDSTRING_H

#include <ui/BaseCommandString.h>
#include <models/Post/PostModelCommand.h>
#include <models/ModelPost.h>
#include <QHBoxLayout>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>


class PostCommandString : public BaseCommandString
{
    Q_OBJECT
public:

    const static int HEIGHT_STRING = 20;
    const static int WIDTH_NUMBER_STRING = 20;
    const static int WIDTH_COMMAND_STRING = 80;
    const static int WIDTH_TRANSITION_STRING = 70;
    const static int WIDTH_COMMENT_STRING = 50;

   explicit PostCommandString(QWidget *parent);
   ~PostCommandString();

   QHBoxLayout* getStringLayout();

   int getNumberString();
   void setNumberString(int number);

   PostCommandType getCommandType();
   void setCommandType(PostCommandType type);

   int getTransition();
   void setTransition(int transition);

   int getSecondTransition();
   void setSecondTransition(int transition);

   QString getComment();
   void setComment(QString comment);

   void setSelect();
   void setDeselected();
private:
   QHBoxLayout *stringLayout;
   QLabel *numberStringLabel;
   QComboBox *commandComboBox;
   QLineEdit *transitionLineEdit;
   QLineEdit *secondTransitionLineEdit;
   QLineEdit *commentLineEdit;

signals:
    void onCommandTypeChangedSignal(int numberString, PostCommandType commandType);
    void onTransitionEditedSignal(int numberString, int transition);
    void onSecondTransitionEditedSignal(int numberString, int transition);
    void onCommentEditedSignal(int numberString, QString comment);
private slots:
    void onCommandTypeChangedSlot(int type);
    void onTransitionEditedSlot();
    void onSecondTransitionEditedSlot();
    void onCommentEditedSlot();
};

#endif // POSTCOMMANDSTRING_H
