#include "postworkareawidget.h"
#include "ui_postworkareawidget.h"

PostWorkAreaWidget::PostWorkAreaWidget(QWidget *parent, ModelBase *model) :
    QWidget(parent),
    ui(new Ui::PostWorkAreaWidget)
{
    ui->setupUi(this);
    init();
}

PostWorkAreaWidget::~PostWorkAreaWidget()
{
    delete ui;
}

PostWorkAreaWidget::init() {
    int width = ui->cellsWithSpacersLayout->geometry().width();
    int countCells = width/PostCell::WIDTH_CELL;

    cellList = new QList<QSharedPointer<PostCell>>();

    for(int i = 0; i<countCells; i++) {
        cellList->append(QSharedPointer<PostCell>(new PostCell(this)));
        ui->cellsLayout->addLayout(cellList->at(i).data()->getMainLayout());
    }

}
