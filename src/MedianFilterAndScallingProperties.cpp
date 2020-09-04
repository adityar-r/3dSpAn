#include "MedianFilterAndScallingProperties.h"
#include "ui_MedianFilterAndScallingProperties.h"

MedianFilterAndScallingProperties::MedianFilterAndScallingProperties(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MedianFilterAndScallingProperties)
{
    ui->setupUi(this);
}

MedianFilterAndScallingProperties::~MedianFilterAndScallingProperties()
{
    delete ui;
}

void MedianFilterAndScallingProperties::on_pushButton_2_clicked()
{
    int kernelSize = 3;
    switch(kernelIndex){
    case 0: kernelSize = 3; break;
    case 1: kernelSize = 5; break;
    case 2: kernelSize = 7; break;
    }

    emit scalingAndKernelSize(ui->scalingValueSb->value(),kernelSize);
//    exit(0);
    hide();
}

void MedianFilterAndScallingProperties::on_pushButton_clicked()
{
    emit operationCanceled();
//    exit(-1);
    hide();
}

void MedianFilterAndScallingProperties::on_kernelSizeCb_currentIndexChanged(int index)
{
    kernelIndex = index;
}
