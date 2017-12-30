#include "PostCommandWidget.h"
#include "ui_PostCommandWidget.h"

PostCommandWidget::PostCommandWidget(ModelBase *model) :
    BaseCommandWidget(),
    ui(new Ui::PostCommandWidget)
{
    ui->setupUi(this);
    this->model = (ModelPost*)model;
    connect(this->model, SIGNAL(selectCommand(int, int)), this, SLOT(onSelectedCommand(int, int)));
    init();
}

PostCommandWidget::~PostCommandWidget()
{
    stringsList->clear();
    delete stringsList;
    delete ui;
}

void PostCommandWidget::init()
{         
    stringsList = new QList<QSharedPointer<PostCommandString> >();

    scrollAreaLayout = new QVBoxLayout(this);
    commandStringsLayout = new QVBoxLayout(this);

    scrollAreaLayout->addLayout(commandStringsLayout);

    ui->scrollArea->widget()->setLayout(scrollAreaLayout);
    scrollAreaLayout->setAlignment(commandStringsLayout, Qt::AlignTop);

    updateCommands();
    updateSelectingFocus(focusedCommand);
}



void PostCommandWidget::addCommandString(int numString)
{
    PostCommandString *command = new PostCommandString();
    stringsList->append(QSharedPointer<PostCommandString>(command));

    connect(command, SIGNAL(onCommandTypeChangedSignal(int, PostCommandType)), this, SLOT(onCommandTypeChanged(int, PostCommandType)));
    connect(command, SIGNAL(onTransitionEditedSignal(int,int)), this, SLOT(onTransitionEdited(int, int)));
    connect(command, SIGNAL(onSecondTransitionEditedSignal(int,int)), this, SLOT(onSecondTransitionEdited(int, int)));
    connect(command, SIGNAL(onCommentEditedSignal(int, QString)), this, SLOT(onCommentEdited(int, QString)));
    connect(command, SIGNAL(onLinkStringSignal(int, int)), this, SLOT(onNumStringClicked(int, int)));
    connect(command, SIGNAL(inFocusSignal(int)), this, SLOT(onInFocusCommand(int)));
    commandStringsLayout->addWidget(command);
}

void PostCommandWidget::deselectCommand()
{
    if (currentSelectedCommand != -1) {
         stringsList->at(currentSelectedCommand).data()->setDeselected();
    }
}

void PostCommandWidget::updateSelectingFocus(int numString)
{
    if (stringsList->size() >= focusedCommand) {
        stringsList->at(focusedCommand).data()->removeSelectingFocus();
    }
    focusedCommand = numString;
    stringsList->at(numString).data()->setSelectingFocused();
}

QWidget *PostCommandWidget::getWidget()
{
    return this;
}

void PostCommandWidget::onCommandTypeChanged(int numberString, PostCommandType type)
{
    model->setCommandType(numberString, type);
}

void PostCommandWidget::onTransitionEdited(int numberString, int transition)
{
    model->setTransition(numberString, transition);
}

void PostCommandWidget::onSecondTransitionEdited(int numberString, int transition)
{
    model->setSecondTransition(numberString, transition);
}

void PostCommandWidget::onCommentEdited(int numberString, QString comment)
{
    model->setComment(numberString, comment);
}

void PostCommandWidget::onSelectedCommand(int numberCommand, int prevCommand)
{
    deselectCommand();
    stringsList->at(numberCommand).data()->setSelect(prevCommand);
    ui->scrollArea->ensureWidgetVisible(stringsList->at(numberCommand).data());
    currentSelectedCommand = numberCommand;
}

void PostCommandWidget::onNumStringClicked(int transitionNum, int senderNum)
{
    if (transitionNum < stringsList->size()) {
        if (clickedCommandList->size() > 1) {
            for(int i = (clickedCommandList->size() - 1);
                i > currentCommandIndex; i--) {
                clickedCommandList->removeLast();
            }
        }

        if (clickedCommandList->at(currentCommandIndex) != senderNum) {
            clickedCommandList->append(senderNum);
        }
        currentCommandIndex++;
        clickedCommandList->append(transitionNum);

        goToCommandByNumber(transitionNum);
    }

}

void PostCommandWidget::onInFocusCommand(int numCommand)
{
    updateSelectingFocus(numCommand);
}

void PostCommandWidget::goToCommandByNumber(int num)
{
      checkCurrentIndex();
      updateSelectingFocus(num);
      ui->scrollArea->ensureWidgetVisible(stringsList->at(num).data());
}

void PostCommandWidget::updateCommands()
{
    int modelSize = model->getCommandsListSize();

    while (stringsList->size() > modelSize) {
        stringsList->removeLast();
    }

    while (stringsList->size() < modelSize) {
        addCommandString(stringsList->size());
    }

    for(int i = 0; i < modelSize; i++) {
        PostModelCommand commandModel = model->getPostCommand(i);
        stringsList->at(i).data()->setNumberString(commandModel.number);
        stringsList->at(i).data()->setCommandType(commandModel.commandType);
        stringsList->at(i).data()->setTransition(commandModel.transition);
        stringsList->at(i).data()->setSecondTransition(commandModel.secondTransition);
        stringsList->at(i).data()->setComment(commandModel.comment);
    }

}


void PostCommandWidget::onAddStringClicked()
{
    model->insertCommandString(focusedCommand + 1);
    updateCommands();
}

void PostCommandWidget::onDeleteStringClicked()
{
    model->deleteCommandString(focusedCommand);
    updateCommands();
}


void PostCommandWidget::onChangedStatusPlay(StatusPlay statusPlay)
{
    if (statusPlay == STOPPED) {
        deselectCommand();
        currentSelectedCommand = -1;
    }
}
