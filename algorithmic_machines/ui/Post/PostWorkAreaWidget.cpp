#include "PostWorkAreaWidget.h"
#include "ui_PostWorkAreaWidget.h"


PostWorkAreaWidget::PostWorkAreaWidget(ModelBase *model) :
    QWidget(0),
    ui(new Ui::PostWorkAreaWidget)
{
    ui->setupUi(this);
    this->model = (ModelPost*)model;
    connect(this->model, SIGNAL(cellsListChanded()), this, SLOT(updateWorkArea()));
    show();
    init();

}

PostWorkAreaWidget::~PostWorkAreaWidget()
{
    cellWidgetList->clear();
    delete cellWidgetList;
    delete ui;
}

void PostWorkAreaWidget::init() {

        cellWidgetList = new QList<QSharedPointer<PostCell> >();

        countCells = QApplication::desktop()->width()/(PostCell::WIDTH_CELL+6)+100;
        numberWidgetCarriage = countCells/2;

        layoutScrollArea = new QHBoxLayout(this);

        for(int i = 0; i<countCells; i++) {
            PostCell *cell = new PostCell();
            cellWidgetList->append(QSharedPointer<PostCell>(cell));
            layoutScrollArea->addWidget(cell->getCellWidget());
            connect(cell, SIGNAL(buttonClickedSignal(QString)), this, SLOT(onCellClicked(QString)));
        }

        ui->scrollArea->widget()->setLayout(layoutScrollArea);
        updateWorkArea();
        cellWidgetList->at(numberWidgetCarriage).data()->setCurrent();

}



QWidget *PostWorkAreaWidget::getWidget() {
    return this;
}


void PostWorkAreaWidget::updateSizeWidget() {
    //подобрано эмперическим путем
    int margin = 6;
    int factor = PostCell::WIDTH_CELL + margin;

    int widthScrollArea = ui->scrollArea->size().width();

    int leftCellNumber = numberWidgetCarriage-(widthScrollArea/factor)/2;

    ui->scrollArea->horizontalScrollBar()->setMaximum(factor * countCells);
    ui->scrollArea->horizontalScrollBar()->setValue(leftCellNumber*factor+3);
}

void PostWorkAreaWidget::resizeEvent(QResizeEvent *event)
{
    updateSizeWidget();
}

void PostWorkAreaWidget::updateWorkArea() {
    int currentModelCarriage = model->getCurrentCarriage();
    for (int i = 0; i<cellWidgetList->size(); i++) {

        //numberCarriage - порядокый номер ячейки виджета в layout, на которой находится каретка
        //numberCell - порядковый номер яйчеки в ленте
        int numberCell = currentModelCarriage-(numberWidgetCarriage-i);

        if(numberCell >= ModelPost::LEFT_BORDER_TAPE && numberCell <= ModelPost::RIGHT_BORDER_TAPE ) {
            cellWidgetList->at(i).data()->getLabel()->setText(QString::number(numberCell));
            cellWidgetList->at(i).data()->setMark(model->getMarkByNumberCell(numberCell));
            if(!cellWidgetList->at(i).data()->isVisible()) {
                    cellWidgetList->at(i).data()->setVisible(true);
            }
        } else {
            cellWidgetList->at(i).data()->setVisible(false);
        }
    }
}

void PostWorkAreaWidget::on_LeftPushButton_clicked() {
     model->setCurrentCarriage(model->getCurrentCarriage()-1);

}

void PostWorkAreaWidget::on_RightPushButton_clicked() {
    model->setCurrentCarriage(model->getCurrentCarriage()+1);
}

void PostWorkAreaWidget::onCellClicked(QString numberCell) {
    model->changeSell(numberCell.toInt());
}
