#include "acceso.h"
#include "ui_acceso.h"
#include "QDebug"
Acceso::Acceso(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Acceso)
{
    ui->setupUi(this);
    m_controlador->Cargar_Usuarios(&usuarios2);
}

Acceso::~Acceso()
{
    delete ui;
}

bool Acceso::on_btn_Ingresar_clicked()
{
    QMapIterator<QString, QString> i(usuarios2);
        while (i.hasNext()){
            i.next();
            if(i.key() == ui->in_Usuario->text() && (i.value()) == ui->in_Contra->text())
            {
                setBandera(true);
                this->close();
                return true;
            }
        }
        setBandera(false);
        if(!getBandera()){
            QMessageBox::warning(this, tr("Administrador"), tr("Usuario y/o Contraseña Incorrecta"), tr("Aceptar"));
        }
        return false;
}

void Acceso::on_btn_Registrar_clicked()
{
    Registrar_usuario *reg = new Registrar_usuario(this);
        reg->setWindowTitle(tr("Registrar Usuario"));
        int res = reg->exec();
        if (res == QDialog::Rejected){
            return;
        }

        if(!reg->getUsuarios().isEmpty()){
            QMapIterator<QString, QString> i(reg->getUsuarios());
                i.next();
                usuarios2.insert(i.key(), i.value());
        }
        qDebug()<<usuarios2;
        m_controlador->Guardar_U(usuarios2);
}

void Acceso::setBandera(bool newBandera)
{
    bandera = newBandera;
}

bool Acceso::getBandera() const
{
    return bandera;
}
