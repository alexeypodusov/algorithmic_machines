#ifndef POSTWORKAREAWIDGET_H
#define POSTWORKAREAWIDGET_H

#include "PostCell.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <qlabel.h>

#include <ui/BaseWorkAreaWidget.h>
#include <QResizeEvent>
#include <QScrollBar>
#include <models/ModelBase.h>
#include <models/ModelPost.h>
#include <QApplication>
#include <QDesktopWidget>
#include <QSize>

namespace Ui {
class PostWorkAreaWidget;
}

class PostWorkAreaWidget : public QWidget, BaseWorkAreaWidget
{
    Q_OBJECT

public:
    explicit PostWorkAreaWidget(ModelBase *model);
    ~PostWorkAreaWidget();

private slots:
    void on_LeftPushButton_clicked();
    void on_RightPushButton_clicked();

    void onCellClicked(QString numberCell);

private:
    ModelPost *model;

    QList<QSharedPointer<PostCell> > *cellWidgetList;
    void resizeEvent(QResizeEvent* event);
    Ui::PostWorkAreaWidget *ui;
    QHBoxLayout *layoutScrollArea;
    int countCells;
    int numberWidgetCarriage;
    void init();

    // BaseWorkAreaWidget interface
public:
    QWidget *getWidget();
    void updateSizeWidget();

public slots:
    void updateWorkArea();
};

#endif // POSTWORKAREAWIDGET_H
