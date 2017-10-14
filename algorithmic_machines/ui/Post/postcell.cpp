#include "postcell.h"

PostCell::PostCell(QObject *parent) : QObject(parent) {
    mainLayout = new QVBoxLayout();
    pushButton = new QPushButton();
    pushButton->setFixedHeight(HEIGHT_BUTTON);
    label = new QLabel();
    label->setFixedHeight(HEIGHT_LABEL);
    mainLayout->addWidget(label);
    mainLayout->addWidget(pushButton);
}

PostCell::~PostCell()
{
    delete mainLayout;
    delete pushButton;
    delete label;
}

QVBoxLayout *PostCell::getMainLayout() {return mainLayout;}

QPushButton *PostCell::getPushButton() {return pushButton;}

QLabel *PostCell::getLabel() {return label;}

void PostCell::setNumber(QString number) {label->setText(number);}
void PostCell::setMark(bool mark) {pushButton->setText(mark?"V":"");}
