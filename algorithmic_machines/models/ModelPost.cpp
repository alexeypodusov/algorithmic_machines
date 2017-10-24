#include "ModelPost.h"

ModelPost::ModelPost(QObject *parent) : ModelBase(parent)
{

}

int ModelPost::getCurrentCarriage() const
{
    return currentCarriage;
}

void ModelPost::setCurrentCarriage(int value)
{
    if(value > -1000 && value < 1000) {
        currentCarriage = value;
    }
}
