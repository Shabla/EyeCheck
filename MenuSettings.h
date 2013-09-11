#ifndef MENUSETTINGS_H
#define MENUSETTINGS_H

#include <QDialog>
#include <QDebug>
#include <QLineEdit>
#include <QToolTip>
#include <QComboBox>
#include <QTimer>
#include <QButtonGroup>

#include "serialportinfo.h"
#include "PortSettings.h"

namespace Ui
{
    class MenuSettings;
}

class MenuSettings : public QDialog
{
    Q_OBJECT
    
    private:
        Ui::MenuSettings* ui;
        PortSettings* settings;

        void setComboSetting( QComboBox* combo, const QString& field, bool isDefault );
        QTimer timerPortUpdate;
        QButtonGroup group;
        QString selectedPort;
        void loadSettings( bool isDefault = false );
        void selectPort();
        QVariant getSettingValue( const QString& name, bool isDefault = false );

    protected:
        bool eventFilter( QObject* obj, QEvent* event );

    public:
        explicit MenuSettings( PortSettings* settings, QWidget* parent = 0 );
        ~MenuSettings();

    signals:
        void portSettingsChanged();
        void connectionSettingsChanged();
        void validationSettingsChanged();

    private slots:
        void updateComboPorts();
        void on_radioAll_toggled( bool checked );
        void on_radioSingle_toggled( bool checked );
        void on_btnOk_clicked();
        void on_btnCancel_clicked();
        void on_btnReset_clicked();
        void on_cmbPorts_activated( const QString& portName );
};

#endif // MENUSETTINGS_H
