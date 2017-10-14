#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include <QObject>

class AbstractFactory : public QObject
{
    Q_OBJECT
public:
    explicit AbstractFactory(QObject *parent = 0);

signals:

public slots:
};

#endif // ABSTRACTFACTORY_H