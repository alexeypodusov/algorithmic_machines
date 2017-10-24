#ifndef MODELPOST_H
#define MODELPOST_H

#include "ModelBase.h"



class ModelPost : public ModelBase
{
    Q_OBJECT
public:
    ModelPost(QObject *parent = 0);
    int getCurrentCarriage() const;
    void setCurrentCarriage(int value);

private:
    int currentCarriage = 0;
};

#endif // MODELPOST_H
