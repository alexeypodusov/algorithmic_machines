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

void ModelBase::play()
{
    switch (statusPlay) {
    case StatusPlay::STOPPED: {
        nextCommand = 0;
        changeStatusPlay(StatusPlay::PLAYING);
        break;
    }
    case StatusPlay::PLAYING: {
        return;
    }
    case StatusPlay::ON_PAUSE: {
        changeStatusPlay(StatusPlay::PLAYING);
        break;
    }
    default:
        break;
    }

    executeWithTimer();

}

void ModelBase::executeWithTimer()
{
    if (statusPlay != StatusPlay::PLAYING) return;

    if (executeCommand(nextCommand)) {
        timer->start(speedTimer);
    } else changeStatusPlay(StatusPlay::STOPPED);

}


void ModelBase::playStep()
{
    switch (statusPlay) {
    case StatusPlay::STOPPED: {
        nextCommand = 0;
        changeStatusPlay(StatusPlay::ON_PAUSE);
        break;
    }
    case StatusPlay::PLAYING: {
        return;
    }
    default:
        break;
    }

    if (!executeCommand(nextCommand)) changeStatusPlay(StatusPlay::STOPPED);
}

void ModelBase::changeStatusPlay(ModelBase::StatusPlay statusPlay)
{
    this->statusPlay = statusPlay;
}


