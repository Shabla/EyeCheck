#ifndef THREADSEQUENCE_H
#define THREADSEQUENCE_H

#include <QThread>
#include <QStringList>

class ThreadSequence : public QThread
{
    Q_OBJECT

    private:
        QStringList sequence;
        int         delay;
        bool        active;

    public:
        ThreadSequence();
        void setSequence( QString sequence );
        void setDelay( int ms );
        void setActive( bool status );
        bool isActive() const;

    public slots:
        void run();

    signals:
        void signalSend( QString command );
};

#endif // THREADSEQUENCE_H
