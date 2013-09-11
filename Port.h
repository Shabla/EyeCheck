#ifndef HANDLER_H
#define HANDLER_H

#include <QObject>
#include <QDebug>

#include "serialport.h"

class Port : public QObject
{
    Q_OBJECT

    private:
        SerialPort* port;
        bool ready;

    public:
        explicit Port( const QString& name, QObject *parent = 0);
        ~Port();
        bool isReady() const;
        void setReady( bool state );
        SerialPort* getPort() const;

        // these class are wrapped from SerialPort
        QString portName() const;
        bool open( SerialPort::OpenMode mode );
        void close();
        qint64 write( const QByteArray& data );
        bool setRate( qint32 rate, SerialPort::Directions dir = SerialPort::AllDirections );
        bool setDataBits( SerialPort::DataBits dataBits );
        bool setParity( SerialPort::Parity parity );
        bool setStopBits( SerialPort::StopBits stopBits );
        bool setFlowControl( SerialPort::FlowControl flow );

    signals:
        void deviceIsReady( Port* port );
        void dataReceived( const QString& name, const QByteArray& data );

    public slots:
        void read();
    
};

#endif // HANDLER_H
