#ifndef MODELPOST_H
#define MODELPOST_H

#include "ModelBase.h"
#include <models/Post/PostModelCommand.h>

class ModelPost : public ModelBase
{
    Q_OBJECT
public:
    const static int LEFT_BORDER_TAPE=-999;
    const static int RIGHT_BORDER_TAPE=999;

    ModelPost(QObject *parent = 0);
    ~ModelPost();
    int getCurrentCarriage() const;
    bool setCurrentCarriage(int value);
    bool getMarkByNumberCell(int numCell);

    void changeSell(int numCell);

    int getCommandsListSize();
    PostModelCommand getPostCommand(int numberCommand);

    void setCommandType(int numberCommand, PostModelCommand::CommandType type);
    void setTransition(int numberCommand, int transition);
    void setSecondTransition(int numberCommand, int transition);
    void setComment(int numberCommand, QString comment);

    void insertCommandString(int numString);
    void deleteCommandString(int numString);

    // ModelBase interface
    bool executeCommand(int numberCommand);

signals:
    void cellsListChanded();

private:
    QList<bool> *cellsList;
    QList<PostModelCommand> *commandsList;
    int currentCarriage = 0;
};

#endif // MODELPOST_H
