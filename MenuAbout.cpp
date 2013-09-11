#include "MenuAbout.h"
#include "ui_MenuAbout.h"

MenuAbout::MenuAbout(QWidget *parent) : QDialog(parent), ui( new Ui::MenuAbout )
{
    ui->setupUi( this );
    this->setWindowFlags( this->windowFlags() & ~Qt::WindowContextHelpButtonHint );
}

MenuAbout::~MenuAbout()
{
    delete ui;
}

void MenuAbout::on_pushButton_clicked()
{
    this->close();
}
