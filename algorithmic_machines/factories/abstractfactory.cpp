#include "abstractfactory.h"

AbstractFactory::AbstractFactory(QObject *parent) : QObject(parent) {

}

ModelBase *AbstractFactory::createModel(QWidget *parent)
{

}

BaseCommandWidget *AbstractFactory::createCommandWidget(QWidget *parent, ModelBase *model)
{

}

BaseWorkAreaWidget *AbstractFactory::createWorkAreaWidget(QWidget *parent, ModelBase *model)
{

}
