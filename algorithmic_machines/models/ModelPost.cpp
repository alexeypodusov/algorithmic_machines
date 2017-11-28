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

void ModelPost::setCommandType(int numberCommand, PostCommandType type)
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
            == NULL_COMMAND) {
          emit sendMessage(MESSAGE_ERROR, ERROR_NULL_TYPE, ERROR_TITLE);
          return false;
    }
    if (commandsList->at(numberCommand).commandType
            != STOP) {
        if (!checkTransitionNumber(commandsList->at(numberCommand).transition)) {
            return false;
        }

        if (commandsList->at(numberCommand).commandType
                == CHECK_MARK)  {
            if (!checkTransitionNumber(commandsList->at(numberCommand).secondTransition)) {
                return false;
            }
        }
    }
    return true;
}

bool ModelPost::checkTransitionNumber(int numberTransition)
{
    if (numberTransition == -1) {
        emit sendMessage(MESSAGE_ERROR, ERROR_TRANSITION_NULL, ERROR_TITLE);
        return false;
    }
    if (numberTransition >= commandsList->size()) {
        emit sendMessage(MESSAGE_ERROR, ERROR_TRANSITION_NOT_EXIST, ERROR_TITLE);
        return false;
    }
    return true;
}

bool ModelPost::executeCommand(int numberCommand)
{
    executeNumberCommandList->append(commandsList->at(numberCommand).transition);

    if (!checkValidationCommand(numberCommand)) {
        return false;
    }

    switch(commandsList->at(numberCommand).commandType)
    {
        case ADD_MARK: {
            if (!cellsList->at(currentCarriage)) {
                changeSell(currentCarriage);
            } else {
                emit sendMessage(MESSAGE_ERROR, ERROR_MARK_TRUE, ERROR_TITLE);
                return false;
            }
            break;
        }
        case DELETE_MARK: {
            if (cellsList->at(currentCarriage)) {
                changeSell(currentCarriage);
            } else {
                emit sendMessage(MESSAGE_ERROR, ERROR_MARK_FALSE, ERROR_TITLE);
                return false;
            }
            break;
        }
        case LEFT_STEP: {
            int newCurrentCarriage = currentCarriage - 1;
            if(!setCurrentCarriage(newCurrentCarriage)) {
                emit sendMessage(MESSAGE_ERROR, ERROR_BORDER, ERROR_TITLE);
                return false;
            }
            break;
        }
        case RIGHT_STEP: {
            int newCurrentCarriage = currentCarriage + 1;
            if(!setCurrentCarriage(newCurrentCarriage)) {
                emit sendMessage(MESSAGE_ERROR, ERROR_BORDER, ERROR_TITLE);
                return false;
            }
            break;
        }
        case CHECK_MARK: {
            if (!cellsList->at(currentCarriage)) {
                executeNumberCommandList->removeLast();
                executeNumberCommandList->append(commandsList->at(numberCommand).secondTransition);
            }
            break;
        }
        case STOP: {
            sendMessage(MESSAGE_INFO, SUCCES_TEXT, SUCCES_TITLE);
            changeStatusPlay(STOPPED);
            break;
        }
        default: {
            return false;
            break;
        }
    }
    return true;
}
