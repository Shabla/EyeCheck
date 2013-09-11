#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow( QSplashScreen& splash, QWidget* parent ) : QMainWindow( parent ), ui( new Ui::MainWindow )
{
    initUI();

    connected       = false;
    menuSettings    = 0;
    menuSequence    = 0;
    menuAbout       = 0;
    threadSequence  = 0;
    console         = "";
    advancedMode    = false;

    QPixmap pixmap(":/ressources/splash.png");
    this->splash.setPixmap( pixmap );

    // load and validate settings
    loadSettings();

    // auto connect
    if( settings->value( "autoConnect" ).toBool() )
    {
        QString line = "Auto-connecting to ";
        if( settings->value( "port" ).toString() == "ALL" )
            line += "all available ports.";
        else
            line += settings->value( "port" ).toString() + "." ;

        println( line );
        splash.finish( this );
        connection();
    }
}

void MainWindow::initUI()
{
    ui->setupUi( this );

    // Initialize the status bar
    lblStatus       = new QLabel( "Disconnected" );
    lblBaud         = new QLabel();
    lblDataBits     = new QLabel();
    lblParity       = new QLabel();
    lblStopBits     = new QLabel();
    lblFlowControl  = new QLabel();

    QFrame::Shape shape     = QFrame::Panel;
    QFrame::Shadow shadow   = QFrame::Sunken;

    lblStatus->setFrameShape( shape );
    lblStatus->setFrameShadow( shadow );
    lblBaud->setFrameShape( shape );
    lblBaud->setFrameShadow( shadow );
    lblDataBits->setFrameShape( shape );
    lblDataBits->setFrameShadow( shadow );
    lblParity->setFrameShape( shape );
    lblParity->setFrameShadow( shadow );
    lblStopBits->setFrameShape( shape );
    lblStopBits->setFrameShadow( shadow );
    lblFlowControl->setFrameShape( shape );
    lblFlowControl->setFrameShadow( shadow );

    ui->statusBar->addPermanentWidget( lblStatus, 200 );
    ui->statusBar->addPermanentWidget( lblBaud );
    ui->statusBar->addPermanentWidget( lblDataBits );
    ui->statusBar->addPermanentWidget( lblParity );
    ui->statusBar->addPermanentWidget( lblStopBits );
    ui->statusBar->addPermanentWidget( lblFlowControl );

    this->setStyleSheet( "QStatusBar::item { border: none; }" );    // remove the bars between the status's bar items

    scrollBar = ui->textEditConsole->verticalScrollBar();
}

/*****************************************************************************
 *****************************************************************************
 ***
 ***                                LOADING
 ***
 *****************************************************************************
 *****************************************************************************/

//
//  Load settings from file
//
void MainWindow::loadSettings()
{
    // Load settings in a QSettings
    settings = new PortSettings( "EyeCheck_settings.ini", QSettings::IniFormat );

    // update the available ports every 2 seconds
    connect( &timerUpdatePorts, SIGNAL(timeout()), this, SLOT(updateAvailablePorts()) );
    timerUpdatePorts.start( 1000 );

    if( settings->allKeys().size() == 0 )
    {
        print( timestamp() + "Settings file is inexistent, creating a new one with default values.");
        settings->resetAll();
    }
    else
    {
        print( timestamp() + "Settings file loaded successfully.");

        if( !settings->contains( "port" ) )
            settings->resetToDefault( "port" );

        if( !settings->contains( "bitsPerSecond" ) )
            settings->resetToDefault( "bitsPerSecond" );

        if( !settings->contains( "dataBits" ) )
            settings->resetToDefault( "dataBits" );

        if( !settings->contains( "parity" ) )
            settings->resetToDefault( "parity" );

        if( !settings->contains( "stopBits" ) )
            settings->resetToDefault( "stopBits" );

        if( !settings->contains( "flowControl" ) )
            settings->resetToDefault( "flowControl" );

        if( !settings->contains( "sequence" ) || !Regex::isValid( REGEX_SEQUENCE, settings->value( "sequence" ).toString() ) )
            settings->resetToDefault( "sequence" );

        if( !settings->contains( "sequenceDelay" ) || !Regex::isValid( REGEX_SEQUENCEDELAY, settings->value( "sequenceDelay" ).toString() ) )
            settings->resetToDefault( "sequenceDelay" );

        if( !settings->contains( "autoConnect" ) || !Regex::isValid( REGEX_BOOL, settings->value( "autoConnect" ).toString() ) )
            settings->resetToDefault( "autoConnect" );

        if( !settings->contains( "validationManualCommand" ) || !Regex::isValid( REGEX_BOOL, settings->value( "validationManualCommand" ).toString() ) )
            settings->resetToDefault( "validationManualCommand" );

        if( !settings->value( "validationManualCommand" ).toBool() )
            commandIsValid();

        if( !settings->contains( "validationSequence" ) || !Regex::isValid( REGEX_BOOL, settings->value( "validationSequence" ).toString() ) )
            settings->resetToDefault( "validationSequence" );
    }

    // Set texts in the status bar labels
    slotPortSettingsChanged();
    updateAvailablePorts();
}

// update avaialbe ports
void MainWindow::updateAvailablePorts()
{
    QStringList lastAvailable = settings->getAvailablePorts();
    QList<SerialPortInfo> available = SerialPortInfo::availablePorts();

    // check if there is a chan
    if( lastAvailable.size() != available.size() )
    {
        // create the list of the available ports
        QStringList updatedPorts;
        foreach( SerialPortInfo spi, available )
        {
            QString portName = spi.portName();

            if( !lastAvailable.contains( portName ) )
                println( "[" + portName + "] New serial port detected." );

            updatedPorts << portName;
        }

        // see if some ports were disconnected since last time the ports were updated
        foreach( QString portName, lastAvailable )
        {
            if( !updatedPorts.contains( portName ) )
                println( "[" + portName + "] Serial port disconnected." );
        }

        qDebug() << "updating ports..." << updatedPorts.count();

        for( int i=0; i<ports.size(); ++i )
        {
            Port* port = ports.at(i);
            if( !updatedPorts.contains( port->portName() ) )
            {
                disconnection();
                break;
            }
        }

        settings->setAvailablePorts( updatedPorts );
        emit availablePortsUpdated();
    }
}

/*****************************************************************************
 *****************************************************************************
 ***
 ***                              CONNECTION
 ***
 *****************************************************************************
 *****************************************************************************/

//  Button -> Connect
//  Toggle connection
//
void MainWindow::on_btnConnection_clicked()
{
    if( !connected )
        connection();
    else
        disconnection();
}

//  Connect to all or one port
//
//
void MainWindow::connection()
{
    splash.show();
    splash.showMessage( "Connecting...", Qt::AlignBottom | Qt::AlignHCenter );

    // Attempt to connect to every available ports on the machine
    if( settings->value( "port" ).toString() == "ALL" )
    {
        foreach( SerialPortInfo spi, SerialPortInfo::availablePorts() )
        {
            QString name = spi.portName();

            // if the port is not already opened
            if( getPort( name ) == 0 )
                openPort( name );
            else
                print( "Already open." );
        }
    }
    else
    {
        openPort( settings->value("port").toString() );
    }

    // if at least one port has been opened
    if( connected )
    {
        if( ui->cmbTarget->count() > 1 )
        {
            ui->cmbTarget->insertItem( 0, "All" );
            ui->cmbTarget->setCurrentIndex( 0 );
        }

        timeConnected.restart();
        connect( &timerStatusBar, SIGNAL(timeout()), this, SLOT(slotUpdateStatusBar()) );
        timerStatusBar.start(500);
        slotUpdateStatusBar();

        ui->btnConnection->setText( "Disconnect" );
        ui->btnSequence->setEnabled(true);
        ui->btnPlus->setEnabled(true);
        ui->btnMinus->setEnabled(true);
        ui->lineEditCommand->setEnabled(true);
        ui->lineEditCommand->setFocus();
        ui->cmbTarget->setEnabled( true );
    }

    splash.finish( this );
}

//  Disconnect from all ports
//
//
void MainWindow::disconnection()
{
    QString disc = "";
    foreach( Port* port, ports )
    {
        disc.append( port->portName() + ", " );
        closePort( port );
    }
    disc.chop(2);
    println( "Disconnected from " + disc + "." );

    timerStatusBar.stop();
    lblStatus->setText("Disconnected");
    ui->btnConnection->setText( "Connect" );
    ui->btnSequence->setEnabled(false);
    ui->lineEditCommand->setEnabled(false);
    ui->btnPlus->setEnabled(false);
    ui->btnMinus->setEnabled(false);
    ui->lineEditCommand->setStyleSheet("");
    ui->lineEditCommand->clear();
    ui->cmbTarget->clear();
    ui->cmbTarget->setEnabled( false );
    targets.clear();

    connected = false;
}

//  Called when the button connect is clicked
//  Open the currently selected port
void MainWindow::openPort( const QString& name )
{
    Port* port = new Port( name );

    println( "[" + name + "] Attempting to connect... " );

    // if connection is successful
    if( port->open( SerialPort::ReadWrite ) )
    {
        port->setRate( settings->getBps() );
        port->setDataBits( settings->getDataBits() );
        port->setParity( settings->getParity() );
        port->setStopBits( settings->getStopBits() );
        port->setFlowControl( settings->getFlowControl() );

        // when readyRead() is emitted (by the port), read the available data and do what needs to be done
        connect( port->getPort(), SIGNAL( readyRead() ), port, SLOT( read() ) );

        // When data is received, display it in the console
        connect( port, SIGNAL( dataReceived(const QString&, const QByteArray&) ), this, SLOT( slotDataReceived(const QString&, const QByteArray&) ) );

        // readAvailableData will emit the signal deviceIsReady and the slot slot_deviceIsReady will do eveything needed for an opend port
        connect( port, SIGNAL( deviceIsReady(Port*) ), this, SLOT( slotDeviceIsReady(Port*) ) );

        port->write("?");

        // wait data for 100 ms before returning false
        if( !port->getPort()->waitForReadyRead(100) )
        {
            port->close();
            delete port;
            print( "Timed out." );
        }
    }
    else
    {
        delete port;
        print( "Could not be opened." );
    }
}

//  Called when the button connect is clicked
//  Close the currently open port
void MainWindow::closePort( Port* port )
{
    // close sequence
    if( threadSequence && threadSequence->isActive() )
        stopSequence();

    if( port->isReady() )
        port->write( "\\27" );

    port->close();
    ports.removeOne( port );
    delete port;
}

void MainWindow::slotDataReceived( const QString& name, const QByteArray& data )
{
    println( "[" + name + "] Received : « " + data + " »");
}

//  SLOT - A COM device replied "Ready"
//  Display a closed eye and add the port to the ports list.
void MainWindow::slotDeviceIsReady( Port* port )
{
    port->write("a0;");
    ports.append( port );
    ui->cmbTarget->addItem( port->portName() );

    if( !connected )
        connected = true;
}

/*****************************************************************************
 *****************************************************************************
 ***
 ***                           SENDING COMMANDS
 ***
 *****************************************************************************
 *****************************************************************************/

//  Button -> Send
//  Send the command typed in the lineEdit as a command.
void MainWindow::on_btnSend_clicked()
{
    if( ui->lineEditCommand->text().length() > 0 )
    {
        if( ui->lineEditCommand->text() == "clear" )
        {
            console = "";
            ui->textEditConsole->setPlainText( console );
        }
        else
            send( ui->lineEditCommand->text() );

        ui->lineEditCommand->clear();
        ui->lineEditCommand->setFocus();
    }
}

//  Slot - Called from the sequence thread for every command in the sequence
//  Send a command to the serial device
void MainWindow::send( const QString& str )
{
    if( connected )
    {
        if( threadSequence == 0 || ( threadSequence && !threadSequence->isActive() ) )
        {
            if( str != "+" && str != "-" )
                println( "[" + this->target() + "] " + "Sending command " + str );
        }

        foreach( QString name, targets )
        {
            Port* port = getPort( name );
            if( port && port->isReady() )
            {
                port->write( str.toAscii() );

                if( str == "?" )
                    port->getPort()->waitForReadyRead(100);
            }
        }
    }
}

//  Button -> Plus
//  Augment the brightness
void MainWindow::on_btnPlus_clicked()
{
    send( "+" );
}

//  Button -> Minus
//  Reduce de brightness
void MainWindow::on_btnMinus_clicked()
{
    send( "-" );
}

//  QLineEdit -> TextChanged
//  Tell the user if what he is typing is a valid sequence of commands.
void MainWindow::on_lineEditCommand_textChanged( const QString& newValue )
{
    if( settings->value( "validationManualCommand" ).toBool() )
    {   // validation is activated
        if( newValue.size() > 0 )
        {
            if( !Regex::isValid( REGEX_SEQUENCE, newValue ) )
                commandIsInvalid();
            else
                commandIsValid();
        }
        else
        {   // if the string is empty, don't display the error message, but disable the send button
            commandIsValid();
            ui->btnSend->setEnabled( false );
        }
    }
}

// Manual command is invalid
void MainWindow::commandIsInvalid()
{
    ui->lineEditCommand->setStyleSheet("QLineEdit { border: 2px solid red; } ");
    QToolTip::showText( ui->lineEditCommand->mapToGlobal( QPoint() ), "This sequence is invalid.", this, this->geometry() );
    ui->btnSend->setEnabled( false );
}

void MainWindow::commandIsValid()
{
    ui->lineEditCommand->setStyleSheet("");
    QToolTip::hideText();
    ui->btnSend->setEnabled( true );
}

//  QComboBox -> Index changed
//  Clean the sendTargets list and add the new target(s).
void MainWindow::on_cmbTarget_currentIndexChanged( const QString& target )
{
    targets.clear();
    if( target == "All" )
    {
        for( int i=1; i<ui->cmbTarget->count(); ++i )
            targets << ui->cmbTarget->itemText( i );
    }
    else
    {
        targets << ui->cmbTarget->currentText();
    }
}


/*****************************************************************************
 *****************************************************************************
 ***
 ***                               SEQUENCE
 ***
 *****************************************************************************
 *****************************************************************************/

//  Menu -> Options -> Test sequence
//  Open the sequence menu
void MainWindow::on_actionTest_sequence_triggered()
{
    if( menuSequence != 0 )
        delete menuSequence;

    menuSequence = new MenuSequence( settings, this );
    connect( menuSequence, SIGNAL(sequenceChanged()), this, SLOT(slotSequenceChanged()));
    connect( menuSequence, SIGNAL(delayChanged()), this, SLOT(slotSequenceDelayChanged()));
    menuSequence->show();
}

//  SLOT - Sequence have been modified
//  If the sequence thread is active, modify the sequence being sent
void MainWindow::slotSequenceChanged()
{
    if( threadSequence && threadSequence->isActive() )
    {
        threadSequence->setSequence( settings->value( "sequence" ).toString() );
        println( "[SEQUENCE] Commands sequence changed to " + settings->value( "sequence" ).toString() + "." );
    }
}

//  SLOT - Sequence delay have been modified
//  If the sequence thread is active, modify the sequence delay
void MainWindow::slotSequenceDelayChanged()
{
    if( threadSequence && threadSequence->isActive() )
    {
        threadSequence->setDelay( settings->value( "sequenceDelay" ).toInt() );
        println( "[SEQUENCE] Delay changed to " + settings->value( "sequenceDelay" ).toString() + "." );
    }
}

//  Button -> Sequence
//  Toggle sequence
void MainWindow::on_btnSequence_clicked()
{
    // Create a new thread the first time it's called
    if( !threadSequence )
    {
        threadSequence = new ThreadSequence();
        connect(threadSequence, SIGNAL( signalSend(QString) ), this, SLOT( send(QString) ) );
    }

    if( threadSequence && threadSequence->isActive() )
        stopSequence();
    else
        startSequence();
}

//  Called from on_btnSequence_clicked
//  Start the sequence thread
//
void MainWindow::startSequence()
{
    if( settings->value("sequence").toString().size() > 0 )
    {
        threadSequence->setSequence( settings->value( "sequence" ).toString() );
        threadSequence->setDelay( settings->value( "sequenceDelay" ).toInt() );
        threadSequence->setActive( true );
        threadSequence->start();
        sequenceStartedTime = timeConnected.elapsed() / 1000;
        ui->btnSequence->setIcon( QIcon(":/ressources/button-sequence-stop.png") );

        // target for printing
        QString target;
        if( targets.size() > 1 )
            target = "ALL ports";
        else
            target = targets.at( 0 );

        println( "[SEQUENCE] Starting commands sequence " + settings->value("sequence").toString() + " on " + target + "." );
        println( "[SEQUENCE] Running..." );
    }
    else
    {
        println( "[SEQUENCE] There is no sequence to play." );
    }
}

//  Called from on_btnSequence_clicked
//  Pause the sequence thread.
void MainWindow::stopSequence()
{
    threadSequence->setActive( false );
    ui->btnSequence->setIcon( QIcon(":/ressources/button-sequence-start.png") );

    int seconds = (timeConnected.elapsed() / 1000) - sequenceStartedTime;
    println( "[SEQUENCE] Stopped. Lasted " + timeFromSeconds( seconds ) );
}

/*****************************************************************************
 *****************************************************************************
 ***
 ***                                SETTINGS
 ***
 *****************************************************************************
 *****************************************************************************/

//  Menu -> Options -> Settings
//  Open the settings menu
void MainWindow::on_actionSettings_triggered()
{
    if( menuSettings != 0 )
        delete menuSettings;

    menuSettings = new MenuSettings( settings, this );
    connect( this, SIGNAL(availablePortsUpdated()), menuSettings, SLOT(updateComboPorts()));
    connect( menuSettings, SIGNAL(portSettingsChanged()), this, SLOT(slotPortSettingsChanged()));
    connect( menuSettings, SIGNAL(connectionSettingsChanged()), this, SLOT(slotConnectionSettingsChanged()));
    connect( menuSettings, SIGNAL(validationSettingsChanged()), this, SLOT(slotValidationSettingsChanged()));

    menuSettings->show();
}

void MainWindow::slotPortSettingsChanged()
{
    lblBaud->setText(        "<b>Baud rate</b>: " + settings->value( "bitsPerSecond" ).toString() );
    lblDataBits->setText(    "<b>Data bits</b>: " + settings->value( "dataBits" ).toString() );
    lblParity->setText(      "<b>Parity</b>: " + settings->value( "parity" ).toString() );
    lblStopBits->setText(    "<b>Stop bits</b>: " + settings->value( "stopBits" ).toString() );
    lblFlowControl->setText( "<b>Flow control</b>: " + settings->value( "flowControl" ).toString() );

    println("Port settings changed successfully.");
}

void MainWindow::slotConnectionSettingsChanged()
{
    foreach( Port* port, ports )
    {
        port->setRate( settings->getBps() );
        port->setDataBits( settings->getDataBits() );
        port->setParity( settings->getParity() );
        port->setStopBits( settings->getStopBits() );
        port->setFlowControl( settings->getFlowControl() );
    }

    println("Connection settings changed successfully.");
}

void MainWindow::slotValidationSettingsChanged()
{
    println("Validation settings changed succesffully.");
    if( !settings->value( "validationManualCommand").toBool() )
    {
        commandIsValid();
    }
}

// Button -> Advanced Mode
// Enable manual command sending
void MainWindow::on_btnAdvanced_clicked()
{
    if( !advancedMode )
    {
        showAdvanced();
        advancedMode = true ;
    }
    else
    {
        hideAdvanced();
        advancedMode = false;
    }
}

void MainWindow::showAdvanced()
{
    ui->btnAdvanced->setIcon( QIcon(":/ressources/arrow-up.png") );
    ui->btnAdvanced->setText( "Simple Mode" );
    setMaximumHeight( 585 );
    setMinimumHeight( 585 );
    resize( width(), 585 );
}

void MainWindow::hideAdvanced()
{
    ui->btnAdvanced->setIcon( QIcon(":/ressources/arrow-down.png") );
    ui->btnAdvanced->setText( "Advanced Mode" );
    setMaximumHeight( 350 );
    setMinimumHeight( 350 );
    resize( width(), 350 );
}

/*****************************************************************************
 *****************************************************************************
 ***
 ***                                OTHER
 ***
 *****************************************************************************
 *****************************************************************************/

//  Target for printing
QString MainWindow::target() const
{
    if( targets.size() == 1 )
        return targets.at( 0 );
    else if( targets.size() > 1 )
        return "ALL";
    else
        qDebug() << "WTF there's nothing in sendTargets";
    return "";
}

//  Menu -> Help -> About
//  Open the About menu
void MainWindow::on_actionAbout_triggered()
{
    if( menuAbout != 0 )
        delete menuAbout;

    menuAbout = new MenuAbout( this );
    menuAbout->show();
}

//  SLOT
//  Display a message on a new line in the QTextEdit
void MainWindow::println( const QString& msg )
{
    print( "\n" + timestamp() + msg );
}

//  SLOT
//  Display a message in the QTextEdit
//
void MainWindow::print( const QString& msg )
{
    console.append( msg );
    ui->textEditConsole->setPlainText( console );
    scrollBar->setValue( scrollBar->maximum() );
}

//  Utility
//  Return the current timestamp
QString MainWindow::timestamp() const
{
    return QTime::currentTime().toString("[HH:mm:ss] ");
}

//  Slot - Called twice per second to update the time connected in the status bar
//  Refresh status bar every second
void MainWindow::slotUpdateStatusBar()
{
    lblStatus->setText( "Connected " + timeFromSeconds( timeConnected.elapsed() / 1000 ) );
}

//  Convert a number of seconds to a time format HH:MM:SS
//
QString MainWindow::timeFromSeconds( int seconds ) const
{
    int hours = seconds / 3600;
    seconds -= hours * 3600;

    int minutes  = seconds / 60;
    seconds -= minutes * 60;

    return QString("%1:%2:%3").arg( hours, 2, 10, QLatin1Char('0') )
                            .arg( minutes, 2, 10, QLatin1Char('0') )
                            .arg( seconds, 2, 10, QLatin1Char('0') );
}

//
//  Returns the index of the port "name" in the ports QList.
Port* MainWindow::getPort( const QString& name ) const
{
    for( int i=0; i<ports.size(); ++i )
    {
        if( ports.at( i )->portName() == name )
            return ports.at(i);
    }
    return 0;
}

//  Menu -> File -> Exit
//  Close the application
void MainWindow::on_actionExit_triggered()
{
    this->close();
}

//  Destructor
//  What happen after closing the main window
MainWindow::~MainWindow()
{
    foreach( Port* port, ports )
        closePort( port );

    delete lblStatus;
    delete lblBaud;
    delete lblDataBits;
    delete lblParity;
    delete lblFlowControl;
    delete ui;
}
