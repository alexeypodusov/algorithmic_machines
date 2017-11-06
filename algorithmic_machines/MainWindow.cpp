#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <factories/PostFactory.h>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    initHardCode();

}

MainWindow::~MainWindow() {
    delete commandWidgetList;
    delete workAreaWidgetList;
    delete ui;
}

//пока хардкод
MainWindow::initHardCode() {
    factory = new PostFactory(this);
    model = factory->createModel(this);

    commandWidgetList = new QList<QSharedPointer<BaseCommandWidget> >();
    commandWidgetList->append(QSharedPointer<BaseCommandWidget>(factory->createCommandWidget(this, model)));

    workAreaWidgetList = new QList<QSharedPointer<BaseWorkAreaWidget> >();
    workAreaWidgetList->append(QSharedPointer<BaseWorkAreaWidget>(factory->createWorkAreaWidget(this, model)));

    ui->tabWorkAreaWidget->addTab(workAreaWidgetList->at(0).data()->getWidget(), "1234");
    workAreaWidgetList->at(0).data()->updateSizeWidget();
    ui->tabCommandWidget->addTab(commandWidgetList->at(0).data()->getWidget(), "1234");

}

void MainWindow::on_pushButtonAddString_clicked()
{
    commandWidgetList->at(ui->tabCommandWidget->currentIndex()).data()->onAddStringClicked();
}
