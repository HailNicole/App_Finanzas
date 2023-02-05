#include "agregar_miembros.h"
#include "ui_agregar_miembros.h"

Agregar_Miembros::Agregar_Miembros(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Agregar_Miembros)
{
    ui->setupUi(this);
    ui->in_rol->addItem(tr("Papá"));
    ui->in_rol->addItem(tr("Mamá"));
    ui->in_rol->addItem(tr("Hijo"));
    ui->in_rol->addItem(tr("Hija"));
    ui->in_rol->addItem(tr("Otro"));
    setWindowTitle(tr("Agregar Miembro"));
}

void Agregar_Miembros::set_datos(QString nom, QString ape, QString rol)
{
    ui->in_nom->setText(nom);
    ui->in_ape->setText(ape);
    ui->in_rol->setCurrentText(rol);
}

Persona_miembro *Agregar_Miembros::persona() const
{
    return m_persona;
}

Agregar_Miembros::~Agregar_Miembros()
{
    delete ui;
}

void Agregar_Miembros::on_buttonBox_accepted()
{
    QString nombre = ui->in_nom->text();

    QString apellido = ui->in_ape->text();

    QString rol = ui->in_rol->currentText();

    if(!m_controlador->validar_texto(nombre) || !m_controlador->validar_texto(apellido)){
        QMessageBox::information(this, tr("Error"), tr("Datos Erróneos o Incompletos"));
        return;
    }
    this->m_persona = new Persona_miembro(nombre, apellido, rol);
    accept();
}


void Agregar_Miembros::on_buttonBox_rejected()
{
    reject();
}


void Agregar_Miembros::on_in_nom_editingFinished()
{
    QString nombre = ui->in_nom->text();
    if(!m_controlador->validar_texto(nombre)){
        ui->in_nom->setStyleSheet("background-color: rgb(255, 105, 180)");
    }
    else{
        ui->in_nom->setStyleSheet("background-color: rgb(153, 193, 241)");
    }
}


void Agregar_Miembros::on_in_ape_editingFinished()
{
    QString apellido = ui->in_ape->text();
    if(!m_controlador->validar_texto(apellido)){
        ui->in_ape->setStyleSheet("background-color: rgb(255, 105, 180)");
    }
    else{
        ui->in_ape->setStyleSheet("background-color: rgb(153, 193, 241)");
    }
}

