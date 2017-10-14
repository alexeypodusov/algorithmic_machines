#include "postfactory.h"

#include <ui/Post/postcommandwidget.h>
#include <ui/Post/postworkareawidget.h>

#include <models/modelpost.h>


PostFactory::PostFactory(QObject *parent) : AbstractFactory(parent)
{

}
ModelBase *PostFactory::createModel(QWidget *parent)
{
    return (ModelBase*)new ModelPost(parent);
}


BaseCommandWidget *PostFactory::createCommandWidget(QWidget *parent, ModelBase *model)
{
     return (BaseCommandWidget*)new PostCommandWidget(parent, model);
}

BaseWorkAreaWidget *PostFactory::createWorkAreaWidget(QWidget *parent, ModelBase *model)
{
    return (BaseWorkAreaWidget*)new PostWorkAreaWidget(parent, model);
}
