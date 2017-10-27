#ifndef MODELPOST_H
#define MODELPOST_H

#include "ModelBase.h"



class ModelPost : public ModelBase
{
    Q_OBJECT
public:
    const static int LEFT_BORDER_TAPE=-999;
    const static int RIGHT_BORDER_TAPE=999;

    ModelPost(QObject *parent = 0);
    ~ModelPost();
    int getCurrentCarriage() const;
    void setCurrentCarriage(int value);
    bool getMarkByNumberCell(int numCell);

    void changeSell(int numCell);
private:
    QList<bool> *cellsList;
    int currentCarriage = 0;
};

#endif // MODELPOST_H
