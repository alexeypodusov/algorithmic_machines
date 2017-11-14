#ifndef POSTFACTORY_H
#define POSTFACTORY_H

#include "AbstractFactory.h"

#include <ui/BaseWorkAreaWidget.h>


class PostFactory : public AbstractFactory
{
    Q_OBJECT
public:
    explicit PostFactory(QObject *parent = 0);

    // AbstractFactory interface
    ModelBase *createModel(QWidget *parent);
    BaseCommandWidget *createCommandWidget(QWidget *parent, ModelBase *model);
    BaseWorkAreaWidget *createWorkAreaWidget(QWidget *parent, ModelBase *model);

};

#endif // POSTFACTORY_H
