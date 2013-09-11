#include "PortSettings.h"

PortSettings::PortSettings( const QString& filename, Format format, QObject *parent ) : QSettings( filename, format, parent )
{
    this->beginGroup( "current" );

    bps["1200"] = SerialPort::Rate1200;
    sortedBps.append("1200");
    bps["2400"] = SerialPort::Rate2400;
    sortedBps.append("2400");
    bps["4800"] = SerialPort::Rate4800;
    sortedBps.append("4800");
    bps["9600"] = SerialPort::Rate9600;
    sortedBps.append("9600");
    bps["19200"] = SerialPort::Rate19200;
    sortedBps.append("19200");
    bps["38400"] = SerialPort::Rate38400;
    sortedBps.append("38400");
    bps["57600"] = SerialPort::Rate57600;
    sortedBps.append("57600");
    bps["115200"] = SerialPort::Rate115200;
    sortedBps.append("115200");

    dataBits["5"]  = SerialPort::Data5;
    dataBits["6"]  = SerialPort::Data6;
    dataBits["7"]  = SerialPort::Data7;
    dataBits["8"]  = SerialPort::Data8;

    parity["Even"] = SerialPort::EvenParity;
    parity["Odd"]  = SerialPort::OddParity;
    parity["None"] = SerialPort::NoParity;
    parity["Mark"] = SerialPort::MarkParity;
    parity["Space"]= SerialPort::SpaceParity;

    stopBits["1"]  = SerialPort::OneStop;
    stopBits["1.5"]= SerialPort::OneAndHalfStop;
    stopBits["2"]  = SerialPort::TwoStop;

    flowControl["Software"]  = SerialPort::SoftwareControl;
    flowControl["Hardware"]  = SerialPort::HardwareControl;
    flowControl["None"]      = SerialPort::NoFlowControl;

    // default settings
    defaultSettings["port"]                     = "ALL";
    defaultSettings["bitsPerSecond"]            = 115200;
    defaultSettings["dataBits"]                 = 8;
    defaultSettings["parity"]                   = "None";
    defaultSettings["stopBits"]                 = 1;
    defaultSettings["flowControl"]              = "None";
    defaultSettings["autoConnect"]              = true;
    defaultSettings["validationManualCommand"]  = true;
    defaultSettings["validationSequence"]       = true;

    defaultSettings["sequence"]         = "a0b2c1d1;a1;a2;a3;a4;a5;a6;a7;a8;";
    defaultSettings["sequenceDelay"]    = 300;
}

void PortSettings::resetToDefault( const QString& key )
{
    this->setValue( key, defaultSettings.value( key ) );
}

void PortSettings::resetAll()
{
    this->resetToDefault( "port" );
    this->resetToDefault( "bitsPerSecond" );
    this->resetToDefault( "dataBits" );
    this->resetToDefault( "parity" );
    this->resetToDefault( "stopBits" );
    this->resetToDefault( "flowControl" );
    this->resetToDefault( "sequence" );
    this->resetToDefault( "sequenceDelay" );
    this->resetToDefault( "autoConnect" );
    this->resetToDefault( "validationManualCommand" );
    this->resetToDefault( "validationSequence" );
}

QVariant PortSettings::getDefault( const QString& setting )
{
    return defaultSettings.value( setting );
}

void PortSettings::setAvailablePorts( const QStringList& ports )
{
    this->availablePorts = ports;
}

QStringList PortSettings::getAvailablePorts() const
{
    return this->availablePorts;
}

QStringList PortSettings::getBpsList() const
{
    return sortedBps;
}

QStringList PortSettings::getDataBitsList() const
{
    return dataBits.keys();
}

QStringList PortSettings::getParityList() const
{
    return parity.keys();
}

QStringList PortSettings::getStopBitsList() const
{
    return stopBits.keys();
}

QStringList PortSettings::getFlowControlList() const
{
    return flowControl.keys();
}

SerialPort::Rate PortSettings::getBps() const
{
    return bps[ this->value("bitsPerSecond").toString() ];
}

SerialPort::DataBits PortSettings::getDataBits() const
{
    return dataBits[ this->value("dataBits").toString() ];
}

SerialPort::Parity PortSettings::getParity() const
{
    return parity[ this->value("parity").toString() ];
}

SerialPort::StopBits PortSettings::getStopBits() const
{
    return stopBits[ this->value("stopBits").toString() ];
}

SerialPort::FlowControl PortSettings::getFlowControl() const
{
    return flowControl[ this->value("flowControl").toString() ];
}
