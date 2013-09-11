#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QByteArray>
#include <QList>
#include <QScrollBar>
#include <QTime>
#include <QTimer>
#include <QLabel>
#include <QFile>
#include <QTextStream>
#include <QToolTip>
#include <QSettings>
#include <QComboBox>
#include <QDebug>
#include <QSplashScreen>

#include "Port.h"
#include "serialportinfo.h"

#include "Regex.h"
#include "ThreadSequence.h"
#include "MenuSettings.h"
#include "MenuSequence.h"
#include "MenuAbout.h"
#include "PortSettings.h"


namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    private:
        // UI
        Ui::MainWindow* ui;
        QLabel*         lblStatus;
        QLabel*         lblBaud;
        QLabel*         lblDataBits;
        QLabel*         lblParity;
        QLabel*         lblStopBits;
        QLabel*         lblFlowControl;
        QScrollBar*     scrollBar;

        // Menus
        MenuSettings*   menuSettings;
        MenuSequence*   menuSequence;
        MenuAbout*      menuAbout;

        // Ports
        QList<Port*>    ports;
        PortSettings*   settings;
        bool            connected;
        QStringList     targets;

        // Other
        QSplashScreen   splash;
        ThreadSequence* threadSequence;
        QTime           timeConnected;
        QTimer          timerStatusBar;
        QTimer          timerUpdatePorts;
        QString         console;
        int             sequenceStartedTime;
        bool            advancedMode;

        // Private methods
        void    initUI();
        void    openPort( const QString& name );
        void    closePort( Port* port );
        void    startSequence();
        void    stopSequence();
        void    showAdvanced();
        void    hideAdvanced();
        void    loadSettings();
        Port*   getPort( const QString& name ) const;
        void    commandIsInvalid();
        void    commandIsValid();
        void    connection();
        void    disconnection();
        QString timestamp() const;
        QString timeFromSeconds( int seconds ) const;
        QString target() const;

    public:
        MainWindow( QSplashScreen& splash, QWidget* parent = 0 );
        ~MainWindow();

    signals:
        void availablePortsUpdated();

    private slots:
        // Custom slots
        void println( const QString& msg );
        void print( const QString& msg );
        void send( const QString& str );
        void slotDeviceIsReady( Port* port );
        void slotDataReceived( const QString& name, const QByteArray& data );
        void slotUpdateStatusBar();
        void slotPortSettingsChanged();
        void slotConnectionSettingsChanged();
        void slotValidationSettingsChanged();
        void slotSequenceChanged();
        void slotSequenceDelayChanged();
        void updateAvailablePorts();

        // Auto connect slots
        void on_btnSend_clicked();
        void on_btnConnection_clicked();
        void on_btnPlus_clicked();
        void on_btnMinus_clicked();
        void on_btnSequence_clicked();
        void on_actionSettings_triggered();
        void on_actionExit_triggered();
        void on_actionAbout_triggered();
        void on_actionTest_sequence_triggered();
        void on_lineEditCommand_textChanged( const QString& newValue );
        void on_cmbTarget_currentIndexChanged( const QString& arg1 );
        void on_btnAdvanced_clicked();
};

#endif // MAINWINDOW_H
