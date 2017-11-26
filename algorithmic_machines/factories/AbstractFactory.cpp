#include "AbstractFactory.h"

AbstractFactory::AbstractFactory(QObject *parent) : QObject(parent) {

}

ModelBase *AbstractFactory::createModel(QWidget *parent)
{

}

BaseCommandWidget *AbstractFactory::createCommandWidget(ModelBase *model)
{

}

BaseWorkAreaWidget *AbstractFactory::createWorkAreaWidget(ModelBase *model)
{

}
