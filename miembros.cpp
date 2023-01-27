#include "miembros.h"
#include "ui_miembros.h"

Miembros::Miembros(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Miembros)
{
    ui->setupUi(this);
    setWindowTitle("Miembros");
    ui->tblLista->setColumnCount(3);
    QStringList titulo;
    titulo << "Nombre" << "Apellido" << "Rol";
    ui->tblLista->setHorizontalHeaderLabels(titulo);
}

Miembros::~Miembros()
{
    delete ui;
}

void Miembros::on_buttonBox_accepted()
{
    Agregar_Miembros a;
    a.exec();
}


void Miembros::on_buttonBox_rejected()
{
    reject();
}
