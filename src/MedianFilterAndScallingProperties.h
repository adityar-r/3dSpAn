#ifndef MEDIANFILTERANDSCALLINGPROPERTIES_H
#define MEDIANFILTERANDSCALLINGPROPERTIES_H

#include <QDialog>

namespace Ui {
class MedianFilterAndScallingProperties;
}

class MedianFilterAndScallingProperties : public QDialog
{
    Q_OBJECT

public:
    explicit MedianFilterAndScallingProperties(QWidget *parent = nullptr);
    ~MedianFilterAndScallingProperties();
    private slots:
        void on_pushButton_2_clicked();

        void on_pushButton_clicked();

        void on_kernelSizeCb_currentIndexChanged(int index);

signals:
    void scalingAndKernelSize(double scaleFactor, int kernelSize);
    void operationCanceled();

private:
    Ui::MedianFilterAndScallingProperties *ui;
    int kernelIndex = 0;
};

#endif // MEDIANFILTERANDSCALLINGPROPERTIES_H
