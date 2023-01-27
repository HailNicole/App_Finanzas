#include "agregar_categorias.h"
#include "ui_agregar_categorias.h"

Agregar_Categorias::Agregar_Categorias(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Agregar_Categorias)
{
    ui->setupUi(this);
    setWindowTitle("Agregar Categoria");
}

Agregar_Categorias::~Agregar_Categorias()
{
    delete ui;
}
