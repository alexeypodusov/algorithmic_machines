#include "ModelBase.h"

ModelBase::ModelBase(QObject *parent) : QObject(parent)
{
    timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()), this, SLOT(executeWithTimer()));
    timer->setSingleShot(1);
}

ModelBase::~ModelBase()
{
    delete timer;
}

bool ModelBase::executeCommand(int numberCommand)
{
}

bool ModelBase::checkValidationCommand(int numberCommand)
{
}

void ModelBase::play()
{
    switch (statusPlay) {
    case STOPPED: {
        nextCommand = 0;
        changeStatusPlay(PLAYING);
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

    executeWithTimer();
}

void ModelBase::executeWithTimer()
{
    if (statusPlay != PLAYING) return;

    emit selectCommand(nextCommand);
    if (executeCommand(nextCommand)) {
        timer->start(speedTimer);
    } else changeStatusPlay(STOPPED);
}


void ModelBase::playStep()
{
    switch (statusPlay) {
    case STOPPED: {
        nextCommand = 0;
        changeStatusPlay(ON_PAUSE);
        break;
    }
    case PLAYING: {
        return;
    }
    default:
        break;
    }

    emit selectCommand(nextCommand);
    if (!executeCommand(nextCommand)) changeStatusPlay(STOPPED);
}

void ModelBase::changeStatusPlay(StatusPlay statusPlay)
{
    this->statusPlay = statusPlay;
    emit changedStatusPlaySignal(statusPlay);
}


