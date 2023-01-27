#include "registrar_usuario.h"
#include "ui_registrar_usuario.h"

#include "QDebug"

Registrar_usuario::Registrar_usuario(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registrar_usuario)
{
    ui->setupUi(this);
    setWindowTitle("Registrar");
}

Registrar_usuario::~Registrar_usuario()
{
    delete ui;
}

void Registrar_usuario::on_buttonBox_accepted()
{
    QString email=ui->in_regusuario->text();
    QString contrasenia=ui->in_regcontra->text();

    if(!validar_email(email) || contrasenia.isEmpty()){
        QMessageBox::information(this, "Error", "Datos Erróneos o Incompletos");
        return;
    }
    //Estructura map donde guarda una llave asociada a un valor
    usuarios.insert(email,contrasenia);
    accept();
}
bool Registrar_usuario::validar_email(QString email)
{
    if(email.isEmpty()){
        return false;
    }
      QRegExp pattern ("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
      return pattern.exactMatch(email);
}

QMap<QString, QString> Registrar_usuario::getUsuarios() const
{
    return usuarios;
}

void Registrar_usuario::on_buttonBox_rejected()
{
    reject();
}

void Registrar_usuario::on_toolButton_released()
{
    ui->in_regcontra->setEchoMode(QLineEdit::Password);
}


void Registrar_usuario::on_toolButton_pressed()
{
    ui->in_regcontra->setEchoMode(QLineEdit::Normal);
}

