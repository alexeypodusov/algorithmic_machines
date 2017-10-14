#ifndef POSTCELL_H
#define POSTCELL_H

#include <QObject>

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

class PostCell : public QObject
{
    Q_OBJECT
public:
    const static int WIDTH_CELL = 22;
    const static int HEIGHT_BUTTON = 30;
    const static int HEIGHT_LABEL = 15;

    explicit PostCell(QObject *parent = 0);
    ~PostCell();

    QVBoxLayout *mainLayout;
    QPushButton *pushButton;
    QLabel *label;

    QVBoxLayout *getMainLayout();
    QPushButton *getPushButton();
    QLabel *getLabel();
    void setNumber(QString number);
    void setMark(bool mark);
private:

signals:

public slots:
};

#endif // POSTCELL_H
