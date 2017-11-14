#include "PostModelCommand.h"

PostModelCommand::PostModelCommand()
{

}

PostModelCommand::~PostModelCommand()
{

}

PostModelCommand::PostModelCommand(int number,
                                   PostCommandType commandType,
                                   int transtion,
                                   int secondTransition,
                                   QString comment)
{
    this->number = number;
    this->commandType = commandType;
    this->transition = transtion;
    this->secondTransition = secondTransition;
    this->comment = comment;
}

