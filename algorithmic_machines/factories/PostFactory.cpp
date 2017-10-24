#include "PostFactory.h"

#include <ui/Post/PostCommandWidget.h>
#include <ui/Post/PostWorkAreaWidget.h>

#include <models/ModelPost.h>


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
