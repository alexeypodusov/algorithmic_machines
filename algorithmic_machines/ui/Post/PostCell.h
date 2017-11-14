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

    QVBoxLayout *getMainLayout();
    QPushButton *getPushButton();
    QWidget *getCellWidget();
    QLabel *getLabel();
    void setNumber(QString number);
    void setMark(bool mark);
    void setCurrent();
    void setVisible(bool isVisible);
    bool isVisible();
    QString getNumber();



private:
    QVBoxLayout *mainLayout;
    QPushButton *pushButton;
    QLabel *label;
    QWidget *cellWidget;

signals:
    void buttonClickedSignal(QString numberCell);
private slots:
    void onButtonClickedSlot(bool b);
};

#endif // POSTCELL_H
