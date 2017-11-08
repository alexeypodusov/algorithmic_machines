#include "ModelPost.h"

ModelPost::ModelPost(QObject *parent) : ModelBase(parent) {

    cellsList = new QList<bool>();
    for(int i = 0; i<2000; i++) {
        cellsList->append(false);
    }

    commandsList = new QList<PostModelCommand>();
    PostModelCommand command;
    commandsList->append(command);
}

ModelPost::~ModelPost()
{
    cellsList->clear();
    delete cellsList;
    commandsList->clear();
    delete commandsList;
}

int ModelPost::getCurrentCarriage() const
{
    return currentCarriage;
}

void ModelPost::setCurrentCarriage(int value)
{
    if(value >= LEFT_BORDER_TAPE && value <= RIGHT_BORDER_TAPE) {
        currentCarriage = value;
    }
}

bool ModelPost::getMarkByNumberCell(int numCell) {
    int numList = numCell + 1000;
    return cellsList->at(numList);
}


void ModelPost::changeSell(int numCell) {
    int numList = numCell + 1000;
    cellsList->operator [](numList) = !cellsList->at(numList);
}

int ModelPost::getCommandsListSize()
{

    return commandsList->size();
}

PostModelCommand ModelPost::getPostCommand(int numberCommand)
{
    return commandsList->at(numberCommand);
}

void ModelPost::setCommandType(int numberCommand, PostModelCommand::CommandType type)
{
    commandsList->at(numberCommand).commandType = type;
}

void ModelPost::setTransition(int numberCommand, int transition)
{
    commandsList->at(numberCommand).transition = transition;
}

void ModelPost::setSecondTransition(int numberCommand, int transition)
{
    commandsList->at(numberCommand).secondTransition = transition;
}

void ModelPost::setComment(int numberCommand, QString comment)
{
    commandsList->at(numberCommand).comment = comment;
}

void ModelPost::insertCommandString(int numString)
{
    PostModelCommand command;
    command.number = numString;
    commandsList->insert(numString, command);
}

void ModelPost::deleteCommandString(int numString)
{
    commandsList->removeAt(numString);
}
