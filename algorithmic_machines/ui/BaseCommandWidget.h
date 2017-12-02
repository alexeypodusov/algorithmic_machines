#ifndef BASECOMMANDWIDGET_H
#define BASECOMMANDWIDGET_H

#include "BaseCommandString.h"
#include <QObject>
#include <QWidget>
#include <models/ModelBase.h>

class BaseCommandWidget : public QWidget {
    Q_OBJECT
public:
    explicit BaseCommandWidget();
    virtual ~BaseCommandWidget();
    virtual QWidget *getWidget()=0;
    virtual void onAddStringClicked()=0;
    virtual void onDeleteStringClicked()=0;
    virtual void onChangedStatusPlay(StatusPlay statusPlay)=0;
    virtual void goToCommandByNumber(int num) = 0;

    virtual void onBackCommandClicked();
    virtual void onForwardCommandClicked();


    void checkCurrentIndex();
signals:
    void enableCommandButtonsChange(bool backEnable, bool forwardEnable);

protected:
    QList<int> *clickedCommandList;
    int currentCommandIndex = 0;
};

#endif // BASECOMMANDWIDGET_H
