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
        emit selectCommand(executeNumberCommandList->last());
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

    emit selectCommand(executeNumberCommandList->last());
    if (executeCommand(executeNumberCommandList->last())) {
        timer->start(speedTimer);
        emit selectCommand(executeNumberCommandList->last());
    } else changeStatusPlay(STOPPED);
}


void ModelBase::playStep()
{
    switch (statusPlay) {
    case STOPPED: {
        executeNumberCommandList->clear();
        executeNumberCommandList->append(0);
        emit selectCommand(executeNumberCommandList->last());
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

    emit selectCommand(executeNumberCommandList->last());

}

void ModelBase::playReverseStep()
{
    if (executeNumberCommandList->size() > 1 ) {
        executeNumberCommandList->removeLast();
        reverseExecuteCommand(executeNumberCommandList->last());
        emit selectCommand(executeNumberCommandList->last());
    } else {
        changeStatusPlay(STOPPED);
    }
}

void ModelBase::changeStatusPlay(StatusPlay statusPlay)
{
    this->statusPlay = statusPlay;
    emit changedStatusPlaySignal(statusPlay);
}


