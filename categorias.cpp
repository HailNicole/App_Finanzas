#include "categorias.h"
#include "ui_categorias.h"

Categorias::Categorias(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Categorias)

{
    ui->setupUi(this);
    setWindowTitle("Categorias");
    ui->tabla->setColumnCount(3);
    QStringList titulo;
    titulo << "ID" << "Nombre" << "Tipo";
    ui->tabla->setHorizontalHeaderLabels(titulo);
}

Categorias::~Categorias()
{
    delete ui;
}

void Categorias::on_buttonBox_accepted()
{
    Agregar_Categorias ac;
    ac.exec();
}


void Categorias::on_buttonBox_rejected()
{
    reject();
}
