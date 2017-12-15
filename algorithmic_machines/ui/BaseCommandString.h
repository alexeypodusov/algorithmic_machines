#ifndef BASECOMMANDSTRING_H
#define BASECOMMANDSTRING_H

#include <QFrame>
#include <QWidget>
#include <QEvent>

class BaseCommandString : public QFrame
{
    Q_OBJECT
public:
    explicit BaseCommandString(QWidget *parent = 0);
    virtual ~BaseCommandString();
    virtual void setSelectingFocused()=0;
    virtual void removeSelectingFocus()=0;

    const QString SELECT_STRING_CSS = "#commandString{"
                                          "padding-right: 5px;"
                                          "border:1px solid green;"
                                      "}";
    const QString NOSELECT_STRING_CSS = "#commandString{"
                                          "padding: 0px;"
                                          "border:0px solid green;"
                                      "}";
private:
    bool eventFilter(QObject *obj, QEvent *event);

protected:
    int numberString = -1;
signals:
    void inFocusSignal(int num);
};

#endif // BASECOMMANDSTRING_H
