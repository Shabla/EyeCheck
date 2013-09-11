#ifndef MENUSEQUENCE_H
#define MENUSEQUENCE_H

#include <QDialog>
#include <QToolTip>
#include <QPushButton>
#include <QRegExpValidator>

#include "Regex.h"
#include "PortSettings.h"

namespace Ui
{
    class MenuSequence;
}

class MenuSequence : public QDialog
{
    Q_OBJECT

    private:
        Ui::MenuSequence*   ui;

        PortSettings*       settings;
        QString             lastSequence;
        int                 lastDelay;
        QRegExpValidator*   validator;

        void validInput( QWidget* w );
        void invalidInput( QWidget* w, const QString& msg );

    public:
        explicit MenuSequence( PortSettings* settings, QWidget *parent = 0 );
        ~MenuSequence();

    signals:
        void sequenceChanged();
        void delayChanged();

    private slots:
        void on_plainTextEdit_textChanged();
        void on_lineEdit_textEdited( const QString& arg1 );
        void on_btnReset_clicked();
        void on_btnSave_clicked();
        void on_btnCancel_clicked();
};

#endif // MENUSEQUENCE_H
