/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad_Image;
    QAction *actionSave;
    QAction *actionFuzzy_Segment;
    QAction *actionFuzzy_Distance_Transform;
    QAction *actionFuzzy_Connectivity;
    QAction *actionMorphological_Reconstruction;
    QAction *actionAbout_3dSpAn;
    QAction *actionDocumentation;
    QAction *actionExit;
    QAction *actionShow_Gridlines;
    QAction *actionShow_Seed_Sep;
    QAction *actionShow_Segmented_Spine_Id;
    QAction *actionSave_Analysis;
    QAction *actionSpine;
    QAction *actionDendrite;
    QAction *actionSeparator;
    QAction *actionLoad_Seeds;
    QAction *actionSelect_a_region;
    QAction *actionApply_3D_Median;
    QAction *actionScale;
    QAction *actionSave_ROIProfile;
    QAction *actionSave_All_ROI_Profile;
    QAction *actionLoad_All_ROI_Profile;
    QAction *actionAdvance_Preprocessing;
    QAction *actionRun_Python;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_13;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QSpinBox *spinBox_curX;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_15;
    QSpinBox *spinBox_curY;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_17;
    QSpinBox *spinBox_curZ;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_11;
    QLabel *label_12;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_8;
    QCheckBox *selectRegion;
    QPushButton *crop;
    QCheckBox *showOriginal;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_12;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_4;
    QSpinBox *spinBox_ta;
    QSpinBox *spinBox_tb;
    QSpinBox *spinBox_tbp;
    QFrame *line_11;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_3;
    QComboBox *comboBox;
    QPushButton *pushButton_5;
    QPushButton *deleteseed;
    QVBoxLayout *verticalLayout_10;
    QSpacerItem *verticalSpacer;
    QLabel *label_16;
    QLineEdit *lineEdit;
    QListWidget *ROIList;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton;
    QLineEdit *ROIno;
    QLabel *label_5;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_16;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_14;
    QPushButton *pushButton_test;
    QPushButton *pushButton_4;
    QVBoxLayout *verticalLayout_15;
    QLabel *label_4;
    QLabel *label_itn;
    QLabel *Plabel;
    QProgressBar *progressBar;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_17;
    QPushButton *pushButton_CH;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout_9;
    QLineEdit *lineEditResolution;
    QLabel *label_14;
    QLabel *label_25;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QLabel *sliceLabel;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuDisplay;
    QMenu *menuShow_Seed_Id;
    QMenu *menuHelp;
    QMenu *menuTool;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1031, 975);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMouseTracking(true);
        actionLoad_Image = new QAction(MainWindow);
        actionLoad_Image->setObjectName(QString::fromUtf8("actionLoad_Image"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionFuzzy_Segment = new QAction(MainWindow);
        actionFuzzy_Segment->setObjectName(QString::fromUtf8("actionFuzzy_Segment"));
        actionFuzzy_Segment->setCheckable(true);
        actionFuzzy_Distance_Transform = new QAction(MainWindow);
        actionFuzzy_Distance_Transform->setObjectName(QString::fromUtf8("actionFuzzy_Distance_Transform"));
        actionFuzzy_Distance_Transform->setCheckable(true);
        actionFuzzy_Connectivity = new QAction(MainWindow);
        actionFuzzy_Connectivity->setObjectName(QString::fromUtf8("actionFuzzy_Connectivity"));
        actionFuzzy_Connectivity->setCheckable(true);
        actionMorphological_Reconstruction = new QAction(MainWindow);
        actionMorphological_Reconstruction->setObjectName(QString::fromUtf8("actionMorphological_Reconstruction"));
        actionMorphological_Reconstruction->setCheckable(true);
        actionAbout_3dSpAn = new QAction(MainWindow);
        actionAbout_3dSpAn->setObjectName(QString::fromUtf8("actionAbout_3dSpAn"));
        actionDocumentation = new QAction(MainWindow);
        actionDocumentation->setObjectName(QString::fromUtf8("actionDocumentation"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionShow_Gridlines = new QAction(MainWindow);
        actionShow_Gridlines->setObjectName(QString::fromUtf8("actionShow_Gridlines"));
        actionShow_Gridlines->setCheckable(true);
        actionShow_Seed_Sep = new QAction(MainWindow);
        actionShow_Seed_Sep->setObjectName(QString::fromUtf8("actionShow_Seed_Sep"));
        actionShow_Seed_Sep->setCheckable(true);
        actionShow_Segmented_Spine_Id = new QAction(MainWindow);
        actionShow_Segmented_Spine_Id->setObjectName(QString::fromUtf8("actionShow_Segmented_Spine_Id"));
        actionShow_Segmented_Spine_Id->setCheckable(true);
        actionSave_Analysis = new QAction(MainWindow);
        actionSave_Analysis->setObjectName(QString::fromUtf8("actionSave_Analysis"));
        actionSpine = new QAction(MainWindow);
        actionSpine->setObjectName(QString::fromUtf8("actionSpine"));
        actionSpine->setCheckable(true);
        actionDendrite = new QAction(MainWindow);
        actionDendrite->setObjectName(QString::fromUtf8("actionDendrite"));
        actionDendrite->setCheckable(true);
        actionSeparator = new QAction(MainWindow);
        actionSeparator->setObjectName(QString::fromUtf8("actionSeparator"));
        actionSeparator->setCheckable(true);
        actionLoad_Seeds = new QAction(MainWindow);
        actionLoad_Seeds->setObjectName(QString::fromUtf8("actionLoad_Seeds"));
        actionSelect_a_region = new QAction(MainWindow);
        actionSelect_a_region->setObjectName(QString::fromUtf8("actionSelect_a_region"));
        actionSelect_a_region->setCheckable(true);
        actionApply_3D_Median = new QAction(MainWindow);
        actionApply_3D_Median->setObjectName(QString::fromUtf8("actionApply_3D_Median"));
        actionScale = new QAction(MainWindow);
        actionScale->setObjectName(QString::fromUtf8("actionScale"));
        actionSave_ROIProfile = new QAction(MainWindow);
        actionSave_ROIProfile->setObjectName(QString::fromUtf8("actionSave_ROIProfile"));
        actionSave_All_ROI_Profile = new QAction(MainWindow);
        actionSave_All_ROI_Profile->setObjectName(QString::fromUtf8("actionSave_All_ROI_Profile"));
        actionLoad_All_ROI_Profile = new QAction(MainWindow);
        actionLoad_All_ROI_Profile->setObjectName(QString::fromUtf8("actionLoad_All_ROI_Profile"));
        actionAdvance_Preprocessing = new QAction(MainWindow);
        actionAdvance_Preprocessing->setObjectName(QString::fromUtf8("actionAdvance_Preprocessing"));
        actionRun_Python = new QAction(MainWindow);
        actionRun_Python->setObjectName(QString::fromUtf8("actionRun_Python"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        horizontalLayout_6 = new QHBoxLayout(centralWidget);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        verticalLayout_13->setSizeConstraint(QLayout::SetFixedSize);
        scrollArea_2 = new QScrollArea(centralWidget);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollArea_2->sizePolicy().hasHeightForWidth());
        scrollArea_2->setSizePolicy(sizePolicy1);
        scrollArea_2->setMinimumSize(QSize(300, 0));
        scrollArea_2->setMaximumSize(QSize(250, 16777215));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 277, 951));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox_4 = new QGroupBox(scrollAreaWidgetContents_2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy2);
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        groupBox_4->setFont(font);
        groupBox_4->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_7 = new QVBoxLayout(groupBox_4);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(9, 9, 9, 9);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 10pt \"MS Shell Dlg 2\";"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        spinBox_curX = new QSpinBox(groupBox_4);
        spinBox_curX->setObjectName(QString::fromUtf8("spinBox_curX"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(spinBox_curX->sizePolicy().hasHeightForWidth());
        spinBox_curX->setSizePolicy(sizePolicy3);
        spinBox_curX->setStyleSheet(QString::fromUtf8("font: 8pt \"MS Shell Dlg 2\";"));

        verticalLayout_2->addWidget(spinBox_curX);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_15 = new QLabel(groupBox_4);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font1);
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 10pt \"MS Shell Dlg 2\";"));
        label_15->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_15);

        spinBox_curY = new QSpinBox(groupBox_4);
        spinBox_curY->setObjectName(QString::fromUtf8("spinBox_curY"));
        sizePolicy3.setHeightForWidth(spinBox_curY->sizePolicy().hasHeightForWidth());
        spinBox_curY->setSizePolicy(sizePolicy3);
        spinBox_curY->setStyleSheet(QString::fromUtf8("font: 8pt \"MS Shell Dlg 2\";"));

        verticalLayout_3->addWidget(spinBox_curY);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_17 = new QLabel(groupBox_4);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setFont(font1);
        label_17->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 10pt \"MS Shell Dlg 2\";"));
        label_17->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_17);

        spinBox_curZ = new QSpinBox(groupBox_4);
        spinBox_curZ->setObjectName(QString::fromUtf8("spinBox_curZ"));
        sizePolicy3.setHeightForWidth(spinBox_curZ->sizePolicy().hasHeightForWidth());
        spinBox_curZ->setSizePolicy(sizePolicy3);
        spinBox_curZ->setStyleSheet(QString::fromUtf8("font: 8pt \"MS Shell Dlg 2\";"));
        spinBox_curZ->setMaximum(1000);

        verticalLayout_6->addWidget(spinBox_curZ);


        horizontalLayout->addLayout(verticalLayout_6);


        verticalLayout_7->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_11 = new QLabel(groupBox_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font1);
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 10pt \"MS Shell Dlg 2\";"));

        horizontalLayout_2->addWidget(label_11);

        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        QFont font2;
        font2.setBold(false);
        font2.setWeight(50);
        label_12->setFont(font2);
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_12);


        verticalLayout_7->addLayout(horizontalLayout_2);


        verticalLayout->addWidget(groupBox_4);

        groupBox_2 = new QGroupBox(scrollAreaWidgetContents_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        sizePolicy2.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy2);
        groupBox_2->setMinimumSize(QSize(50, 0));
        groupBox_2->setFont(font);
        verticalLayout_8 = new QVBoxLayout(groupBox_2);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(9, -1, -1, -1);
        selectRegion = new QCheckBox(groupBox_2);
        selectRegion->setObjectName(QString::fromUtf8("selectRegion"));
        selectRegion->setFont(font2);

        verticalLayout_8->addWidget(selectRegion);

        crop = new QPushButton(groupBox_2);
        crop->setObjectName(QString::fromUtf8("crop"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(crop->sizePolicy().hasHeightForWidth());
        crop->setSizePolicy(sizePolicy4);
        crop->setFont(font2);

        verticalLayout_8->addWidget(crop);

        showOriginal = new QCheckBox(groupBox_2);
        showOriginal->setObjectName(QString::fromUtf8("showOriginal"));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(false);
        font3.setWeight(50);
        showOriginal->setFont(font3);
        showOriginal->setChecked(true);

        verticalLayout_8->addWidget(showOriginal);


        verticalLayout->addWidget(groupBox_2);

        groupBox = new QGroupBox(scrollAreaWidgetContents_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        sizePolicy2.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy2);
        groupBox->setFont(font);
        groupBox->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_12 = new QVBoxLayout(groupBox);
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(9, 9, 9, 9);
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetMinimumSize);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy5);
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(126, 125, 124, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_6->setPalette(palette);
        label_6->setFont(font3);
        label_6->setAlignment(Qt::AlignCenter);
        label_6->setWordWrap(true);

        horizontalLayout_3->addWidget(label_6);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy5.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy5);
        QPalette palette1;
        QBrush brush2(QColor(0, 170, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_7->setPalette(palette1);
        label_7->setFont(font3);
        label_7->setAlignment(Qt::AlignCenter);
        label_7->setWordWrap(true);

        horizontalLayout_3->addWidget(label_7);


        verticalLayout_9->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetMinimumSize);
        spinBox_ta = new QSpinBox(groupBox);
        spinBox_ta->setObjectName(QString::fromUtf8("spinBox_ta"));
        sizePolicy4.setHeightForWidth(spinBox_ta->sizePolicy().hasHeightForWidth());
        spinBox_ta->setSizePolicy(sizePolicy4);
        QFont font4;
        font4.setPointSize(8);
        font4.setBold(false);
        font4.setWeight(50);
        spinBox_ta->setFont(font4);
        spinBox_ta->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        spinBox_ta->setMaximum(255);
        spinBox_ta->setSingleStep(1);
        spinBox_ta->setValue(40);

        horizontalLayout_4->addWidget(spinBox_ta);

        spinBox_tb = new QSpinBox(groupBox);
        spinBox_tb->setObjectName(QString::fromUtf8("spinBox_tb"));
        sizePolicy4.setHeightForWidth(spinBox_tb->sizePolicy().hasHeightForWidth());
        spinBox_tb->setSizePolicy(sizePolicy4);
        spinBox_tb->setFont(font4);
        spinBox_tb->setMinimum(0);
        spinBox_tb->setMaximum(255);
        spinBox_tb->setValue(254);

        horizontalLayout_4->addWidget(spinBox_tb);

        spinBox_tbp = new QSpinBox(groupBox);
        spinBox_tbp->setObjectName(QString::fromUtf8("spinBox_tbp"));
        sizePolicy4.setHeightForWidth(spinBox_tbp->sizePolicy().hasHeightForWidth());
        spinBox_tbp->setSizePolicy(sizePolicy4);
        spinBox_tbp->setFont(font4);
        spinBox_tbp->setMaximum(255);
        spinBox_tbp->setValue(255);

        horizontalLayout_4->addWidget(spinBox_tbp);


        verticalLayout_9->addLayout(horizontalLayout_4);


        verticalLayout_12->addLayout(verticalLayout_9);

        line_11 = new QFrame(groupBox);
        line_11->setObjectName(QString::fromUtf8("line_11"));
        line_11->setFrameShape(QFrame::HLine);
        line_11->setFrameShadow(QFrame::Sunken);

        verticalLayout_12->addWidget(line_11);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_11->setSizeConstraint(QLayout::SetMinimumSize);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy4.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy4);
        label_3->setFont(font2);

        verticalLayout_11->addWidget(label_3);

        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        sizePolicy4.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy4);
        comboBox->setFont(font2);

        verticalLayout_11->addWidget(comboBox);

        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        verticalLayout_11->addWidget(pushButton_5);

        deleteseed = new QPushButton(groupBox);
        deleteseed->setObjectName(QString::fromUtf8("deleteseed"));

        verticalLayout_11->addWidget(deleteseed);


        horizontalLayout_5->addLayout(verticalLayout_11);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer);

        label_16 = new QLabel(groupBox);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        sizePolicy5.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy5);
        label_16->setFont(font1);
        label_16->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
"font: 10pt \"MS Shell Dlg 2\";"));

        verticalLayout_10->addWidget(label_16);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy6(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy6);
        lineEdit->setFont(font3);
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout_10->addWidget(lineEdit);


        horizontalLayout_5->addLayout(verticalLayout_10);


        verticalLayout_12->addLayout(horizontalLayout_5);


        verticalLayout->addWidget(groupBox);

        ROIList = new QListWidget(scrollAreaWidgetContents_2);
        ROIList->setObjectName(QString::fromUtf8("ROIList"));
        QSizePolicy sizePolicy7(QSizePolicy::Ignored, QSizePolicy::Expanding);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(ROIList->sizePolicy().hasHeightForWidth());
        ROIList->setSizePolicy(sizePolicy7);
        ROIList->setMouseTracking(true);

        verticalLayout->addWidget(ROIList);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setSizeConstraint(QLayout::SetDefaultConstraint);
        pushButton = new QPushButton(scrollAreaWidgetContents_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy3.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy3);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 10pt \"MS Shell Dlg 2\";\n"
"	color: rgb(0, 0, 0);\n"
"    border: 1px solid #8f8f91;\n"
"    border-radius: 1px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}"));

        horizontalLayout_7->addWidget(pushButton);

        ROIno = new QLineEdit(scrollAreaWidgetContents_2);
        ROIno->setObjectName(QString::fromUtf8("ROIno"));
        sizePolicy6.setHeightForWidth(ROIno->sizePolicy().hasHeightForWidth());
        ROIno->setSizePolicy(sizePolicy6);
        ROIno->setMinimumSize(QSize(50, 0));

        horizontalLayout_7->addWidget(ROIno);

        label_5 = new QLabel(scrollAreaWidgetContents_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy2.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy2);
        QFont font5;
        font5.setPointSize(10);
        label_5->setFont(font5);

        horizontalLayout_7->addWidget(label_5);


        verticalLayout->addLayout(horizontalLayout_7);

        tabWidget = new QTabWidget(scrollAreaWidgetContents_2);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setFont(font);
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_16 = new QVBoxLayout(tab_3);
        verticalLayout_16->setSpacing(6);
        verticalLayout_16->setContentsMargins(11, 11, 11, 11);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setSizeConstraint(QLayout::SetMaximumSize);
        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        pushButton_test = new QPushButton(tab_3);
        pushButton_test->setObjectName(QString::fromUtf8("pushButton_test"));
        sizePolicy4.setHeightForWidth(pushButton_test->sizePolicy().hasHeightForWidth());
        pushButton_test->setSizePolicy(sizePolicy4);
        pushButton_test->setMinimumSize(QSize(82, 25));
        pushButton_test->setFont(font1);
        pushButton_test->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 10pt \"MS Shell Dlg 2\";\n"
"    border: 1px solid #8f8f91;\n"
"    border-radius: 1px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}"));

        verticalLayout_14->addWidget(pushButton_test);

        pushButton_4 = new QPushButton(tab_3);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setEnabled(true);
        sizePolicy4.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy4);
        pushButton_4->setMinimumSize(QSize(82, 25));
        pushButton_4->setFont(font1);
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 10pt \"MS Shell Dlg 2\";\n"
"    border: 1px solid #8f8f91;\n"
"    border-radius: 1px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}"));

        verticalLayout_14->addWidget(pushButton_4);


        horizontalLayout_8->addLayout(verticalLayout_14);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        label_4 = new QLabel(tab_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setFont(font2);
        label_4->setWordWrap(true);

        verticalLayout_15->addWidget(label_4);

        label_itn = new QLabel(tab_3);
        label_itn->setObjectName(QString::fromUtf8("label_itn"));
        label_itn->setFont(font2);
        label_itn->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_itn->setFrameShape(QFrame::Box);

        verticalLayout_15->addWidget(label_itn);


        horizontalLayout_8->addLayout(verticalLayout_15);


        verticalLayout_16->addLayout(horizontalLayout_8);

        Plabel = new QLabel(tab_3);
        Plabel->setObjectName(QString::fromUtf8("Plabel"));
        Plabel->setFont(font2);
        Plabel->setWordWrap(true);

        verticalLayout_16->addWidget(Plabel);

        progressBar = new QProgressBar(tab_3);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        verticalLayout_16->addWidget(progressBar);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        verticalLayout_17 = new QVBoxLayout(tab_4);
        verticalLayout_17->setSpacing(6);
        verticalLayout_17->setContentsMargins(11, 11, 11, 11);
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        pushButton_CH = new QPushButton(tab_4);
        pushButton_CH->setObjectName(QString::fromUtf8("pushButton_CH"));
        QSizePolicy sizePolicy8(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(pushButton_CH->sizePolicy().hasHeightForWidth());
        pushButton_CH->setSizePolicy(sizePolicy8);
        pushButton_CH->setMinimumSize(QSize(82, 30));
        pushButton_CH->setFont(font2);
        pushButton_CH->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    border: 1px solid #8f8f91;\n"
"    border-radius: 1px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}"));

        verticalLayout_17->addWidget(pushButton_CH);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_17->addItem(verticalSpacer_2);

        label = new QLabel(tab_4);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font2);

        verticalLayout_17->addWidget(label);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        lineEditResolution = new QLineEdit(tab_4);
        lineEditResolution->setObjectName(QString::fromUtf8("lineEditResolution"));
        lineEditResolution->setFont(font2);

        horizontalLayout_9->addWidget(lineEditResolution);

        label_14 = new QLabel(tab_4);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_9->addWidget(label_14);


        verticalLayout_17->addLayout(horizontalLayout_9);

        tabWidget->addTab(tab_4, QString());

        verticalLayout->addWidget(tabWidget);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_13->addWidget(scrollArea_2);

        label_25 = new QLabel(centralWidget);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        QFont font6;
        font6.setPointSize(6);
        font6.setItalic(true);
        label_25->setFont(font6);

        verticalLayout_13->addWidget(label_25);


        horizontalLayout_6->addLayout(verticalLayout_13);

        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        QSizePolicy sizePolicy9(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy9);
        scrollArea->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        scrollArea->setMouseTracking(true);
        scrollArea->setStyleSheet(QString::fromUtf8("background-color: rgb(200,200,200);"));
        scrollArea->setFrameShape(QFrame::Box);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 701, 888));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        sliceLabel = new QLabel(scrollAreaWidgetContents);
        sliceLabel->setObjectName(QString::fromUtf8("sliceLabel"));
        sizePolicy.setHeightForWidth(sliceLabel->sizePolicy().hasHeightForWidth());
        sliceLabel->setSizePolicy(sizePolicy);
        sliceLabel->setCursor(QCursor(Qt::ArrowCursor));
        sliceLabel->setMouseTracking(true);
        sliceLabel->setFrameShape(QFrame::NoFrame);
        sliceLabel->setScaledContents(false);

        gridLayout->addWidget(sliceLabel, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_6->addWidget(scrollArea);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1031, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuDisplay = new QMenu(menuBar);
        menuDisplay->setObjectName(QString::fromUtf8("menuDisplay"));
        menuShow_Seed_Id = new QMenu(menuDisplay);
        menuShow_Seed_Id->setObjectName(QString::fromUtf8("menuShow_Seed_Id"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuTool = new QMenu(menuBar);
        menuTool->setObjectName(QString::fromUtf8("menuTool"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuTool->menuAction());
        menuBar->addAction(menuDisplay->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionLoad_Image);
        menuFile->addAction(actionLoad_All_ROI_Profile);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_All_ROI_Profile);
        menuFile->addAction(actionSave_Analysis);
        menuFile->addAction(actionExit);
        menuFile->addSeparator();
        menuDisplay->addAction(actionShow_Gridlines);
        menuDisplay->addAction(actionShow_Seed_Sep);
        menuDisplay->addAction(menuShow_Seed_Id->menuAction());
        menuDisplay->addSeparator();
        menuDisplay->addAction(actionFuzzy_Segment);
        menuDisplay->addAction(actionFuzzy_Distance_Transform);
        menuDisplay->addAction(actionFuzzy_Connectivity);
        menuDisplay->addAction(actionMorphological_Reconstruction);
        menuDisplay->addSeparator();
        menuDisplay->addAction(actionShow_Segmented_Spine_Id);
        menuShow_Seed_Id->addAction(actionSpine);
        menuShow_Seed_Id->addAction(actionDendrite);
        menuShow_Seed_Id->addAction(actionSeparator);
        menuHelp->addAction(actionAbout_3dSpAn);
        menuHelp->addAction(actionDocumentation);
        menuTool->addAction(actionSelect_a_region);
        menuTool->addAction(actionApply_3D_Median);
        menuTool->addSeparator();
        menuTool->addAction(actionAdvance_Preprocessing);
        menuTool->addAction(actionScale);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionLoad_Image->setText(QApplication::translate("MainWindow", "Load Image", nullptr));
        actionSave->setText(QApplication::translate("MainWindow", "Save", nullptr));
        actionFuzzy_Segment->setText(QApplication::translate("MainWindow", "Fuzzy Segment", nullptr));
        actionFuzzy_Distance_Transform->setText(QApplication::translate("MainWindow", "Fuzzy Distance Transform", nullptr));
        actionFuzzy_Connectivity->setText(QApplication::translate("MainWindow", "Fuzzy Connectivity", nullptr));
        actionMorphological_Reconstruction->setText(QApplication::translate("MainWindow", "Morphological Reconstruction", nullptr));
        actionAbout_3dSpAn->setText(QApplication::translate("MainWindow", "About 3dSpAn", nullptr));
        actionDocumentation->setText(QApplication::translate("MainWindow", "Manual", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        actionShow_Gridlines->setText(QApplication::translate("MainWindow", "Show Gridlines", nullptr));
        actionShow_Seed_Sep->setText(QApplication::translate("MainWindow", "Show Seed/Sep", nullptr));
        actionShow_Segmented_Spine_Id->setText(QApplication::translate("MainWindow", "Show Segmented Spine Id", nullptr));
        actionSave_Analysis->setText(QApplication::translate("MainWindow", "Save Analysis", nullptr));
        actionSpine->setText(QApplication::translate("MainWindow", "Spine", nullptr));
        actionDendrite->setText(QApplication::translate("MainWindow", "Dendrite", nullptr));
        actionSeparator->setText(QApplication::translate("MainWindow", "Separator", nullptr));
        actionLoad_Seeds->setText(QApplication::translate("MainWindow", "Load Current ROI Profile", nullptr));
        actionSelect_a_region->setText(QApplication::translate("MainWindow", "Select a region", nullptr));
        actionApply_3D_Median->setText(QApplication::translate("MainWindow", "Default Preprocessing", nullptr));
        actionScale->setText(QApplication::translate("MainWindow", "Scale", nullptr));
        actionSave_ROIProfile->setText(QApplication::translate("MainWindow", "Save Current ROI Profile", nullptr));
        actionSave_All_ROI_Profile->setText(QApplication::translate("MainWindow", "Save All ROI Profile", nullptr));
        actionLoad_All_ROI_Profile->setText(QApplication::translate("MainWindow", "Load All ROI Profile", nullptr));
        actionAdvance_Preprocessing->setText(QApplication::translate("MainWindow", "Advance Preprocessing", nullptr));
        actionRun_Python->setText(QApplication::translate("MainWindow", "Run Python Script", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Current Position", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "CurX", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "CurY", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "CurZ", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "Grey Value (x,y,z):", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "0", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Crop a selected Region", nullptr));
        selectRegion->setText(QApplication::translate("MainWindow", "Select a region", nullptr));
        crop->setText(QApplication::translate("MainWindow", "Crop", nullptr));
        showOriginal->setText(QApplication::translate("MainWindow", "Show Original Image", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "Interactive Preprocessing", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Pure Spine", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Pure Dendrite", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Seeding unit", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "Add Seed", nullptr));
        deleteseed->setText(QApplication::translate("MainWindow", "Delete Seed", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "Seed No.", nullptr));
        lineEdit->setText(QApplication::translate("MainWindow", "0", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Delete ROI", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "ROI No.", nullptr));
        pushButton_test->setText(QApplication::translate("MainWindow", "Execute", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "Iterate", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "No of Iteration", nullptr));
        label_itn->setText(QString());
        Plabel->setText(QApplication::translate("MainWindow", "Execution Status", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Segment", nullptr));
        pushButton_CH->setText(QApplication::translate("MainWindow", "Extract Feature", nullptr));
        label->setText(QApplication::translate("MainWindow", "Resolution", nullptr));
        lineEditResolution->setText(QApplication::translate("MainWindow", "0.069", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Century Gothic'; font-size:10pt; font-weight:600; font-style:italic; color:#000000;\">\316\274m</span></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Analyse", nullptr));
        label_25->setText(QApplication::translate("MainWindow", "\302\251 Subhadip Basu, Jadavpur University, INDIA", nullptr));
        sliceLabel->setText(QString());
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuDisplay->setTitle(QApplication::translate("MainWindow", "Display", nullptr));
        menuShow_Seed_Id->setTitle(QApplication::translate("MainWindow", "Show Seed Id", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", nullptr));
        menuTool->setTitle(QApplication::translate("MainWindow", "Tool", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
