#ifndef POSTFACTORY_H
#define POSTFACTORY_H

#include "abstractfactory.h"

#include <ui/baseworkareawidget.h>


class PostFactory : public AbstractFactory
{
    Q_OBJECT
public:
    explicit PostFactory(QObject *parent = 0);

    QObject *g;

    // AbstractFactory interface
    ModelBase *createModel(QWidget *parent) override;
    BaseCommandWidget *createCommandWidget(QWidget *parent, ModelBase *model) override;
    BaseWorkAreaWidget *createWorkAreaWidget(QWidget *parent, ModelBase *model) override;

};

#endif // POSTFACTORY_H
