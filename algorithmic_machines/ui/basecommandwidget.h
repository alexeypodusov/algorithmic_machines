#ifndef BASECOMMANDWIDGET_H
#define BASECOMMANDWIDGET_H

#include <QObject>

class BaseCommandWidget : public QObject
{
    Q_OBJECT
public:
    explicit BaseCommandWidget(QObject *parent = 0);

signals:

public slots:
};

#endif // BASECOMMANDWIDGET_H