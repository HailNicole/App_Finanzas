#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}


void login::on_pushButton_clicked()
{
    Principal p(this);
    /*QMessageBox about;
    about.setIconPixmap(QPixmap(":/imagen/recursos/perrito.jpg"));
    about.exec();
    */

}


void login::on_pushButton_2_clicked()
{

}

