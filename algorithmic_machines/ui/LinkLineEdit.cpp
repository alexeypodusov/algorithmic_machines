#include "LinkLineEdit.h"

LinkLineEdit::LinkLineEdit(QWidget *parent) : QLineEdit(parent)
{
    connect(getMainWindow(), SIGNAL(keyPressSignal(QKeyEvent *)), this, SLOT(keyPressSlot(QKeyEvent*)));
    connect(getMainWindow(), SIGNAL(keyReleaseSignal(QKeyEvent *)), this, SLOT(keyReleaseSlot(QKeyEvent*)));
}

QMainWindow* LinkLineEdit::getMainWindow()
{

    foreach(QWidget *widget, qApp->topLevelWidgets())
            if (QMainWindow *mainWindow = qobject_cast<QMainWindow*>(widget))
                return mainWindow;
    return NULL;
}

void LinkLineEdit::selectText()
{
    QCursor cursor;
    cursor.setShape(Qt::PointingHandCursor);
    setCursor(cursor);
    setStyleSheet(SELECTED_LINK_CSS);
    isSelected = true;
}

void LinkLineEdit::deselectText()
{
    QCursor cursor;
    cursor.setShape(Qt::ArrowCursor);
    setCursor(cursor);
    setStyleSheet(DESELECTED_LINK_CSS);
    isSelected = false;
}

LinkLineEdit::keyPressSlot(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Control) {
        isPressCtrl = true;
    }
}

LinkLineEdit::keyReleaseSlot(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Control) {
        isPressCtrl = false;
        deselectText();
    }
}

void LinkLineEdit::mouseMoveEvent(QMouseEvent *event)
{
    QLineEdit::mouseMoveEvent(event);
    if (isPressCtrl == true && !text().isEmpty()) {
        selectText();
    }
}

void LinkLineEdit::mousePressEvent(QMouseEvent *event)
{
    QLineEdit::mousePressEvent(event);
    if (isSelected == true) {
        emit clickedLinkSignal(text());
    }
}

void LinkLineEdit::leaveEvent(QEvent *event)
{
    QLineEdit::leaveEvent(event);
    deselectText();
}




