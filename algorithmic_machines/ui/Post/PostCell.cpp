#include "PostCell.h"

PostCell::PostCell(QObject *parent) : QObject(parent) {
    mainLayout = new QVBoxLayout();
    pushButton = new QPushButton();
    pushButton->setFixedSize(WIDTH_CELL, HEIGHT_BUTTON);

    label = new QLabel();
    label->setFixedHeight(HEIGHT_LABEL);
    label->setFixedSize(WIDTH_CELL, HEIGHT_LABEL);
    label->setAlignment(Qt::AlignCenter);

    mainLayout->addWidget(label);
    mainLayout->addWidget(pushButton);

    connect(pushButton, SIGNAL(clicked(bool)), this, SLOT(onButtonClickedSlot(bool)));
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

QString PostCell::getNumber() {label->text();}

void PostCell::setCurrent() {
    label->setStyleSheet("color: rgb(156,  45, 7)");
    pushButton->setStyleSheet("border:1px solid ;");
}

PostCell::onButtonClickedSlot(bool b) {
    emit buttonClickedSignal(getNumber());
}

