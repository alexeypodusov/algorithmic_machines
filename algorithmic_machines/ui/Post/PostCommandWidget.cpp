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

    int commandListSize = model->getCommandsListSize();
    for(int i = 0 ; i < commandListSize ; i++) {
        addCommandString(i);
    }
    updateSelectingFocus(focusedCommand);
}



void PostCommandWidget::addCommandString(int numString)
{
    PostModelCommand commandModel = model->getPostCommand(numString);
    PostCommandString *command = new PostCommandString();
    stringsList->append(QSharedPointer<PostCommandString>(command));
    command->setNumberString(commandModel.number);
    command->setCommandType(commandModel.commandType);
    command->setTransition(commandModel.transition);
    command->setSecondTransition(commandModel.secondTransition);
    command->setComment(commandModel.comment);

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
    if (stringsList->size() > focusedCommand) {
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
      ui->scrollArea->ensureWidgetVisible(stringsList->at(num).data());
}


void PostCommandWidget::onAddStringClicked()
{
    model->insertCommandString(stringsList->size());
    addCommandString(stringsList->size());
}

void PostCommandWidget::onDeleteStringClicked()
{
    model->deleteCommandString(stringsList->size()-1);
    stringsList->removeLast();
}


void PostCommandWidget::onChangedStatusPlay(StatusPlay statusPlay)
{
    if (statusPlay == STOPPED) {
        deselectCommand();
        currentSelectedCommand = -1;
    }
}
