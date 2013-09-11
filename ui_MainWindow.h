/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created: Wed 4. Apr 10:37:39 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionSettings;
    QAction *actionTest_sequence;
    QAction *actionAbout;
    QWidget *centralWidget;
    QPushButton *btnSequence;
    QPushButton *btnConnection;
    QTextEdit *textEditConsole;
    QPushButton *btnAdvanced;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_24;
    QLabel *label_22;
    QLabel *label_21;
    QLabel *label_20;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_9;
    QLabel *label_5;
    QLabel *label_11;
    QLabel *label_10;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_19;
    QLabel *label_23;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_18;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_30;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnMinus;
    QPushButton *btnPlus;
    QLabel *label_8;
    QLineEdit *lineEditCommand;
    QComboBox *cmbTarget;
    QLabel *label_2;
    QPushButton *btnSend;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuOptions;
    QMenu *menuHelp;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(585, 350);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(585, 350));
        MainWindow->setMaximumSize(QSize(585, 590));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ressources/logo-cae-white.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/ressources/icon-exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon1);
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/ressources/icon-settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSettings->setIcon(icon2);
        actionTest_sequence = new QAction(MainWindow);
        actionTest_sequence->setObjectName(QString::fromUtf8("actionTest_sequence"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/ressources/icon-test.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTest_sequence->setIcon(icon3);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/ressources/icon-about.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon4);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        btnSequence = new QPushButton(centralWidget);
        btnSequence->setObjectName(QString::fromUtf8("btnSequence"));
        btnSequence->setEnabled(false);
        btnSequence->setGeometry(QRect(10, 70, 128, 128));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/ressources/button-sequence-start.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSequence->setIcon(icon5);
        btnSequence->setIconSize(QSize(120, 120));
        btnConnection = new QPushButton(centralWidget);
        btnConnection->setObjectName(QString::fromUtf8("btnConnection"));
        btnConnection->setGeometry(QRect(10, 10, 128, 50));
        textEditConsole = new QTextEdit(centralWidget);
        textEditConsole->setObjectName(QString::fromUtf8("textEditConsole"));
        textEditConsole->setGeometry(QRect(150, 10, 419, 295));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(100);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(textEditConsole->sizePolicy().hasHeightForWidth());
        textEditConsole->setSizePolicy(sizePolicy1);
        textEditConsole->setReadOnly(true);
        btnAdvanced = new QPushButton(centralWidget);
        btnAdvanced->setObjectName(QString::fromUtf8("btnAdvanced"));
        btnAdvanced->setGeometry(QRect(20, 280, 111, 25));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/ressources/arrow-down.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAdvanced->setIcon(icon6);
        btnAdvanced->setCheckable(false);
        btnAdvanced->setAutoRepeat(false);
        gridLayoutWidget_3 = new QWidget(centralWidget);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(10, 370, 561, 171));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setSpacing(2);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(gridLayoutWidget_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy2);
        label_14->setMinimumSize(QSize(0, 30));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setUnderline(false);
        font.setWeight(75);
        label_14->setFont(font);
        label_14->setFrameShape(QFrame::Box);
        label_14->setFrameShadow(QFrame::Sunken);
        label_14->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_14, 0, 0, 1, 7);

        label_15 = new QLabel(gridLayoutWidget_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy3);
        label_15->setMinimumSize(QSize(25, 0));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label_15->setFont(font1);
        label_15->setFrameShape(QFrame::Box);
        label_15->setFrameShadow(QFrame::Sunken);
        label_15->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_15, 2, 5, 1, 1);

        label_16 = new QLabel(gridLayoutWidget_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        sizePolicy3.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy3);
        label_16->setMinimumSize(QSize(25, 0));
        label_16->setFont(font1);
        label_16->setFrameShape(QFrame::Box);
        label_16->setFrameShadow(QFrame::Sunken);
        label_16->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_16, 3, 5, 1, 1);

        label_17 = new QLabel(gridLayoutWidget_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        sizePolicy3.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy3);
        label_17->setMinimumSize(QSize(25, 0));
        label_17->setFont(font1);
        label_17->setFrameShape(QFrame::Box);
        label_17->setFrameShadow(QFrame::Sunken);
        label_17->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_17, 4, 5, 1, 1);

        label_24 = new QLabel(gridLayoutWidget_3);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_24->sizePolicy().hasHeightForWidth());
        label_24->setSizePolicy(sizePolicy4);
        label_24->setMinimumSize(QSize(0, 25));
        label_24->setFrameShape(QFrame::Box);
        label_24->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(label_24, 2, 6, 1, 1);

        label_22 = new QLabel(gridLayoutWidget_3);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        sizePolicy4.setHeightForWidth(label_22->sizePolicy().hasHeightForWidth());
        label_22->setSizePolicy(sizePolicy4);
        label_22->setMinimumSize(QSize(0, 25));
        label_22->setFrameShape(QFrame::Box);
        label_22->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(label_22, 3, 6, 1, 1);

        label_21 = new QLabel(gridLayoutWidget_3);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        sizePolicy4.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy4);
        label_21->setMinimumSize(QSize(0, 25));
        label_21->setFrameShape(QFrame::Box);
        label_21->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(label_21, 4, 6, 1, 1);

        label_20 = new QLabel(gridLayoutWidget_3);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        sizePolicy4.setHeightForWidth(label_20->sizePolicy().hasHeightForWidth());
        label_20->setSizePolicy(sizePolicy4);
        label_20->setMinimumSize(QSize(0, 25));
        label_20->setFrameShape(QFrame::Box);
        label_20->setFrameShadow(QFrame::Sunken);
        label_20->setWordWrap(true);

        gridLayout_3->addWidget(label_20, 5, 1, 1, 6);

        label_3 = new QLabel(gridLayoutWidget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy3.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy3);
        label_3->setMinimumSize(QSize(25, 0));
        label_3->setFont(font1);
        label_3->setFrameShape(QFrame::Box);
        label_3->setFrameShadow(QFrame::Sunken);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_3, 1, 5, 1, 1);

        label = new QLabel(gridLayoutWidget_3);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy4.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy4);
        label->setMinimumSize(QSize(0, 25));
        label->setFrameShape(QFrame::Box);
        label->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(label, 1, 6, 1, 1);

        label_4 = new QLabel(gridLayoutWidget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy3.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy3);
        label_4->setMinimumSize(QSize(25, 0));
        label_4->setFont(font1);
        label_4->setFrameShape(QFrame::Box);
        label_4->setFrameShadow(QFrame::Sunken);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_4, 1, 0, 1, 1);

        label_6 = new QLabel(gridLayoutWidget_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy3.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy3);
        label_6->setMinimumSize(QSize(25, 0));
        label_6->setFont(font1);
        label_6->setFrameShape(QFrame::Box);
        label_6->setFrameShadow(QFrame::Sunken);
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_6, 2, 0, 1, 1);

        label_9 = new QLabel(gridLayoutWidget_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy3.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy3);
        label_9->setMinimumSize(QSize(25, 0));
        label_9->setFont(font1);
        label_9->setFrameShape(QFrame::Box);
        label_9->setFrameShadow(QFrame::Sunken);
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_9, 3, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMinimumSize(QSize(130, 25));
        label_5->setFrameShape(QFrame::Box);
        label_5->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(label_5, 1, 2, 1, 1);

        label_11 = new QLabel(gridLayoutWidget_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        sizePolicy.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy);
        label_11->setMinimumSize(QSize(130, 25));
        label_11->setFrameShape(QFrame::Box);
        label_11->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(label_11, 2, 2, 1, 1);

        label_10 = new QLabel(gridLayoutWidget_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);
        label_10->setMinimumSize(QSize(130, 25));
        label_10->setFrameShape(QFrame::Box);
        label_10->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(label_10, 3, 2, 1, 1);

        label_12 = new QLabel(gridLayoutWidget_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        sizePolicy3.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy3);
        label_12->setMinimumSize(QSize(25, 0));
        label_12->setFont(font1);
        label_12->setFrameShape(QFrame::Box);
        label_12->setFrameShadow(QFrame::Sunken);
        label_12->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_12, 4, 0, 1, 1);

        label_13 = new QLabel(gridLayoutWidget_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        sizePolicy.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy);
        label_13->setMinimumSize(QSize(130, 25));
        label_13->setFrameShape(QFrame::Box);
        label_13->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(label_13, 4, 2, 1, 1);

        label_19 = new QLabel(gridLayoutWidget_3);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        sizePolicy3.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy3);
        label_19->setMinimumSize(QSize(45, 0));
        label_19->setFrameShape(QFrame::Box);
        label_19->setFrameShadow(QFrame::Sunken);
        label_19->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_19, 1, 1, 1, 1);

        label_23 = new QLabel(gridLayoutWidget_3);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        sizePolicy3.setHeightForWidth(label_23->sizePolicy().hasHeightForWidth());
        label_23->setSizePolicy(sizePolicy3);
        label_23->setMinimumSize(QSize(45, 0));
        label_23->setFrameShape(QFrame::Box);
        label_23->setFrameShadow(QFrame::Sunken);
        label_23->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_23, 2, 1, 1, 1);

        label_25 = new QLabel(gridLayoutWidget_3);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        sizePolicy3.setHeightForWidth(label_25->sizePolicy().hasHeightForWidth());
        label_25->setSizePolicy(sizePolicy3);
        label_25->setMinimumSize(QSize(45, 0));
        label_25->setFrameShape(QFrame::Box);
        label_25->setFrameShadow(QFrame::Sunken);
        label_25->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_25, 3, 1, 1, 1);

        label_26 = new QLabel(gridLayoutWidget_3);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        sizePolicy3.setHeightForWidth(label_26->sizePolicy().hasHeightForWidth());
        label_26->setSizePolicy(sizePolicy3);
        label_26->setMinimumSize(QSize(45, 0));
        label_26->setFrameShape(QFrame::Box);
        label_26->setFrameShadow(QFrame::Sunken);
        label_26->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_26, 4, 1, 1, 1);

        label_18 = new QLabel(gridLayoutWidget_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        sizePolicy.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy);
        label_18->setMinimumSize(QSize(25, 25));
        label_18->setFont(font1);
        label_18->setFrameShape(QFrame::Box);
        label_18->setFrameShadow(QFrame::Sunken);
        label_18->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_18, 5, 0, 1, 1);

        label_27 = new QLabel(gridLayoutWidget_3);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        sizePolicy3.setHeightForWidth(label_27->sizePolicy().hasHeightForWidth());
        label_27->setSizePolicy(sizePolicy3);
        label_27->setMinimumSize(QSize(45, 0));
        label_27->setFrameShape(QFrame::Box);
        label_27->setFrameShadow(QFrame::Sunken);
        label_27->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_27, 1, 3, 1, 1);

        label_28 = new QLabel(gridLayoutWidget_3);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        sizePolicy3.setHeightForWidth(label_28->sizePolicy().hasHeightForWidth());
        label_28->setSizePolicy(sizePolicy3);
        label_28->setMinimumSize(QSize(45, 0));
        label_28->setFrameShape(QFrame::Box);
        label_28->setFrameShadow(QFrame::Sunken);
        label_28->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_28, 2, 3, 1, 1);

        label_29 = new QLabel(gridLayoutWidget_3);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        sizePolicy3.setHeightForWidth(label_29->sizePolicy().hasHeightForWidth());
        label_29->setSizePolicy(sizePolicy3);
        label_29->setMinimumSize(QSize(45, 0));
        label_29->setFrameShape(QFrame::Box);
        label_29->setFrameShadow(QFrame::Sunken);
        label_29->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_29, 3, 3, 1, 1);

        label_30 = new QLabel(gridLayoutWidget_3);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        sizePolicy3.setHeightForWidth(label_30->sizePolicy().hasHeightForWidth());
        label_30->setSizePolicy(sizePolicy3);
        label_30->setMinimumSize(QSize(45, 0));
        label_30->setFrameShape(QFrame::Box);
        label_30->setFrameShadow(QFrame::Sunken);
        label_30->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_30, 4, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(15, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 1, 4, 4, 1);

        btnMinus = new QPushButton(centralWidget);
        btnMinus->setObjectName(QString::fromUtf8("btnMinus"));
        btnMinus->setEnabled(false);
        btnMinus->setGeometry(QRect(20, 320, 40, 40));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/ressources/brightness-dark.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnMinus->setIcon(icon7);
        btnMinus->setIconSize(QSize(36, 36));
        btnPlus = new QPushButton(centralWidget);
        btnPlus->setObjectName(QString::fromUtf8("btnPlus"));
        btnPlus->setEnabled(false);
        btnPlus->setGeometry(QRect(90, 320, 40, 40));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/ressources/brightness-light.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPlus->setIcon(icon8);
        btnPlus->setIconSize(QSize(36, 36));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(150, 318, 81, 20));
        lineEditCommand = new QLineEdit(centralWidget);
        lineEditCommand->setObjectName(QString::fromUtf8("lineEditCommand"));
        lineEditCommand->setEnabled(false);
        lineEditCommand->setGeometry(QRect(150, 343, 338, 20));
        cmbTarget = new QComboBox(centralWidget);
        cmbTarget->setObjectName(QString::fromUtf8("cmbTarget"));
        cmbTarget->setEnabled(false);
        cmbTarget->setGeometry(QRect(408, 317, 80, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(360, 318, 44, 20));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        btnSend = new QPushButton(centralWidget);
        btnSend->setObjectName(QString::fromUtf8("btnSend"));
        btnSend->setEnabled(false);
        btnSend->setGeometry(QRect(495, 315, 75, 50));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 585, 20));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setSizeGripEnabled(false);
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuOptions->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionExit);
        menuOptions->addAction(actionSettings);
        menuOptions->addAction(actionTest_sequence);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);
        QObject::connect(lineEditCommand, SIGNAL(returnPressed()), btnSend, SLOT(click()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "CAE Healthcare - OLED", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "&Exit", 0, QApplication::UnicodeUTF8));
        actionExit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionSettings->setText(QApplication::translate("MainWindow", "&Settings", 0, QApplication::UnicodeUTF8));
        actionSettings->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionTest_sequence->setText(QApplication::translate("MainWindow", "&Test sequence", 0, QApplication::UnicodeUTF8));
        actionTest_sequence->setShortcut(QApplication::translate("MainWindow", "Ctrl+T", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "&About", 0, QApplication::UnicodeUTF8));
        actionAbout->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btnSequence->setToolTip(QApplication::translate("MainWindow", "Start the test sequence", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnSequence->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnConnection->setToolTip(QApplication::translate("MainWindow", "Connect to ports", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnConnection->setText(QApplication::translate("MainWindow", "Connect", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btnAdvanced->setToolTip(QApplication::translate("MainWindow", "Advanced mode allow you to send command manually and choose which port will receive future commands.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnAdvanced->setText(QApplication::translate("MainWindow", "Advanced Mode", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "Available commands", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("MainWindow", "\\27", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("MainWindow", "Increases the display brightness.", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("MainWindow", "Decreases the display brightness.", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("MainWindow", "Blank the display.", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("MainWindow", "Executes a command. A to D commands need to be followed by the ; character to be executed.", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "?", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Device will return \"Ready\" to show it is alive.", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "A", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "B", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "C", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Eye lid position.", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "Horizontal eye position.", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "Vertical eye position.", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "D", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "Pupil dilation.", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("MainWindow", "0 to 8", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("MainWindow", "0 to 4", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("MainWindow", "0 to 2", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("MainWindow", "0 to 2", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("MainWindow", ";", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("MainWindow", "Ex: A2", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("MainWindow", "Ex: B3", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("MainWindow", "Ex: C2", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("MainWindow", "Ex: D0", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btnMinus->setToolTip(QApplication::translate("MainWindow", "Reduce brightness", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnMinus->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnPlus->setToolTip(QApplication::translate("MainWindow", "Augment brightness", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnPlus->setText(QString());
        label_8->setText(QApplication::translate("MainWindow", "Manual command", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Target :", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btnSend->setToolTip(QApplication::translate("MainWindow", "Send a command to the current target.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnSend->setText(QApplication::translate("MainWindow", "Send", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "&File", 0, QApplication::UnicodeUTF8));
        menuOptions->setTitle(QApplication::translate("MainWindow", "Options", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
