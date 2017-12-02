#include "BaseCommandWidget.h"

BaseCommandWidget::BaseCommandWidget() : QWidget(0) {
    clickedCommandList = new QList<int>();
    clickedCommandList->append(0);
}

BaseCommandWidget::~BaseCommandWidget()
{
    delete clickedCommandList;
}

void BaseCommandWidget::onBackCommandClicked()
{
    if (currentCommandIndex > 0) {
        --currentCommandIndex;
        goToCommandByNumber(clickedCommandList->at(currentCommandIndex));
    }
}

void BaseCommandWidget::onForwardCommandClicked()
{
    if (currentCommandIndex < (clickedCommandList->size() - 1)) {
        ++currentCommandIndex;
        goToCommandByNumber(clickedCommandList->at(currentCommandIndex));
    }
}

void BaseCommandWidget::checkCurrentIndex()
{
    bool backEnable = currentCommandIndex != 0;
    bool forwardEnable = !(currentCommandIndex == (clickedCommandList->size() - 1));

    emit enableCommandButtonsChange(backEnable, forwardEnable);
}
