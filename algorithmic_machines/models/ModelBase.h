#ifndef MODELBASE_H
#define MODELBASE_H

#include <QObject>
#include <QTimer>
#include <QLinkedList>
#include <models/StatusPlay.h>
#include <ui/MessageType.h>

class ModelBase : public QObject
{
    Q_OBJECT
public:
    explicit ModelBase(QObject *parent = 0);
    virtual ~ModelBase();
    virtual bool executeCommand(int numberCommand);
    virtual bool reverseExecuteCommand(int numberCommand);
    virtual bool checkValidationCommand(int numberCommand);

    void play();
    void playStep();
    void playReverseStep();
    void changeStatusPlay(StatusPlay statusPlay);
    int speedTimer = 500;
private:
    QTimer *timer;

protected:
    QLinkedList<int> *executeNumberCommandList;
    StatusPlay statusPlay = STOPPED;

signals:
    void sendMessage(MessageType messageType, QString text, QString title);
    void selectCommand(int numberCommand);
    void changedStatusPlaySignal(StatusPlay statusPlay);
public slots:
    void executeWithTimer();
};

#endif // MODELBASE_H
