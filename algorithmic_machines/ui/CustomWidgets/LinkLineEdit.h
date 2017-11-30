#ifndef LINKLINEEDIT_H
#define LINKLINEEDIT_H

#include <QApplication>
#include <QObject>
#include <QLineEdit>
#include <QWidget>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QMainWindow>

class MainWindow;

class LinkLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit LinkLineEdit(QWidget *parent = 0);

private:
    const QString SELECTED_LINK_CSS = "LinkLineEdit{"
                                                "text-decoration: underline;"
                                                "color: MidnightBlue ;"
                                                "font-weight: bold;"
                                                "}";
    const QString DESELECTED_LINK_CSS = "LinkLineEdit{"
                                                "text-decoration: none;"
                                                "color: black;"
                                                "font-weight: normal;"
                                                "}";

    QMainWindow* getMainWindow();
    bool isPressCtrl = false;
    bool isSelected = false;
    void selectText();
    void deselectText();
signals:
    void clickedLinkSignal(QString link);
private slots:
    keyPressSlot(QKeyEvent *event);
    keyReleaseSlot(QKeyEvent *event);
public slots:


    // QWidget interface
protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void leaveEvent(QEvent *);
};

#endif // LINKLINEEDIT_H
