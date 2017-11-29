#include "PostCommandString.h"

PostCommandString::PostCommandString(QWidget *parent) : BaseCommandString(parent)
{
    mainLayout = new QVBoxLayout;
    stringLayout = new QHBoxLayout();

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

    transitionLineEdit = new LinkLineEdit();
    transitionLineEdit->setFixedWidth(WIDTH_TRANSITION_STRING);
    transitionLineEdit->setFixedHeight(HEIGHT_STRING);
    transitionLineEdit->setMaximumWidth(3);
    transitionLineEdit->setValidator(new QIntValidator(0, 999));
    connect(transitionLineEdit, SIGNAL(editingFinished()), this, SLOT(onTransitionEditedSlot()));
    connect(transitionLineEdit, SIGNAL(clickedLinkSignal(QString)), this, SLOT(onLinkStringSlot(QString)));
    stringLayout->addWidget(transitionLineEdit);

    secondTransitionLineEdit = new LinkLineEdit();
    secondTransitionLineEdit->setFixedWidth(WIDTH_TRANSITION_STRING);
    secondTransitionLineEdit->setFixedHeight(HEIGHT_STRING);
    transitionLineEdit->setMaximumWidth(3);
    transitionLineEdit->setValidator(new QIntValidator(0, 999));
    secondTransitionLineEdit->hide();
    connect(secondTransitionLineEdit, SIGNAL(editingFinished()), this, SLOT(onSecondTransitionEditedSlot()));
    connect(secondTransitionLineEdit, SIGNAL(clickedLinkSignal(QString)), this, SLOT(onLinkStringSlot(QString)));
    stringLayout->addWidget(secondTransitionLineEdit);

    commentLineEdit = new QLineEdit();
    commentLineEdit->setMinimumWidth(WIDTH_COMMENT_STRING);
    commentLineEdit->setFixedHeight(HEIGHT_STRING);
    commentLineEdit->setMaxLength(255);
    stringLayout->addWidget(commentLineEdit);
    connect(commentLineEdit, SIGNAL(editingFinished()), this, SLOT(onCommentEditedSlot()));
    stringLayout->setContentsMargins(0,0,0,0);

    mainLayout->setContentsMargins(0,0,0,0);
    mainLayout->addLayout(stringLayout);

    previousStringWidget = new QWidget;
    linkLayout = new QHBoxLayout;
    previousStringText = new QLabel(previousStringWidget);
    previousStringText->setText(QString::fromLocal8Bit("Предыдущая строка: "));
    linkLayout->addWidget(previousStringText);

    previousNumberString = new QLabel(previousStringWidget);
    connect(previousNumberString, SIGNAL(linkActivated(QString)), this, SLOT(onLinkStringSlot(QString)));
    linkLayout->addWidget(previousNumberString);

    linkLayout->setContentsMargins(LINK_LAYOUT_MARGIN,0,0,0);
    linkLayout->setAlignment(Qt::AlignLeft);
    previousStringWidget->setLayout(linkLayout);
    previousStringWidget->hide();

    mainLayout->addWidget(previousStringWidget);

    this->setLayout(mainLayout);
    mainLayout->setAlignment(Qt::AlignCenter);

    this->setFixedHeight(HEIGHT_STRING);
    this->setStyleSheet(NOSELECT_STRING_CSS);

}

PostCommandString::~PostCommandString()
{
    delete linkLayout;
    delete previousStringWidget;
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

void PostCommandString::setSelect(int prevCommand)
{
    this->setStyleSheet(SELECT_STRING_CSS);
    setFixedHeight(3*HEIGHT_STRING);
    if (prevCommand != -1) {
        QString link = QString("<a href='%1'>%1</a>").arg(QString::number(prevCommand));
        previousNumberString->setText(link);
        previousStringWidget->show();
    }

}

void PostCommandString::setDeselected()
{
    this->setStyleSheet(NOSELECT_STRING_CSS);
    setFixedHeight(HEIGHT_STRING);
    previousStringWidget->hide();
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

void PostCommandString::onLinkStringSlot(QString link)
{
    emit onLinkStringSignal(link.toInt());
}

