#include "PostCommandWidget.h"
#include "ui_postcommandwidget.h"

PostCommandWidget::PostCommandWidget(QWidget *parent, ModelBase *model) :
    QWidget(parent),
    ui(new Ui::PostCommandWidget)
{
    ui->setupUi(this);
    this->model = (ModelPost*)model;
    init();
}

PostCommandWidget::~PostCommandWidget()
{
    stringsList->clear();
    delete stringsList;
    delete ui;
}

PostCommandWidget::init()
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

}

void PostCommandWidget::addCommandString(int numString)
{
    PostModelCommand commandModel = model->getPostCommand(numString);
    PostCommandString *command = new PostCommandString(this);
    stringsList->append(QSharedPointer<PostCommandString>(command));
    command->setNumberString(commandModel.number);
    command->setCommandType(commandModel.commandType);
    command->setTransition(commandModel.transition);
    command->setSecondTransition(commandModel.secondTransition);
    command->setComment(commandModel.comment);

    connect(command, SIGNAL(onCommandTypeChangedSignal(int, PostModelCommand::CommandType)), this, SLOT(onCommandTypeChanged(int, PostModelCommand::CommandType)));
    connect(command, SIGNAL(onTransitionEditedSignal(int,int)), this, SLOT(onTransitionEdited(int, int)));
    connect(command, SIGNAL(onSecondTransitionEditedSignal(int,int)), this, SLOT(onSecondTransitionEdited(int, int)));
    connect(command, SIGNAL(onCommentEditedSignal(int, QString)), this, SLOT(onCommentEdited(int, QString)));
    commandStringsLayout->addWidget(command);
}

QWidget *PostCommandWidget::getWidget()
{
    return this;
}

PostCommandWidget::onCommandTypeChanged(int numberString, PostModelCommand::CommandType type)
{
    model->setCommandType(numberString, type);
}

PostCommandWidget::onTransitionEdited(int numberString, int transition)
{
    model->setTransition(numberString, transition);
}

PostCommandWidget::onSecondTransitionEdited(int numberString, int transition)
{
    model->setSecondTransition(numberString, transition);
}

PostCommandWidget::onCommentEdited(int numberString, QString comment)
{
    model->setComment(numberString, comment);
}


PostCommandWidget::onAddStringClicked()
{
    model->insertCommandString(stringsList->size());
    addCommandString(stringsList->size());
}

PostCommandWidget::onDeleteStringClicked()
{
    model->deleteCommandString(stringsList->size()-1);
    stringsList->removeLast();
}
