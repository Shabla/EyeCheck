#include <QtGui/QApplication>
#include <QSplashScreen>

#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setQuitOnLastWindowClosed(true);

    QPixmap pixmap(":/ressources/splash.png");
    QSplashScreen splash( pixmap );
    splash.show();
    splash.showMessage( "Loading...", Qt::AlignBottom | Qt::AlignHCenter );

    app.processEvents();

    MainWindow w( splash );
    w.show();
    splash.finish( &w );

    return app.exec();
}
