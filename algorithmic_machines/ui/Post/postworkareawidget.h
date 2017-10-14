#ifndef POSTWORKAREAWIDGET_H
#define POSTWORKAREAWIDGET_H

#include <QWidget>

namespace Ui {
class PostWorkAreaWidget;
}

class PostWorkAreaWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PostWorkAreaWidget(QWidget *parent = 0);
    ~PostWorkAreaWidget();

private:
    Ui::PostWorkAreaWidget *ui;
};

#endif // POSTWORKAREAWIDGET_H
