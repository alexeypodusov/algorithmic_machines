#include "postworkareawidget.h"
#include "ui_postworkareawidget.h"

PostWorkAreaWidget::PostWorkAreaWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PostWorkAreaWidget)
{
    ui->setupUi(this);
}

PostWorkAreaWidget::~PostWorkAreaWidget()
{
    delete ui;
}
