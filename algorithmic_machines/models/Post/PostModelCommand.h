#ifndef POSTMODELCOMMAND_H
#define POSTMODELCOMMAND_H

#include <QString>

class PostModelCommand
{
public:
    enum class CommandType {
        NULL_COMMAND,
        ADD_MARK,
        DELETE_MARK,
        LEFT_STEP,
        RIGHT_STEP,
        CHECK_MARK,
        STOP
    };

    PostModelCommand();
    ~PostModelCommand();
    PostModelCommand(int number, CommandType commandType, int transtion, int secondTransition, QString comment);

    mutable int number = 0;
    mutable CommandType commandType = CommandType::NULL_COMMAND;
    mutable int transition = -1;
    mutable int secondTransition = -1;
    mutable QString comment = "";
private:

};

#endif // POSTMODELCOMMAND_H
