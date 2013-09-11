#include "MenuSettings.h"
#include "ui_MenuSettings.h"

MenuSettings::MenuSettings( PortSettings* settings, QWidget* parent ) : QDialog( parent ), ui( new Ui::MenuSettings )
{
    ui->setupUi(this);

    this->setWindowFlags( this->windowFlags() & ~Qt::WindowContextHelpButtonHint );

    this->settings = settings;

    // fill combo boxes
    ui->cmbBps->addItems( settings->getBpsList() );
    ui->cmbDataBits->addItems( settings->getDataBitsList() );
    ui->cmbParity->addItems( settings->getParityList() );
    ui->cmbStopBits->addItems( settings->getStopBitsList() );
    ui->cmbFlowControl->addItems( settings->getFlowControlList() );

    // remove mouse wheel selection if the combo box is not focused
    ui->cmbBps->installEventFilter( this );
    ui->cmbDataBits->installEventFilter( this );
    ui->cmbFlowControl->installEventFilter( this );
    ui->cmbParity->installEventFilter( this );
    ui->cmbPorts->installEventFilter( this );
    ui->cmbStopBits->installEventFilter( this );

    group.addButton( ui->radioAll );
    group.addButton( ui->radioSingle );

    selectedPort = settings->value( "port" ).toString();
    loadSettings();
}

QVariant MenuSettings::getSettingValue( const QString& name, bool isDefault )
{
    if( isDefault )
        return settings->getDefault( name );
    else
        return settings->value( name );
}

bool MenuSettings::eventFilter( QObject* obj, QEvent* event )
{
    if( obj->inherits( "QComboBox" ) )
    {
        if( event->type() == QEvent::Wheel && !( ((QComboBox*)obj)->hasFocus() ) )
            return true;
    }

    return false;
}

void MenuSettings::loadSettings( bool isDefault )
{
    // PORT SETTINGS
    setComboSetting( ui->cmbBps,         "bitsPerSecond", isDefault );
    setComboSetting( ui->cmbDataBits,    "dataBits", isDefault );
    setComboSetting( ui->cmbStopBits,    "stopBits", isDefault );
    setComboSetting( ui->cmbParity,      "parity", isDefault );
    setComboSetting( ui->cmbFlowControl, "flowControl", isDefault );

    // CONNECTION SETTINGS
    if( getSettingValue( "port", isDefault ).toString() == "ALL" )
    {
        ui->radioAll->setChecked( true );
        on_radioAll_toggled( true );
    }
    else
    {
        ui->radioSingle->setChecked( true );
        on_radioSingle_toggled( true );
    }

    updateComboPorts();

    if( getSettingValue( "autoConnect", isDefault ).toBool() )
        ui->chkAutoConnect->setChecked( true );
    else
        ui->chkAutoConnect->setChecked( false );

    // VALIDATION SETTINGS
    if( getSettingValue( "validationManualCommand", isDefault ).toBool() )
        ui->chkVerifManCom->setChecked( true );

    if( getSettingValue( "validationSequence", isDefault ).toBool() )
        ui->chkVerifSeq->setChecked( true );
}

//  Slot - Called everytime a serial device is detected/removed
//  Refresh the COM ports list
//
void MenuSettings::updateComboPorts()
{
    ui->cmbPorts->clear();
    ui->cmbPorts->addItems( settings->getAvailablePorts() );

    selectPort();
}

void MenuSettings::selectPort()
{
    if( selectedPort != "ALL" )
    {
        // Set current port
        int itemIndex = ui->cmbPorts->findText( selectedPort );
        if( itemIndex != -1 )
            ui->cmbPorts->setCurrentIndex( itemIndex );
        else    // else select the first one in the combo box
            ui->cmbPorts->setCurrentIndex( 0 );
    }
}

//  Set current values in combo boxes
//
void MenuSettings::setComboSetting( QComboBox* combo, const QString& field, bool isDefault )
{
    int itemIndex;
    if( isDefault )
        itemIndex = combo->findText( settings->getDefault( field ).toString() );
    else
        itemIndex = combo->findText( settings->value( field ).toString() );

    // if the chosen setting is found, select it in the combo box
    if( itemIndex != -1 )
        combo->setCurrentIndex( itemIndex );
    else    // else select the first one in the combo box
        combo->setCurrentIndex( 0 );
}

void MenuSettings::on_radioAll_toggled( bool checked )
{
    if( checked )
    {
        ui->serialPortLabel->setEnabled( false );
        ui->cmbPorts->setEnabled( false );
    }
}

void MenuSettings::on_radioSingle_toggled( bool checked )
{
    if( checked )
    {
        ui->serialPortLabel->setEnabled( true );
        ui->cmbPorts->setEnabled( true );
    }
}

void MenuSettings::on_btnOk_clicked()
{
    // Port settings
    if( settings->value( "bitsPerSecond" ).toString() != ui->cmbBps->currentText() ||
        settings->value( "dataBits" ).toString() != ui->cmbDataBits->currentText() ||
        settings->value( "parity" ).toString() != ui->cmbParity->currentText() ||
        settings->value( "stopBits" ).toString() != ui->cmbStopBits->currentText() ||
        settings->value( "flowControl" ).toString() != ui->cmbFlowControl->currentText() )
    {
        settings->setValue( "bitsPerSecond", ui->cmbBps->currentText() );
        settings->setValue( "dataBits", ui->cmbDataBits->currentText() );
        settings->setValue( "parity", ui->cmbParity->currentText() );
        settings->setValue( "stopBits", ui->cmbStopBits->currentText() );
        settings->setValue( "flowControl", ui->cmbFlowControl->currentText() );

        emit portSettingsChanged();
    }

    // CONNECTION SETTINGS
    bool changed = false;

    // connect all or single
    if( group.checkedButton() == ui->radioAll )
    {
        if( settings->value( "port" ).toString() != "ALL" )
        {
            settings->setValue( "port", "ALL" );
            changed = true;
        }
    }
    else if( group.checkedButton() == ui->radioSingle )
    {
        if( settings->value( "port" ).toString() != ui->cmbPorts->currentText() )
        {
            settings->setValue( "port", ui->cmbPorts->currentText() );
            changed = true;
        }
    }

    // auto connect
    if( settings->value( "autoConnect").toBool() != ui->chkAutoConnect->isChecked() )
    {
        if( ui->chkAutoConnect->isChecked() )   // checked
            settings->setValue( "autoConnect", true );
        else                                    // unchecked
            settings->setValue( "autoConnect", false );
        changed = true;
    }

    // did the connection settings change
    if( changed )
        emit connectionSettingsChanged();


    // VALIDATION SETTINGS
    if( settings->value( "validationManualCommand" ).toBool() != ui->chkVerifManCom->isChecked() ||
        settings->value( "validationSequence" ).toBool() != ui->chkVerifSeq->isChecked() )
    {
        // validation: manual command
        if( ui->chkVerifManCom->isChecked() )   // checked
            settings->setValue( "validationManualCommand", true );
        else                                    // unchecked
            settings->setValue( "validationManualCommand", false );

        // validation: sequence
        if( ui->chkVerifSeq->isChecked() )   // checked
            settings->setValue( "validationSequence", true );
        else                                 // unchecked
            settings->setValue( "validationSequence", false );

        emit validationSettingsChanged();
    }

    this->close();
}

void MenuSettings::on_btnCancel_clicked()
{
    this->close();
}

void MenuSettings::on_btnReset_clicked()
{
    this->loadSettings( true );
}

MenuSettings::~MenuSettings()
{
    delete ui;
}

void MenuSettings::on_cmbPorts_activated( const QString& portName )
{
    selectedPort = portName;
}
