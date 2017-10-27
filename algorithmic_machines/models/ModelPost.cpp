#include "ModelPost.h"

ModelPost::ModelPost(QObject *parent) : ModelBase(parent) {

    cellsList = new QList<bool>();
    for(int i = 0; i<2000; i++) {
        cellsList->append(false);
    }
}

ModelPost::~ModelPost()
{
    delete cellsList;
}

int ModelPost::getCurrentCarriage() const
{
    return currentCarriage;
}

void ModelPost::setCurrentCarriage(int value)
{
    if(value >= LEFT_BORDER_TAPE && value <= RIGHT_BORDER_TAPE) {
        currentCarriage = value;
    }
}

bool ModelPost::getMarkByNumberCell(int numCell) {
    int numList = numCell + 1000;
    return cellsList->at(numList);
}


void ModelPost::changeSell(int numCell) {
    int numList = numCell + 1000;
    cellsList->operator [](numList) = !cellsList->at(numList);
}


