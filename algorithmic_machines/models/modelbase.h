#ifndef MODELBASE_H
#define MODELBASE_H

#include <QObject>

class ModelBase : public QObject
{
    Q_OBJECT
public:
    explicit ModelBase(QObject *parent = 0);

signals:

public slots:
};

#endif // MODELBASE_H