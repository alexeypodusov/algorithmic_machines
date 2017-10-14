#ifndef POSTCOMMANDWIDGET_H
#define POSTCOMMANDWIDGET_H

#include <QWidget>

namespace Ui {
class PostCommandWidget;
}

class PostCommandWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PostCommandWidget(QWidget *parent = 0);
    ~PostCommandWidget();

private:
    Ui::PostCommandWidget *ui;
};

#endif // POSTCOMMANDWIDGET_H
