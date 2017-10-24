#include "postworkareawidget.h"
#include "ui_postworkareawidget.h"


PostWorkAreaWidget::PostWorkAreaWidget(QWidget *parent, ModelBase *model) :
    QWidget(parent),
    ui(new Ui::PostWorkAreaWidget)
{
    ui->setupUi(this);

    show();
    init();
}

PostWorkAreaWidget::~PostWorkAreaWidget()
{
    delete cellList;
    delete ui;
}

void PostWorkAreaWidget::resizeEvent(QResizeEvent* event)
{
    QSize test = ui->scrollArea->size();
    int test2 = layoutScrollArea->margin();
     //int countCellsInVisible = (size().width()-100) / PostCell::WIDTH_CELL;
    // ui->scrollArea->horizontalScrollBar()->setValue((20-countCellsInVisible/2)*(PostCell::WIDTH_CELL+6));
}

PostWorkAreaWidget::init() {

        if(cellList!=NULL) {
            for(int i=0 ; i<cellList->size() ; i++) {
                delete cellList->at(i).data();
            }
        }
        cellList = new QList<QSharedPointer<PostCell> >();

        int countCells = QApplication::desktop()->width()/PostCell::WIDTH_CELL;


//        if(layoutScrollArea!=NULL) {
//           delete layoutScrollArea;
//        }
        layoutScrollArea = new QHBoxLayout(this);
        QWidget *testWidget = new QWidget();
        for(int i = 0; i<countCells; i++) {
            cellList->append(QSharedPointer<PostCell>(new PostCell(this)));
            layoutScrollArea->addLayout(cellList->at(i).data()->getMainLayout());
            cellList->at(i).data()->getLabel()->setText(QString::number(i));
        }

        testWidget->setLayout(layoutScrollArea);
        ui->scrollArea->setWidget(testWidget);

       //ui->scrollArea->widget()->setLayout(tlayoutScrollArea);

        //ui->scrollArea->horizontalScrollBar()->setValue(200);

}


