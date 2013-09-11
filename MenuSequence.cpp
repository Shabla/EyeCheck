#include "MenuSequence.h"
#include "ui_MenuSequence.h"

#include <QDebug>

MenuSequence::MenuSequence( PortSettings* settings, QWidget *parent ) : QDialog( parent ), ui( new Ui::MenuSequence )
{
    ui->setupUi(this);

    this->setWindowFlags( this->windowFlags() & ~Qt::WindowContextHelpButtonHint );

    this->settings = settings;

    lastSequence = settings->value( "sequence" ).toString();
    lastDelay = settings->value( "sequenceDelay" ).toInt();

    ui->plainTextEdit->setPlainText( settings->value("sequence").toString() );
    ui->lineEdit->setText( settings->value("sequenceDelay").toString() );
    validator = new QRegExpValidator( QRegExp( REGEX_SEQUENCEDELAY ) );
    ui->lineEdit->setValidator( validator );

    on_plainTextEdit_textChanged();
}

MenuSequence::~MenuSequence()
{
    delete ui;
    delete validator;
}

void MenuSequence::on_plainTextEdit_textChanged()
{
    if( settings->value( "validationSequence").toBool() ) // if validation is activated
    {
        if( !Regex::isValid( REGEX_SEQUENCE, ui->plainTextEdit->toPlainText() ) ) // doesn't match
            invalidInput( ui->plainTextEdit, "This sequence is invalid." );
        else
            validInput( ui->plainTextEdit );
    }
}

void MenuSequence::on_lineEdit_textEdited( const QString &arg1 )
{
    if( !Regex::isValid( REGEX_SEQUENCEDELAY, ui->lineEdit->text() ) ) // doesn't match
        invalidInput( ui->lineEdit, "This timer is invalid." );
    else
        validInput( ui->lineEdit );
}

void MenuSequence::invalidInput( QWidget* w, const QString& msg )
{
    QString className = w->metaObject()->className();
    w->setStyleSheet( className + " { border: 2px solid red; } ");
    QToolTip::showText( w->mapToGlobal( QPoint() ), msg, this->parentWidget(), this->parentWidget()->geometry() );
    ui->btnSave->setEnabled( false );
}

void MenuSequence::validInput( QWidget* w )
{
    w->setStyleSheet("");
    QToolTip::hideText();
    ui->btnSave->setEnabled( true );
}

void MenuSequence::on_btnReset_clicked()
{
    ui->plainTextEdit->setPlainText( settings->getDefault( "sequence" ).toString() );
    ui->lineEdit->setText( settings->getDefault( "sequenceDelay" ).toString() );
    validInput( ui->lineEdit );
    validInput( ui->plainTextEdit );
}

void MenuSequence::on_btnSave_clicked()
{
    if( settings->value("sequence").toString() != ui->plainTextEdit->toPlainText() )
    {
        settings->setValue("sequence", ui->plainTextEdit->toPlainText() );
        emit sequenceChanged();
    }

    if( settings->value("sequenceDelay").toInt() != ui->lineEdit->text().toInt() )
    {
        settings->setValue("sequenceDelay", ui->lineEdit->text().toInt() );
        emit delayChanged();
    }
    close();
}

void MenuSequence::on_btnCancel_clicked()
{
    close();
}
