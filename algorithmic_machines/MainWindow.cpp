#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <factories/PostFactory.h>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    initHardCode();

}

MainWindow::~MainWindow() {
    commandWidgetList->clear();
    delete commandWidgetList;
    workAreaWidgetList->clear();
    delete workAreaWidgetList;
    delete ui;
}

//пока хардкод
void MainWindow::initHardCode() {
    factory = new PostFactory(this);
    model = factory->createModel(this);
    connect(model, SIGNAL(sendMessage(MessageType, QString, QString)), this, SLOT(receiveMessage(MessageType, QString, QString)));
    connect(model, SIGNAL(changedStatusPlaySignal(StatusPlay)), this, SLOT(onChangedStatusPlay(StatusPlay)));

    commandWidgetList = new QList<QSharedPointer<BaseCommandWidget> >();
    commandWidgetList->append(QSharedPointer<BaseCommandWidget>(factory->createCommandWidget(model)));

    workAreaWidgetList = new QList<QSharedPointer<BaseWorkAreaWidget> >();
    workAreaWidgetList->append(QSharedPointer<BaseWorkAreaWidget>(factory->createWorkAreaWidget(model)));

    ui->tabWorkAreaWidget->addTab(workAreaWidgetList->at(0).data()->getWidget(), "1234");
    ui->tabCommandWidget->addTab(commandWidgetList->at(0).data()->getWidget(), "1234");
    workAreaWidgetList->at(0).data()->updateSizeWidget();

}

void MainWindow::on_pushButtonAddString_clicked()
{
    commandWidgetList->at(ui->tabCommandWidget->currentIndex()).data()->onAddStringClicked();
}

void MainWindow::on_pushButtonDeleteString_clicked()
{
    commandWidgetList->at(ui->tabCommandWidget->currentIndex()).data()->onDeleteStringClicked();
}

void MainWindow::on_actionPlay_triggered()
{
    model->play();
}

void MainWindow::receiveMessage(MessageType messageType, QString text, QString title)
{
    switch (messageType) {
    case MESSAGE_ERROR: {
        QMessageBox::warning(this, title, text);
        break;
    }
    case MESSAGE_INFO: {
        QMessageBox::information(this, title, text);
        break;
    }
    default:
        break;
    }
}

void MainWindow::onChangedStatusPlay(StatusPlay statusPlay)
{
     commandWidgetList->at(ui->tabCommandWidget->currentIndex()).data()->onChangedStatusPlay(statusPlay);
}
