/********************************************************************************
** Form generated from reading UI file 'MenuAbout.ui'
**
** Created: Wed 4. Apr 10:37:39 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUABOUT_H
#define UI_MENUABOUT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MenuAbout
{
public:
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *MenuAbout)
    {
        if (MenuAbout->objectName().isEmpty())
            MenuAbout->setObjectName(QString::fromUtf8("MenuAbout"));
        MenuAbout->setWindowModality(Qt::WindowModal);
        MenuAbout->resize(290, 190);
        MenuAbout->setMinimumSize(QSize(290, 190));
        MenuAbout->setMaximumSize(QSize(290, 190));
        MenuAbout->setSizeGripEnabled(true);
        MenuAbout->setModal(true);
        groupBox = new QGroupBox(MenuAbout);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 270, 170));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(90, 125, 90, 30));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 96, 96));
        label->setPixmap(QPixmap(QString::fromUtf8(":/ressources/logo-cae.png")));
        label->setScaledContents(true);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(130, 30, 131, 81));

        retranslateUi(MenuAbout);

        QMetaObject::connectSlotsByName(MenuAbout);
    } // setupUi

    void retranslateUi(QDialog *MenuAbout)
    {
        MenuAbout->setWindowTitle(QApplication::translate("MenuAbout", "About", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MenuAbout", "About", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MenuAbout", "OK", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        label_2->setText(QApplication::translate("MenuAbout", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600;\">OLED Display Check</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">CAE Healthcare</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Version 4.1</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-bl"
                        "ock-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">2012</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Author: Mathieu Collinge</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MenuAbout: public Ui_MenuAbout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUABOUT_H
