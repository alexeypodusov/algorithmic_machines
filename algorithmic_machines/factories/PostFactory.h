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
    BaseCommandWidget *createCommandWidget(ModelBase *model);
    BaseWorkAreaWidget *createWorkAreaWidget(ModelBase *model);

};

#endif // POSTFACTORY_H
