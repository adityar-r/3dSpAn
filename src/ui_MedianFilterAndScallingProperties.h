/********************************************************************************
** Form generated from reading UI file 'MedianFilterAndScallingProperties.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDIANFILTERANDSCALLINGPROPERTIES_H
#define UI_MEDIANFILTERANDSCALLINGPROPERTIES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MedianFilterAndScallingProperties
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QDoubleSpinBox *scalingValueSb;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *kernelSizeCb;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QDialog *MedianFilterAndScallingProperties)
    {
        if (MedianFilterAndScallingProperties->objectName().isEmpty())
            MedianFilterAndScallingProperties->setObjectName(QString::fromUtf8("MedianFilterAndScallingProperties"));
        MedianFilterAndScallingProperties->resize(336, 175);
        verticalLayout = new QVBoxLayout(MedianFilterAndScallingProperties);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(MedianFilterAndScallingProperties);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        scalingValueSb = new QDoubleSpinBox(MedianFilterAndScallingProperties);
        scalingValueSb->setObjectName(QString::fromUtf8("scalingValueSb"));
        scalingValueSb->setDecimals(4);
        scalingValueSb->setMinimum(1.000000000000000);
        scalingValueSb->setMaximum(10.000000000000000);
        scalingValueSb->setSingleStep(0.050000000000000);
        scalingValueSb->setValue(1.150000000000000);

        horizontalLayout_2->addWidget(scalingValueSb);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(MedianFilterAndScallingProperties);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        kernelSizeCb = new QComboBox(MedianFilterAndScallingProperties);
        kernelSizeCb->addItem(QString());
        kernelSizeCb->addItem(QString());
        kernelSizeCb->addItem(QString());
        kernelSizeCb->setObjectName(QString::fromUtf8("kernelSizeCb"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(kernelSizeCb->sizePolicy().hasHeightForWidth());
        kernelSizeCb->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(kernelSizeCb);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pushButton_2 = new QPushButton(MedianFilterAndScallingProperties);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(pushButton_2);

        pushButton = new QPushButton(MedianFilterAndScallingProperties);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(pushButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(MedianFilterAndScallingProperties);

        QMetaObject::connectSlotsByName(MedianFilterAndScallingProperties);
    } // setupUi

    void retranslateUi(QDialog *MedianFilterAndScallingProperties)
    {
        MedianFilterAndScallingProperties->setWindowTitle(QApplication::translate("MedianFilterAndScallingProperties", "Dialog", nullptr));
        label_3->setText(QApplication::translate("MedianFilterAndScallingProperties", "Scaling Value: ", nullptr));
        label->setText(QApplication::translate("MedianFilterAndScallingProperties", "Median Filter Kernel Size:", nullptr));
        kernelSizeCb->setItemText(0, QApplication::translate("MedianFilterAndScallingProperties", "3 x 3 x 3", nullptr));
        kernelSizeCb->setItemText(1, QApplication::translate("MedianFilterAndScallingProperties", "5 x 5 x 5", nullptr));
        kernelSizeCb->setItemText(2, QApplication::translate("MedianFilterAndScallingProperties", "7 x 7 x 7", nullptr));

        pushButton_2->setText(QApplication::translate("MedianFilterAndScallingProperties", "OK", nullptr));
        pushButton->setText(QApplication::translate("MedianFilterAndScallingProperties", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MedianFilterAndScallingProperties: public Ui_MedianFilterAndScallingProperties {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDIANFILTERANDSCALLINGPROPERTIES_H
