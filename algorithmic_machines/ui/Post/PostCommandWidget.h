#ifndef POSTCOMMANDWIDGET_H
#define POSTCOMMANDWIDGET_H

#include <QWidget>

#include <ui/BaseCommandWidget.h>

#include <models/ModelBase.h>

namespace Ui {
class PostCommandWidget;
}

class PostCommandWidget : public QWidget, BaseCommandWidget
{
    Q_OBJECT

public:
    explicit PostCommandWidget(QWidget *parent, ModelBase *model);
    ~PostCommandWidget();

private:
    Ui::PostCommandWidget *ui;
};

#endif // POSTCOMMANDWIDGET_H
