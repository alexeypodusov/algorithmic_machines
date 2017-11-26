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


BaseCommandWidget *PostFactory::createCommandWidget(ModelBase *model)
{
     return (BaseCommandWidget*)new PostCommandWidget(model);
}

BaseWorkAreaWidget *PostFactory::createWorkAreaWidget(ModelBase *model)
{
    return (BaseWorkAreaWidget*)new PostWorkAreaWidget(model);
}
