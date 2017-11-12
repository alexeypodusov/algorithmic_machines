#ifndef MODELBASE_H
#define MODELBASE_H

#include <QObject>
#include <QTimer>
#include <ui/MessageType.h>

class ModelBase : public QObject
{
    Q_OBJECT
public:
    explicit ModelBase(QObject *parent = 0);
    virtual ~ModelBase();
    virtual bool executeCommand(int numberCommand);
    void play();
    void playStep();
    int speedTimer = 500;
private:
    QTimer *timer;

protected:
    int nextCommand;
    enum class StatusPlay {
        STOPPED,
        PLAYING,
        ON_PAUSE
    };
    StatusPlay statusPlay = StatusPlay::STOPPED;
    void changeStatusPlay(StatusPlay statusPlay);

signals:
    sendMessage(MessageType messageType, QString text, QString title);
public slots:
    void executeWithTimer();
};

#endif // MODELBASE_H
