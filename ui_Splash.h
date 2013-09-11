/********************************************************************************
** Form generated from reading UI file 'Splash.ui'
**
** Created: Tue 3. Apr 10:27:51 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPLASH_H
#define UI_SPLASH_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Splash
{
public:
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *Splash)
    {
        if (Splash->objectName().isEmpty())
            Splash->setObjectName(QString::fromUtf8("Splash"));
        Splash->resize(400, 300);
        label = new QLabel(Splash);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 10, 351, 221));
        label->setPixmap(QPixmap(QString::fromUtf8(":/ressources/logo-cae.png")));
        label_2 = new QLabel(Splash);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(120, 250, 51, 16));

        retranslateUi(Splash);

        QMetaObject::connectSlotsByName(Splash);
    } // setupUi

    void retranslateUi(QWidget *Splash)
    {
        Splash->setWindowTitle(QApplication::translate("Splash", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        label_2->setText(QApplication::translate("Splash", "Loading...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Splash: public Ui_Splash {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPLASH_H
