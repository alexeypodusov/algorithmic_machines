#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include <QObject>

#include <ui/basecommandwidget.h>
#include <ui/baseworkareawidget.h>

#include <models/modelbase.h>

class AbstractFactory : public QObject
{
    Q_OBJECT
public:
    explicit AbstractFactory(QObject *parent = 0);

    virtual ModelBase *createModel(QWidget *parent);
    virtual BaseCommandWidget *createCommandWidget(QWidget *parent, ModelBase *model);
    virtual BaseWorkAreaWidget *createWorkAreaWidget(QWidget *parent, ModelBase *model);
private:

signals:

public slots:
};

#endif // ABSTRACTFACTORY_H
