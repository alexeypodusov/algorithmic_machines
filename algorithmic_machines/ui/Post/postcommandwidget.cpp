#include "postcommandwidget.h"
#include "ui_postcommandwidget.h"

PostCommandWidget::PostCommandWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PostCommandWidget)
{
    ui->setupUi(this);
}

PostCommandWidget::~PostCommandWidget()
{
    delete ui;
}
