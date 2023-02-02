#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Principal)
{
    ui->setupUi(this);
    setWindowTitle("Safe Home");

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


void Principal::on_actionMiembros_triggered()
{
    Miembros m(this);
    this->hide();
    m.exec();
    this->show();

}

void Principal::on_actionCategorias_triggered()
{
    Categorias c(this);
    this->hide();
    c.exec();
    this->show();
}

void Principal::on_actionRegistrar_triggered()
{
    Registrar_usuario ru(this);
    this->hide();
    ru.exec();
    this->show();
}

bool Principal::entrar()
{
    //login log;
}

