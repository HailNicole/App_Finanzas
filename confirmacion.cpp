#include "confirmacion.h"
#include "ui_confirmacion.h"
#include "QDebug"
Confirmacion::Confirmacion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Confirmacion)
{
    ui->setupUi(this);
    setWindowTitle(tr("CONFIRMACION"));
}

Confirmacion::~Confirmacion()
{
    delete ui;
}

bool Confirmacion::on_btn_confi_clicked()
{
    QString password = ui->in_password->text();
    QString match;
    m_controlador->Cargar_Admin(&match);
    if(password == match){
        setFlag(true);
        this->close();
        return true;
    }else{
        QMessageBox::critical(this,tr("Borrar Cuenta Admin"),tr("Contraseña Incorrecta"));
        setFlag(false);
        return false;
    }
}

bool Confirmacion::getFlag() const
{
    return flag;
}

void Confirmacion::setFlag(bool newFlag)
{
    flag = newFlag;
}
