#include "ThreadSequence.h"

ThreadSequence::ThreadSequence()
{
    active = false;
}

void ThreadSequence::run()
{
    while( active )
    {
        for( int i=0; i<sequence.size(); i++ )
        {
            if( !active )
                break;

            emit signalSend( sequence.at( i ) + ";" );
            msleep( delay );
        }
    }
}

void ThreadSequence::setSequence( QString sequence )
{
    active = false;

    sequence = sequence.remove( sequence.size()-1, 1 );
    this->sequence = sequence.split( ";" );

    active = true;
}

void ThreadSequence::setDelay( int ms )
{
    delay = ms;
}

void ThreadSequence::setActive( bool status )
{
    active = status;
}

bool ThreadSequence::isActive() const
{
    return active;
}
