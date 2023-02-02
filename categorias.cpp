#include "categorias.h"
#include "ui_categorias.h"

Categorias::Categorias(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Categorias)
{
    ui->setupUi(this);
    setWindowTitle("Categorias");
    // Configurar la tabla
    ui->tblLista_cat->setColumnCount(1);
    QStringList titulo;
    titulo << "Tipo";
    ui->tblLista_cat->setHorizontalHeaderLabels(titulo);
}

Categorias::~Categorias()
{
    delete ui;
}

void Categorias::on_btn_agrcat_clicked()
{

}


void Categorias::on_btn_cancat_clicked()
{

}


void Categorias::on_btn_borrarcat_clicked()
{

}


void Categorias::on_btn_editcat_clicked()
{

}

