#ifndef POSTMODELCOMMAND_H
#define POSTMODELCOMMAND_H

#include <QString>
#include <models/Post/PostCommandType.h>

class PostModelCommand
{
public:
    PostModelCommand();
    ~PostModelCommand();
    PostModelCommand(int number, PostCommandType commandType, int transtion, int secondTransition, QString comment);

    mutable int number = 0;
    mutable PostCommandType commandType = NULL_COMMAND;
    mutable int transition = -1;
    mutable int secondTransition = -1;
    mutable QString comment = "";
private:

};

#endif // POSTMODELCOMMAND_H
