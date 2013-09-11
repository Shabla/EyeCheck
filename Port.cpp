#include "Port.h"

Port::Port( const QString& name, QObject *parent ) : QObject(parent)
{
    port = new SerialPort( name );
    ready = false;
}

Port::~Port()
{
    delete port;
}

void Port::setReady( bool state )
{
    ready = state;
}

bool Port::isReady() const
{
    return ready;
}

// this is to get the readReady() signal in MainWindow
SerialPort* Port::getPort() const
{
    return port;
}

// slot called when readyRead() is emitted
void Port::read()
{
    QByteArray ba = port->read( port->bytesAvailable() );

    if( ba == "Ready"  )
    {
        emit dataReceived( this->portName(), ba );

        if( !ready )
        {
            ready = true;
            emit deviceIsReady( this );
        }
    }
}

/*
 *
 *  WRAPPED METHODS
 *
 */

QString Port::portName() const
{
    return port->portName();
}

bool Port::open( SerialPort::OpenMode mode )
{
    return port->open( mode );
}

void Port::close()
{
    port->close();
}

qint64 Port::write( const QByteArray& data )
{
    return port->write(data);
}

bool Port::setRate(qint32 rate, SerialPort::Directions dir)
{
    return port->setRate(rate, dir);
}

bool Port::setDataBits(SerialPort::DataBits dataBits)
{
    return port->setDataBits(dataBits);
}

bool Port::setParity(SerialPort::Parity parity)
{
    return port->setParity(parity);
}

bool Port::setStopBits(SerialPort::StopBits stopBits)
{
    return port->setStopBits(stopBits);
}

bool Port::setFlowControl(SerialPort::FlowControl flow)
{
    return port->setFlowControl(flow);
}
