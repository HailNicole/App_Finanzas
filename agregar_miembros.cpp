#include "agregar_miembros.h"
#include "ui_agregar_miembros.h"

Agregar_Miembros::Agregar_Miembros(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Agregar_Miembros)
{
    ui->setupUi(this);
    setWindowTitle("Agregar Miembro");
}

Agregar_Miembros::~Agregar_Miembros()
{
    delete ui;
}
