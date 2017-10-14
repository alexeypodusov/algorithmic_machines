#ifndef POSTCELL_H
#define POSTCELL_H

#include <QObject>

class PostCell : public QObject
{
    Q_OBJECT
public:
    explicit PostCell(QObject *parent = 0);

signals:

public slots:
};

#endif // POSTCELL_H