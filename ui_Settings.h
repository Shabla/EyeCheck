/********************************************************************************
** Form generated from reading UI file 'Settings.ui'
**
** Created: Thu 23. Feb 16:28:15 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *portLabel;
    QLineEdit *portLineEdit;
    QLabel *bitsPerSecondLabel;
    QComboBox *bitsPerSecondComboBox;
    QLabel *dataBitsLabel;
    QComboBox *dataBitsComboBox;
    QLabel *parityLabel;
    QComboBox *parityComboBox;
    QLabel *stopBitsLabel;
    QComboBox *stopBitsComboBox;
    QLabel *flowControlLabel;
    QComboBox *flowControlComboBox;
    QLabel *label;
    QSlider *horizontalSlider;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QString::fromUtf8("Settings"));
        Settings->setWindowModality(Qt::WindowModal);
        Settings->resize(242, 301);
        Settings->setModal(true);
        buttonBox = new QDialogButtonBox(Settings);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 260, 221, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox = new QGroupBox(Settings);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 221, 241));
        formLayoutWidget = new QWidget(groupBox);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 20, 201, 211));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setHorizontalSpacing(10);
        formLayout->setVerticalSpacing(10);
        formLayout->setContentsMargins(0, 0, 0, 0);
        portLabel = new QLabel(formLayoutWidget);
        portLabel->setObjectName(QString::fromUtf8("portLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, portLabel);

        portLineEdit = new QLineEdit(formLayoutWidget);
        portLineEdit->setObjectName(QString::fromUtf8("portLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, portLineEdit);

        bitsPerSecondLabel = new QLabel(formLayoutWidget);
        bitsPerSecondLabel->setObjectName(QString::fromUtf8("bitsPerSecondLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, bitsPerSecondLabel);

        bitsPerSecondComboBox = new QComboBox(formLayoutWidget);
        bitsPerSecondComboBox->setObjectName(QString::fromUtf8("bitsPerSecondComboBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, bitsPerSecondComboBox);

        dataBitsLabel = new QLabel(formLayoutWidget);
        dataBitsLabel->setObjectName(QString::fromUtf8("dataBitsLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, dataBitsLabel);

        dataBitsComboBox = new QComboBox(formLayoutWidget);
        dataBitsComboBox->setObjectName(QString::fromUtf8("dataBitsComboBox"));

        formLayout->setWidget(2, QFormLayout::FieldRole, dataBitsComboBox);

        parityLabel = new QLabel(formLayoutWidget);
        parityLabel->setObjectName(QString::fromUtf8("parityLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, parityLabel);

        parityComboBox = new QComboBox(formLayoutWidget);
        parityComboBox->setObjectName(QString::fromUtf8("parityComboBox"));

        formLayout->setWidget(3, QFormLayout::FieldRole, parityComboBox);

        stopBitsLabel = new QLabel(formLayoutWidget);
        stopBitsLabel->setObjectName(QString::fromUtf8("stopBitsLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, stopBitsLabel);

        stopBitsComboBox = new QComboBox(formLayoutWidget);
        stopBitsComboBox->setObjectName(QString::fromUtf8("stopBitsComboBox"));

        formLayout->setWidget(4, QFormLayout::FieldRole, stopBitsComboBox);

        flowControlLabel = new QLabel(formLayoutWidget);
        flowControlLabel->setObjectName(QString::fromUtf8("flowControlLabel"));

        formLayout->setWidget(5, QFormLayout::LabelRole, flowControlLabel);

        flowControlComboBox = new QComboBox(formLayoutWidget);
        flowControlComboBox->setObjectName(QString::fromUtf8("flowControlComboBox"));

        formLayout->setWidget(5, QFormLayout::FieldRole, flowControlComboBox);

        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label);

        horizontalSlider = new QSlider(formLayoutWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMinimum(0);
        horizontalSlider->setMaximum(16);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksAbove);
        horizontalSlider->setTickInterval(1);

        formLayout->setWidget(6, QFormLayout::FieldRole, horizontalSlider);


        retranslateUi(Settings);
        QObject::connect(buttonBox, SIGNAL(accepted()), Settings, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Settings, SLOT(reject()));

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "Settings", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Settings", "Start up values", 0, QApplication::UnicodeUTF8));
        portLabel->setText(QApplication::translate("Settings", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Port :</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        bitsPerSecondLabel->setText(QApplication::translate("Settings", "Bits per second :", 0, QApplication::UnicodeUTF8));
        dataBitsLabel->setText(QApplication::translate("Settings", "Data bits :", 0, QApplication::UnicodeUTF8));
        parityLabel->setText(QApplication::translate("Settings", "Parity :", 0, QApplication::UnicodeUTF8));
        stopBitsLabel->setText(QApplication::translate("Settings", "Stop bits :", 0, QApplication::UnicodeUTF8));
        flowControlLabel->setText(QApplication::translate("Settings", "Flow control :", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Settings", "Brightness :", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MenuSettings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
