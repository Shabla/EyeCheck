#ifndef PORTSETTINGS_H
#define PORTSETTINGS_H

#include <QSettings>
#include <QStringList>
#include <QMap>

#include "serialport.h"

class PortSettings : public QSettings
{
    Q_OBJECT

private:
    QMap<QString, QVariant> defaultSettings;

    // Combo boxes content
    QStringList sortedBps; // sorted display in the combobox
    QMap<QString, SerialPort::Rate>         bps;
    QMap<QString, SerialPort::DataBits>     dataBits;
    QMap<QString, SerialPort::Parity>       parity;
    QMap<QString, SerialPort::StopBits>     stopBits;
    QMap<QString, SerialPort::FlowControl>  flowControl;

    QStringList                             availablePorts;

public:
    PortSettings( const QString& filename, Format format, QObject *parent = 0 );

    QStringList getBpsList() const;
    QStringList getDataBitsList() const;
    QStringList getParityList() const;
    QStringList getStopBitsList() const;
    QStringList getFlowControlList() const;
    QStringList getAvailablePorts() const;
    void setAvailablePorts( const QStringList& ports );
    QVariant getDefault( const QString& setting );

    SerialPort::Rate getBps() const;
    SerialPort::DataBits getDataBits() const;
    SerialPort::Parity getParity() const;
    SerialPort::StopBits getStopBits() const;
    SerialPort::FlowControl getFlowControl() const;
    void resetToDefault( const QString& key );
    void resetAll();
};

#endif // PORTSETTINGS_H
