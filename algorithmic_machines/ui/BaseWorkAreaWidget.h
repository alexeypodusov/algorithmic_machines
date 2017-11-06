#ifndef BASEWORKAREAWIDGET_H
#define BASEWORKAREAWIDGET_H

#include <QObject>
#include <QWidget>

class BaseWorkAreaWidget
{
public:
    explicit BaseWorkAreaWidget();
    virtual ~BaseWorkAreaWidget();
    virtual QWidget* getWidget();
    virtual void updateSizeWidget();
    virtual void updateWorkArea();
};

#endif // BASEWORKAREAWIDGET_H
