#include "ModelBase.h"

ModelBase::ModelBase(QObject *parent) : QObject(parent)
{
    executeNumberCommandList = new QLinkedList<int>();
    timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()), this, SLOT(executeWithTimer()));
    timer->setSingleShot(1);
}

ModelBase::~ModelBase()
{
    executeNumberCommandList->clear();
    delete executeNumberCommandList;
    delete timer;
}

bool ModelBase::executeCommand(int numberCommand)
{
}

bool ModelBase::reverseExecuteCommand(int numberCommand)
{

}

bool ModelBase::checkValidationCommand(int numberCommand)
{
}

void ModelBase::play()
{
    switch (statusPlay) {
    case STOPPED: {
        executeNumberCommandList->clear();
        executeNumberCommandList->append(0);
        changeStatusPlay(PLAYING);
        emitSelectCommand();
        timer->start(speedTimer);
        break;
    }
    case PLAYING: {
        return;
    }
    case ON_PAUSE: {
        changeStatusPlay(PLAYING);
        break;
    }
    default:
        break;
    }

}

void ModelBase::executeWithTimer()
{
    if (statusPlay != PLAYING) return;

    emitSelectCommand();
    if (executeCommand(executeNumberCommandList->last())) {
        timer->start(speedTimer);


        emitSelectCommand();
    } else changeStatusPlay(STOPPED);
}


void ModelBase::playStep()
{
    switch (statusPlay) {
    case STOPPED: {
        executeNumberCommandList->clear();
        executeNumberCommandList->append(0);
        emitSelectCommand();
        changeStatusPlay(ON_PAUSE);
        return;
    }
    case PLAYING: {
        return;
    }
    default:
        break;
    }

    if (!executeCommand(executeNumberCommandList->last())) {
        changeStatusPlay(STOPPED);
        return;
    }

    emitSelectCommand();

}

void ModelBase::playReverseStep()
{
    if (executeNumberCommandList->size() > 1 ) {
        executeNumberCommandList->removeLast();
        reverseExecuteCommand(executeNumberCommandList->last());
        emitSelectCommand();
    } else {
        changeStatusPlay(STOPPED);
    }
}

void ModelBase::emitSelectCommand()
{
    int prevCommand = -1;
    if (executeNumberCommandList->size() > 1) {
        QLinkedList<int>::iterator i;
        i = executeNumberCommandList->end();
        i-=2;
        prevCommand = *i;
    }
    emit selectCommand(executeNumberCommandList->last(), prevCommand);
}

void ModelBase::changeStatusPlay(StatusPlay statusPlay)
{
    this->statusPlay = statusPlay;
    emit changedStatusPlaySignal(statusPlay);
}


