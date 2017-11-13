#ifndef BASECOMMANDSTRING_H
#define BASECOMMANDSTRING_H

#include <QFrame>
#include <QWidget>

class BaseCommandString : public QFrame
{
    Q_OBJECT
public:
    explicit BaseCommandString(QWidget *parent = 0);
    virtual ~BaseCommandString();

    const QString SELECT_STRING_CSS = "#commandString{"
                                          "padding-right: 5px;"
                                          "border:1px solid green;"
                                      "}";
    const QString NOSELECT_STRING_CSS = "#commandString{"
                                          "padding: 0px;"
                                          "border:0px solid green;"
                                      "}";

signals:

public slots:
};

#endif // BASECOMMANDSTRING_H
