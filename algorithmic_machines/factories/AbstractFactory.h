#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include <QObject>

#include <ui/BaseCommandWidget.h>
#include <ui/BaseWorkAreaWidget.h>

#include <models/ModelBase.h>

class AbstractFactory : public QObject
{
    Q_OBJECT
public:
    explicit AbstractFactory(QObject *parent = 0);

    virtual ModelBase *createModel(QWidget *parent);
    virtual BaseCommandWidget *createCommandWidget(ModelBase *model);
    virtual BaseWorkAreaWidget *createWorkAreaWidget(ModelBase *model);
private:

signals:

public slots:
};

#endif // ABSTRACTFACTORY_H
