#include "BaseCommandString.h"

BaseCommandString::BaseCommandString(QWidget *parent) : QFrame(parent)
{
     setObjectName("commandString");
}

BaseCommandString::~BaseCommandString()
{

}

bool BaseCommandString::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::FocusIn) {
        emit inFocusSignal(numberString);
    }
    return QFrame::eventFilter(obj, event);
}
