#ifndef BASECOMMANDWIDGET_H
#define BASECOMMANDWIDGET_H

#include "BaseCommandString.h"
#include <QWidget>
#include <models/ModelBase.h>

class BaseCommandWidget {
public:
    explicit BaseCommandWidget();
    virtual ~BaseCommandWidget();
    virtual QWidget *getWidget()=0;
    virtual void onAddStringClicked()=0;
    virtual void onDeleteStringClicked()=0;
    virtual void onChangedStatusPlay(StatusPlay statusPlay)=0;
protected:
};

#endif // BASECOMMANDWIDGET_H
