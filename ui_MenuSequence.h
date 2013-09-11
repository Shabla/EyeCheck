/********************************************************************************
** Form generated from reading UI file 'MenuSequence.ui'
**
** Created: Wed 4. Apr 10:37:39 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUSEQUENCE_H
#define UI_MENUSEQUENCE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuSequence
{
public:
    QGroupBox *groupBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPlainTextEdit *plainTextEdit;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QPushButton *btnCancel;
    QPushButton *btnSave;
    QPushButton *btnReset;

    void setupUi(QDialog *MenuSequence)
    {
        if (MenuSequence->objectName().isEmpty())
            MenuSequence->setObjectName(QString::fromUtf8("MenuSequence"));
        MenuSequence->setWindowModality(Qt::WindowModal);
        MenuSequence->resize(430, 315);
        MenuSequence->setMinimumSize(QSize(430, 315));
        MenuSequence->setMaximumSize(QSize(430, 315));
        MenuSequence->setModal(true);
        groupBox = new QGroupBox(MenuSequence);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 410, 260));
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
        label_2->setGeometry(QRect(10, 210, 311, 41));
        btnCancel = new QPushButton(MenuSequence);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setGeometry(QRect(342, 280, 80, 23));
        btnSave = new QPushButton(MenuSequence);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setGeometry(QRect(252, 280, 80, 23));
        btnReset = new QPushButton(MenuSequence);
        btnReset->setObjectName(QString::fromUtf8("btnReset"));
        btnReset->setGeometry(QRect(142, 280, 100, 23));

        retranslateUi(MenuSequence);

        QMetaObject::connectSlotsByName(MenuSequence);
    } // setupUi

    void retranslateUi(QDialog *MenuSequence)
    {
        MenuSequence->setWindowTitle(QApplication::translate("MenuSequence", "Test sequence", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MenuSequence", "Test sequence", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MenuSequence", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">This sequence is a succession of commands to be sent to the eye(s) until stopped.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">To start the sequence, click on the blue &quot;Play&quot; button on the main interface, and a second time to stop it.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; f"
                        "ont-size:8pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">These settings can be changed while the sequence is running.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Every command must end with &quot;;&quot; in order to be executed.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Ex. A1;A2B3;A0;A5B4D2;</span></p></body></h"
                        "tml>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MenuSequence", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Sequence timer (1 - 9999 ms)</span></p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-style:italic;\">Time to wait between each command.</span></p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; text-decoration: underline;\">WARNING: A value below 200 might "
                        "freeze the display.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        btnCancel->setText(QApplication::translate("MenuSequence", "Cancel", 0, QApplication::UnicodeUTF8));
        btnSave->setText(QApplication::translate("MenuSequence", "Save", 0, QApplication::UnicodeUTF8));
        btnReset->setText(QApplication::translate("MenuSequence", "Reset to default", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MenuSequence: public Ui_MenuSequence {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUSEQUENCE_H
