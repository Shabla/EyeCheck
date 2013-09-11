/********************************************************************************
** Form generated from reading UI file 'TestSequence.ui'
**
** Created: Thu 23. Feb 10:31:54 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTSEQUENCE_H
#define UI_TESTSEQUENCE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestSequence
{
public:
    QGroupBox *groupBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPlainTextEdit *plainTextEdit;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *TestSequence)
    {
        if (TestSequence->objectName().isEmpty())
            TestSequence->setObjectName(QString::fromUtf8("TestSequence"));
        TestSequence->resize(439, 332);
        groupBox = new QGroupBox(TestSequence);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 411, 261));
        verticalLayoutWidget = new QWidget(groupBox);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(9, 19, 391, 181));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label->setWordWrap(true);

        verticalLayout->addWidget(label);

        plainTextEdit = new QPlainTextEdit(verticalLayoutWidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        verticalLayout->addWidget(plainTextEdit);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(340, 220, 61, 20));
        lineEdit->setMaxLength(5);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 210, 311, 31));
        buttonBox = new QDialogButtonBox(TestSequence);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 290, 389, 23));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(TestSequence);
        QObject::connect(buttonBox, SIGNAL(accepted()), TestSequence, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), TestSequence, SLOT(reject()));

        QMetaObject::connectSlotsByName(TestSequence);
    } // setupUi

    void retranslateUi(QDialog *TestSequence)
    {
        TestSequence->setWindowTitle(QApplication::translate("TestSequence", "Test sequence", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("TestSequence", "Test sequence", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TestSequence", "This sequence is a succession of commands to be sent to the eye until stopped.\n"
"To start the sequence, click on the green looping arrow button on the main interface, and a second time to stop it.\n"
"\n"
"Every command must end with \";\" in order to be executed.\n"
"\n"
"Ex. A1;A2B3;A0;A5B4D2;", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("TestSequence", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Sequence timer (0 - 99999 ms)</span></p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-style:italic;\">Time to wait between each command.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MenuSequence: public Ui_TestSequence {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTSEQUENCE_H
