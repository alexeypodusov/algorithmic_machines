#ifndef POSTWORKAREAWIDGET_H
#define POSTWORKAREAWIDGET_H

#include "postcell.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <qlabel.h>

#include <ui/baseworkareawidget.h>

#include <models/modelbase.h>
#include <qDebug.h>

namespace Ui {
class PostWorkAreaWidget;
}

class PostWorkAreaWidget : public QWidget, BaseWorkAreaWidget
{
    Q_OBJECT

public:
    explicit PostWorkAreaWidget(QWidget *parent, ModelBase *model);
    ~PostWorkAreaWidget();

private:
    QList<QSharedPointer<PostCell>> *cellList;

    Ui::PostWorkAreaWidget *ui;
    init();
};

#endif // POSTWORKAREAWIDGET_H
