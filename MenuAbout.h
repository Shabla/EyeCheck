#ifndef MENUABOUT_H
#define MENUABOUT_H

#include <QDialog>

namespace Ui
{
    class MenuAbout;
}

class MenuAbout : public QDialog
{
    Q_OBJECT
    
    public:
        explicit MenuAbout( QWidget *parent = 0 );
        ~MenuAbout();

    private slots:
        void on_pushButton_clicked();

    private:
        Ui::MenuAbout* ui;
};

#endif // MENUABOUT_H
