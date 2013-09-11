/********************************************************************************
** Form generated from reading UI file 'MenuSettings.ui'
**
** Created: Wed 4. Apr 10:37:39 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUSETTINGS_H
#define UI_MENUSETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuSettings
{
public:
    QGroupBox *groupBox;
    QWidget *formLayoutWidget_3;
    QFormLayout *formLayout_3;
    QLabel *bitsPerSecondLabel;
    QLabel *dataBitsLabel;
    QLabel *parityLabel;
    QLabel *stopBitsLabel;
    QLabel *flowControlLabel;
    QComboBox *cmbBps;
    QComboBox *cmbDataBits;
    QComboBox *cmbParity;
    QComboBox *cmbStopBits;
    QComboBox *cmbFlowControl;
    QGroupBox *groupBox_2;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QComboBox *cmbPorts;
    QLabel *serialPortLabel;
    QCheckBox *chkAutoConnect;
    QRadioButton *radioAll;
    QRadioButton *radioSingle;
    QLabel *label;
    QGroupBox *groupBox_3;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QCheckBox *chkVerifManCom;
    QCheckBox *chkVerifSeq;
    QPushButton *btnReset;
    QPushButton *btnOk;
    QPushButton *btnCancel;

    void setupUi(QDialog *MenuSettings)
    {
        if (MenuSettings->objectName().isEmpty())
            MenuSettings->setObjectName(QString::fromUtf8("MenuSettings"));
        MenuSettings->setWindowModality(Qt::WindowModal);
        MenuSettings->resize(230, 435);
        MenuSettings->setMinimumSize(QSize(230, 435));
        MenuSettings->setMaximumSize(QSize(230, 435));
        MenuSettings->setModal(true);
        groupBox = new QGroupBox(MenuSettings);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 210, 151));
        formLayoutWidget_3 = new QWidget(groupBox);
        formLayoutWidget_3->setObjectName(QString::fromUtf8("formLayoutWidget_3"));
        formLayoutWidget_3->setGeometry(QRect(10, 20, 191, 131));
        formLayout_3 = new QFormLayout(formLayoutWidget_3);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        bitsPerSecondLabel = new QLabel(formLayoutWidget_3);
        bitsPerSecondLabel->setObjectName(QString::fromUtf8("bitsPerSecondLabel"));
        bitsPerSecondLabel->setMinimumSize(QSize(0, 0));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, bitsPerSecondLabel);

        dataBitsLabel = new QLabel(formLayoutWidget_3);
        dataBitsLabel->setObjectName(QString::fromUtf8("dataBitsLabel"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, dataBitsLabel);

        parityLabel = new QLabel(formLayoutWidget_3);
        parityLabel->setObjectName(QString::fromUtf8("parityLabel"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, parityLabel);

        stopBitsLabel = new QLabel(formLayoutWidget_3);
        stopBitsLabel->setObjectName(QString::fromUtf8("stopBitsLabel"));

        formLayout_3->setWidget(3, QFormLayout::LabelRole, stopBitsLabel);

        flowControlLabel = new QLabel(formLayoutWidget_3);
        flowControlLabel->setObjectName(QString::fromUtf8("flowControlLabel"));

        formLayout_3->setWidget(4, QFormLayout::LabelRole, flowControlLabel);

        cmbBps = new QComboBox(formLayoutWidget_3);
        cmbBps->setObjectName(QString::fromUtf8("cmbBps"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cmbBps->sizePolicy().hasHeightForWidth());
        cmbBps->setSizePolicy(sizePolicy);
        cmbBps->setMinimumSize(QSize(100, 0));
        cmbBps->setFocusPolicy(Qt::ClickFocus);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, cmbBps);

        cmbDataBits = new QComboBox(formLayoutWidget_3);
        cmbDataBits->setObjectName(QString::fromUtf8("cmbDataBits"));
        sizePolicy.setHeightForWidth(cmbDataBits->sizePolicy().hasHeightForWidth());
        cmbDataBits->setSizePolicy(sizePolicy);
        cmbDataBits->setMinimumSize(QSize(100, 0));
        cmbDataBits->setFocusPolicy(Qt::ClickFocus);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, cmbDataBits);

        cmbParity = new QComboBox(formLayoutWidget_3);
        cmbParity->setObjectName(QString::fromUtf8("cmbParity"));
        sizePolicy.setHeightForWidth(cmbParity->sizePolicy().hasHeightForWidth());
        cmbParity->setSizePolicy(sizePolicy);
        cmbParity->setMinimumSize(QSize(100, 0));
        cmbParity->setFocusPolicy(Qt::ClickFocus);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, cmbParity);

        cmbStopBits = new QComboBox(formLayoutWidget_3);
        cmbStopBits->setObjectName(QString::fromUtf8("cmbStopBits"));
        sizePolicy.setHeightForWidth(cmbStopBits->sizePolicy().hasHeightForWidth());
        cmbStopBits->setSizePolicy(sizePolicy);
        cmbStopBits->setMinimumSize(QSize(100, 0));
        cmbStopBits->setFocusPolicy(Qt::ClickFocus);

        formLayout_3->setWidget(3, QFormLayout::FieldRole, cmbStopBits);

        cmbFlowControl = new QComboBox(formLayoutWidget_3);
        cmbFlowControl->setObjectName(QString::fromUtf8("cmbFlowControl"));
        sizePolicy.setHeightForWidth(cmbFlowControl->sizePolicy().hasHeightForWidth());
        cmbFlowControl->setSizePolicy(sizePolicy);
        cmbFlowControl->setMinimumSize(QSize(100, 0));
        cmbFlowControl->setFocusPolicy(Qt::ClickFocus);

        formLayout_3->setWidget(4, QFormLayout::FieldRole, cmbFlowControl);

        groupBox_2 = new QGroupBox(MenuSettings);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 170, 211, 111));
        gridLayoutWidget = new QWidget(groupBox_2);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 20, 191, 87));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        cmbPorts = new QComboBox(gridLayoutWidget);
        cmbPorts->setObjectName(QString::fromUtf8("cmbPorts"));
        cmbPorts->setEnabled(true);
        sizePolicy.setHeightForWidth(cmbPorts->sizePolicy().hasHeightForWidth());
        cmbPorts->setSizePolicy(sizePolicy);
        cmbPorts->setMinimumSize(QSize(100, 0));
        cmbPorts->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(cmbPorts, 2, 1, 1, 1);

        serialPortLabel = new QLabel(gridLayoutWidget);
        serialPortLabel->setObjectName(QString::fromUtf8("serialPortLabel"));
        serialPortLabel->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(serialPortLabel->sizePolicy().hasHeightForWidth());
        serialPortLabel->setSizePolicy(sizePolicy1);
        serialPortLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(serialPortLabel, 2, 0, 1, 1);

        chkAutoConnect = new QCheckBox(gridLayoutWidget);
        chkAutoConnect->setObjectName(QString::fromUtf8("chkAutoConnect"));

        gridLayout->addWidget(chkAutoConnect, 3, 0, 1, 2);

        radioAll = new QRadioButton(gridLayoutWidget);
        radioAll->setObjectName(QString::fromUtf8("radioAll"));
        radioAll->setChecked(true);

        gridLayout->addWidget(radioAll, 1, 0, 1, 1);

        radioSingle = new QRadioButton(gridLayoutWidget);
        radioSingle->setObjectName(QString::fromUtf8("radioSingle"));

        gridLayout->addWidget(radioSingle, 1, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 2);

        groupBox_3 = new QGroupBox(MenuSettings);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 290, 210, 70));
        verticalLayoutWidget = new QWidget(groupBox_3);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 20, 191, 51));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        chkVerifManCom = new QCheckBox(verticalLayoutWidget);
        chkVerifManCom->setObjectName(QString::fromUtf8("chkVerifManCom"));

        verticalLayout->addWidget(chkVerifManCom);

        chkVerifSeq = new QCheckBox(verticalLayoutWidget);
        chkVerifSeq->setObjectName(QString::fromUtf8("chkVerifSeq"));

        verticalLayout->addWidget(chkVerifSeq);

        btnReset = new QPushButton(MenuSettings);
        btnReset->setObjectName(QString::fromUtf8("btnReset"));
        btnReset->setGeometry(QRect(10, 370, 210, 25));
        btnOk = new QPushButton(MenuSettings);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));
        btnOk->setGeometry(QRect(10, 400, 102, 25));
        btnCancel = new QPushButton(MenuSettings);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setGeometry(QRect(118, 400, 102, 25));

        retranslateUi(MenuSettings);

        QMetaObject::connectSlotsByName(MenuSettings);
    } // setupUi

    void retranslateUi(QDialog *MenuSettings)
    {
        MenuSettings->setWindowTitle(QApplication::translate("MenuSettings", "Settings", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MenuSettings", "Port settings", 0, QApplication::UnicodeUTF8));
        bitsPerSecondLabel->setText(QApplication::translate("MenuSettings", "Bits per second :", 0, QApplication::UnicodeUTF8));
        dataBitsLabel->setText(QApplication::translate("MenuSettings", "Data bits :", 0, QApplication::UnicodeUTF8));
        parityLabel->setText(QApplication::translate("MenuSettings", "Parity :", 0, QApplication::UnicodeUTF8));
        stopBitsLabel->setText(QApplication::translate("MenuSettings", "Stop bits :", 0, QApplication::UnicodeUTF8));
        flowControlLabel->setText(QApplication::translate("MenuSettings", "Flow control :", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MenuSettings", "Connection", 0, QApplication::UnicodeUTF8));
        serialPortLabel->setText(QApplication::translate("MenuSettings", "Serial Port :", 0, QApplication::UnicodeUTF8));
        chkAutoConnect->setText(QApplication::translate("MenuSettings", "Connect on start-up", 0, QApplication::UnicodeUTF8));
        radioAll->setText(QApplication::translate("MenuSettings", "All ports", 0, QApplication::UnicodeUTF8));
        radioSingle->setText(QApplication::translate("MenuSettings", "Single port", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MenuSettings", "Connect to :", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MenuSettings", "Other", 0, QApplication::UnicodeUTF8));
        chkVerifManCom->setText(QApplication::translate("MenuSettings", "Validate manual commands", 0, QApplication::UnicodeUTF8));
        chkVerifSeq->setText(QApplication::translate("MenuSettings", "Validate test sequence", 0, QApplication::UnicodeUTF8));
        btnReset->setText(QApplication::translate("MenuSettings", "Reset to default settings", 0, QApplication::UnicodeUTF8));
        btnOk->setText(QApplication::translate("MenuSettings", "OK", 0, QApplication::UnicodeUTF8));
        btnCancel->setText(QApplication::translate("MenuSettings", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MenuSettings: public Ui_MenuSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUSETTINGS_H
