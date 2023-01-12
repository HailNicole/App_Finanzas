#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Principal)
{
    ui->setupUi(this);
}

Principal::~Principal()
{
    delete ui;
}

void Principal::on_actionAcerca_de_triggered()
{
    // Crear un objeto del cuadro de diálogo
    Acerca_de *dialog = new Acerca_de(this);
    // Enviar datos a la otra ventana
    dialog->setVersion(VERSION);
    // Mostrar la venta en modo MODAL
    dialog->exec();
    // Luego de cerrar la ventana, se acceden a los datos de la misma
    qDebug() << dialog->valor();
}


void Principal::on_actionAgregar_miembro_triggered()
{
    Miembros m(this);
    m.exec();
}

bool Principal::entrar()
{
    login log;

}

