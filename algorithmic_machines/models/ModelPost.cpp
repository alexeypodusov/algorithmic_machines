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

bool ModelPost::setCurrentCarriage(int value)
{
    if(value >= LEFT_BORDER_TAPE && value <= RIGHT_BORDER_TAPE) {
        currentCarriage = value;
        emit cellsListChanded();
        return true;
    }
    return false;
}

bool ModelPost::getMarkByNumberCell(int numCell) {
    int numList = numCell + 1000;
    return cellsList->at(numList);
}


void ModelPost::changeSell(int numCell) {
    int numList = numCell + 1000;
    cellsList->operator [](numList) = !cellsList->at(numList);
    emit cellsListChanded();
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

bool ModelPost::checkValidationCommand(int numberCommand)
{
    if (commandsList->at(numberCommand).commandType
            == PostModelCommand::CommandType::NULL_COMMAND) {
          emit sendMessage(MessageType::MESSAGE_ERROR, ERROR_NULL_TYPE, ERROR_TITLE);
          return false;
    }
    if (commandsList->at(numberCommand).commandType
            != PostModelCommand::CommandType::STOP) {
        if (!checkTransitionNumber(commandsList->at(numberCommand).transition)) {
            return false;
        }

        if (commandsList->at(numberCommand).commandType
                == PostModelCommand::CommandType::CHECK_MARK)  {
            if (!checkTransitionNumber(commandsList->at(numberCommand).secondTransition)) {
                return false;
            }
        }
    }
}

bool ModelPost::checkTransitionNumber(int numberTransition)
{
    if (numberTransition == -1) {
        emit sendMessage(MessageType::MESSAGE_ERROR, ERROR_TRANSITION_NULL, ERROR_TITLE);
        return false;
    }
    if (numberTransition >= commandsList->size()) {
        emit sendMessage(MessageType::MESSAGE_ERROR, ERROR_TRANSITION_NOT_EXIST, ERROR_TITLE);
        return false;
    }
}

bool ModelPost::executeCommand(int numberCommand)
{
    nextCommand = commandsList->at(numberCommand).transition;

    if (!checkValidationCommand(numberCommand)) {
        return false;
    }

    switch(commandsList->at(numberCommand).commandType)
    {
        case PostModelCommand::CommandType::ADD_MARK: {
            if (!cellsList->at(currentCarriage)) {
                changeSell(currentCarriage);
            } else {
                emit sendMessage(MessageType::MESSAGE_ERROR, ERROR_MARK_TRUE, ERROR_TITLE);
                return false;
            }
            break;
        }
        case PostModelCommand::CommandType::DELETE_MARK: {
            if (cellsList->at(currentCarriage)) {
                changeSell(currentCarriage);
            } else {
                emit sendMessage(MessageType::MESSAGE_ERROR, ERROR_MARK_FALSE, ERROR_TITLE);
                return false;
            }
            break;
        }
        case PostModelCommand::CommandType::LEFT_STEP: {
            int newCurrentCarriage = currentCarriage - 1;
            if(!setCurrentCarriage(newCurrentCarriage)) {
                emit sendMessage(MessageType::MESSAGE_ERROR, ERROR_BORDER, ERROR_TITLE);
                return false;
            }
            break;
        }
        case PostModelCommand::CommandType::RIGHT_STEP: {
            int newCurrentCarriage = currentCarriage + 1;
            if(!setCurrentCarriage(newCurrentCarriage)) {
                emit sendMessage(MessageType::MESSAGE_ERROR, ERROR_BORDER, ERROR_TITLE);
                return false;
            }
            break;
        }
        case PostModelCommand::CommandType::CHECK_MARK: {
            if (!cellsList->at(currentCarriage)) {
                nextCommand = commandsList->at(numberCommand).secondTransition;
            }
            break;
        }
        case PostModelCommand::CommandType::STOP: {
            sendMessage(MessageType::MESSAGE_INFO, SUCCES_TEXT, SUCCES_TITLE);
            changeStatusPlay(StatusPlay::STOPPED);
            break;
        }
        default: {
            return false;
            break;
        }
    }
    return true;
}
