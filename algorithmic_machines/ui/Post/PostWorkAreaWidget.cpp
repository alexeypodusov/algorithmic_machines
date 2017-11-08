#include "PostWorkAreaWidget.h"
#include "ui_postworkareawidget.h"


PostWorkAreaWidget::PostWorkAreaWidget(QWidget *parent, ModelBase *model) :
    QWidget(parent),
    ui(new Ui::PostWorkAreaWidget)
{
    ui->setupUi(this);
    this->model = (ModelPost*)model;
    show();
    init();

}

PostWorkAreaWidget::~PostWorkAreaWidget()
{
    cellList->clear();
    delete cellList;
    delete ui;
}

void PostWorkAreaWidget::resizeEvent(QResizeEvent* event)
{
    updateSizeWidget();
}

PostWorkAreaWidget::init() {

        cellList = new QList<QSharedPointer<PostCell> >();

        countCells = QApplication::desktop()->width()/(PostCell::WIDTH_CELL+6)+100;
        numberCarriage = countCells/2;

        layoutScrollArea = new QHBoxLayout(this);
        for(int i = 0; i<countCells; i++) {
            PostCell *cell = new PostCell(this);
            cellList->append(QSharedPointer<PostCell>(cell));
            layoutScrollArea->addWidget(cell->getCellWidget());
            connect(cell, SIGNAL(buttonClickedSignal(QString)), this, SLOT(onCellClicked(QString)));
        }

        updateWorkArea();
        cellList->at(numberCarriage).data()->setCurrent();

       ui->scrollArea->widget()->setLayout(layoutScrollArea);

}



QWidget *PostWorkAreaWidget::getWidget() {
    return this;
}


void PostWorkAreaWidget::updateSizeWidget() {
    //подобрано эмперическим путем
    int margin = 6;
    int factor = PostCell::WIDTH_CELL+margin;

    int widthScrollArea = ui->scrollArea->size().width();

    int leftCellNumber = numberCarriage-(widthScrollArea/factor)/2;
    ui->scrollArea->horizontalScrollBar()->setValue(leftCellNumber*factor+3);
}

void PostWorkAreaWidget::updateWorkArea() {
    int currentModelCarriage = model->getCurrentCarriage();
    for (int i = 0; i<cellList->size(); i++) {
        int numberCell = currentModelCarriage-(numberCarriage-i);

        if(numberCell >= ModelPost::LEFT_BORDER_TAPE && numberCell <= ModelPost::RIGHT_BORDER_TAPE ) {
            cellList->at(i).data()->getLabel()->setText(QString::number(numberCell));
            cellList->at(i).data()->setMark(model->getMarkByNumberCell(numberCell));
            if(!cellList->at(i).data()->isVisible()) {
                    cellList->at(i).data()->setVisible(true);
            }
        } else {
            cellList->at(i).data()->setVisible(false);
        }
    }
}

void PostWorkAreaWidget::on_LeftPushButton_clicked() {
     model->setCurrentCarriage(model->getCurrentCarriage()-1);
     updateWorkArea();
}

void PostWorkAreaWidget::on_RightPushButton_clicked() {
    model->setCurrentCarriage(model->getCurrentCarriage()+1);
    updateWorkArea();
}

void PostWorkAreaWidget::onCellClicked(QString numberCell) {
    model->changeSell(numberCell.toInt());
    updateWorkArea();
}
