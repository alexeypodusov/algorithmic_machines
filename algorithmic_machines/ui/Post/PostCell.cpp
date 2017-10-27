#include "PostCell.h"

PostCell::PostCell(QObject *parent) : QObject(parent) {
    cellWidget = new QWidget();

    mainLayout = new QVBoxLayout(cellWidget);
    pushButton = new QPushButton();
    pushButton->setFixedSize(WIDTH_CELL, HEIGHT_BUTTON);

    label = new QLabel();
    label->setFixedHeight(HEIGHT_LABEL);
    label->setFixedSize(WIDTH_CELL, HEIGHT_LABEL);
    label->setAlignment(Qt::AlignCenter);

    mainLayout->addWidget(label);
    mainLayout->addWidget(pushButton);
    mainLayout->setContentsMargins(0,0,0,0);

    connect(pushButton, SIGNAL(clicked(bool)), this, SLOT(onButtonClickedSlot(bool)));
}

PostCell::~PostCell()
{
    delete mainLayout;
    delete pushButton;
    delete label;
    delete cellWidget;

}

QVBoxLayout *PostCell::getMainLayout() {return mainLayout;}
QPushButton *PostCell::getPushButton() {return pushButton;}
QWidget *PostCell::getCellWidget() {return cellWidget;}
QLabel *PostCell::getLabel() {return label;}

void PostCell::setNumber(QString number) {label->setText(number);}
void PostCell::setMark(bool mark) {pushButton->setText(mark?"V":"");}

QString PostCell::getNumber() {return label->text();}

void PostCell::setCurrent() {
    label->setStyleSheet("color: rgb(156,  45, 7)");
    pushButton->setStyleSheet("border:1px solid ;");
}

void PostCell::setVisible(bool isVisible) {
    pushButton->setVisible(isVisible);
    label->setVisible(isVisible);
}

bool PostCell::isVisible() {
    return pushButton->isVisible() && label->isVisible();
}

PostCell::onButtonClickedSlot(bool b) {
    emit buttonClickedSignal(getNumber());
}

