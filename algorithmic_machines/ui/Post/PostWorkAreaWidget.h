#ifndef POSTWORKAREAWIDGET_H
#define POSTWORKAREAWIDGET_H

#include "postcell.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <qlabel.h>

#include <ui/baseworkareawidget.h>
#include <QResizeEvent>
#include <QScrollBar>
#include <models/modelbase.h>
#include <qDebug.h>
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
    explicit PostWorkAreaWidget(QWidget *parent, ModelBase *model);
    ~PostWorkAreaWidget();

private slots:

private:
    QList<QSharedPointer<PostCell> > *cellList;
    void resizeEvent(QResizeEvent *event);
    Ui::PostWorkAreaWidget *ui;
    QHBoxLayout *layoutScrollArea;
    init();
};

#endif // POSTWORKAREAWIDGET_H
