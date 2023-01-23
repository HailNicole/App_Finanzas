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
    dialog->setWindowTitle("Acerca De");
    // Enviar datos a la otra ventana
    dialog->setVersion(VERSION);
    // Mostrar la venta en modo MODAL
    dialog->exec();
}


void Principal::on_actionAgregar_miembro_triggered()
{
    Miembros m(this);
   /* this->hide();
    m.exec();
    this->show();
    */
}

bool Principal::entrar()
{
    //login log;

}

