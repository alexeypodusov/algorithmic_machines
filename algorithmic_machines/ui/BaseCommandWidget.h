#ifndef BASECOMMANDWIDGET_H
#define BASECOMMANDWIDGET_H

#include "BaseCommandString.h"

#include <QWidget>


class BaseCommandWidget {
public:
    explicit BaseCommandWidget();
    virtual ~BaseCommandWidget();
    virtual QWidget *getWidget()=0;
    virtual onAddStringClicked()=0;
    virtual onDeleteStringClicked()=0;
protected:
};

#endif // BASECOMMANDWIDGET_H
