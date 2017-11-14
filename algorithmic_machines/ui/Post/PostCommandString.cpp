#include "PostCommandString.h"

PostCommandString::PostCommandString(QWidget *parent) : BaseCommandString(parent)
{
    stringLayout = new QHBoxLayout;

    numberStringLabel = new QLabel();
    numberStringLabel->setMinimumWidth(WIDTH_NUMBER_STRING);
    numberStringLabel->setFixedHeight(HEIGHT_STRING);
    numberStringLabel->setAlignment(Qt::AlignCenter);
    stringLayout->addWidget(numberStringLabel);

    commandComboBox = new QComboBox();
    commandComboBox->setMinimumWidth(WIDTH_COMMAND_STRING);
    commandComboBox->setFixedHeight(HEIGHT_STRING);
    commandComboBox->addItem("");
    commandComboBox->addItem(QString::fromLocal8Bit("V добавить метку"));
    commandComboBox->addItem(QString::fromLocal8Bit("X удалить метку"));
    commandComboBox->addItem(QString::fromLocal8Bit("<- шаг влево"));
    commandComboBox->addItem(QString::fromLocal8Bit("-> шаг вправо"));
    commandComboBox->addItem(QString::fromLocal8Bit("? проверить"));
    commandComboBox->addItem(QString::fromLocal8Bit("! стоп"));
    connect(commandComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onCommandTypeChangedSlot(int)));
    stringLayout->addWidget(commandComboBox);

    transitionLineEdit = new QLineEdit();
    transitionLineEdit->setFixedWidth(WIDTH_TRANSITION_STRING);
    transitionLineEdit->setFixedHeight(HEIGHT_STRING);
    transitionLineEdit->setMaximumWidth(3);
    transitionLineEdit->setValidator(new QIntValidator(0, 999));
    connect(transitionLineEdit, SIGNAL(editingFinished()), this, SLOT(onTransitionEditedSlot()));
    stringLayout->addWidget(transitionLineEdit);

    secondTransitionLineEdit = new QLineEdit();
    secondTransitionLineEdit->setFixedWidth(WIDTH_TRANSITION_STRING);
    secondTransitionLineEdit->setFixedHeight(HEIGHT_STRING);
    transitionLineEdit->setMaximumWidth(3);
    transitionLineEdit->setValidator(new QIntValidator(0, 999));
    secondTransitionLineEdit->hide();
    connect(secondTransitionLineEdit, SIGNAL(editingFinished()), this, SLOT(onSecondTransitionEditedSlot()));
    stringLayout->addWidget(secondTransitionLineEdit);

    commentLineEdit = new QLineEdit();
    commentLineEdit->setMinimumWidth(WIDTH_COMMENT_STRING);
    commentLineEdit->setFixedHeight(HEIGHT_STRING);
    commentLineEdit->setMaxLength(255);
    stringLayout->addWidget(commentLineEdit);
    connect(commentLineEdit, SIGNAL(editingFinished()), this, SLOT(onCommentEditedSlot()));
    stringLayout->setContentsMargins(0,0,0,0);

    this->setLayout(stringLayout);

    this->setFixedHeight(HEIGHT_STRING);
    this->setStyleSheet(NOSELECT_STRING_CSS);

}

PostCommandString::~PostCommandString()
{
    delete stringLayout;
    delete numberStringLabel;
    delete transitionLineEdit;
    delete secondTransitionLineEdit;
    delete commandComboBox;
    delete commentLineEdit;
}

QHBoxLayout *PostCommandString::getStringLayout()
{
    return stringLayout;
}

int PostCommandString::getNumberString()
{
    bool ok;
    int number = numberStringLabel->text().toInt(&ok);
    if (ok) {return number;}
}

void PostCommandString::setNumberString(int number)
{
    numberStringLabel->setText(QString::number(number));
}

PostCommandType PostCommandString::getCommandType()
{
      return static_cast<PostCommandType>(commandComboBox->currentIndex());
}

void PostCommandString::setCommandType(PostCommandType type)
{
     commandComboBox->setCurrentIndex(static_cast<int>(type));
}

int PostCommandString::getTransition()
{
    bool ok;
    int transition = transitionLineEdit->text().toInt(&ok);
    if (!ok) {transition = -1;}
    return transition;

}

void PostCommandString::setTransition(int transition)
{
    transitionLineEdit->setText(transition != -1 ? QString::number(transition) : "");
}

int PostCommandString::getSecondTransition()
{
    bool ok;
    int transition = secondTransitionLineEdit->text().toInt(&ok);
    if (!ok) {transition = -1;}
    return transition;
}

void PostCommandString::setSecondTransition(int transition)
{
    secondTransitionLineEdit->setText(transition != -1 ? QString::number(transition) : "");
}

QString PostCommandString::getComment()
{
    return commentLineEdit->text();
}

void PostCommandString::setComment(QString comment)
{
    commentLineEdit->setText(comment);
}

void PostCommandString::setSelect()
{
    this->setStyleSheet(SELECT_STRING_CSS);
    setFixedHeight(2*HEIGHT_STRING);
}

void PostCommandString::setDeselected()
{
    this->setStyleSheet(NOSELECT_STRING_CSS);
    setFixedHeight(HEIGHT_STRING);
}


void PostCommandString::onCommandTypeChangedSlot(int type)
{
    PostCommandType commandType = static_cast<PostCommandType>(type);
    if (commandType == CHECK_MARK) {
        secondTransitionLineEdit->show();
    } else {
        secondTransitionLineEdit->hide();
    }

    emit onCommandTypeChangedSignal(numberStringLabel->text().toInt(), commandType);

}

void PostCommandString::onTransitionEditedSlot()
{
    emit  onTransitionEditedSignal(numberStringLabel->text().toInt(), getTransition());
}

void PostCommandString::onSecondTransitionEditedSlot()
{
    emit  onSecondTransitionEditedSignal(numberStringLabel->text().toInt(), getSecondTransition());
}

void PostCommandString::onCommentEditedSlot()
{
    emit onCommentEditedSignal(numberStringLabel->text().toInt(), getComment());
}

