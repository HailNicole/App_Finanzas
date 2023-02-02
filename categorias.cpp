#include "categorias.h"
#include "ui_categorias.h"

Categorias::Categorias(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Categorias)
{
    ui->setupUi(this);
    setWindowTitle("Categorias");
    // Configurar la tabla
    ui->tblLista_cat->setColumnCount(2);
    QStringList titulo;
    titulo <<"ID" << "Tipo";
    ui->tblLista_cat->setHorizontalHeaderLabels(titulo);
}

Categorias::~Categorias()
{
    delete ui;
}

void Categorias::on_btn_agrcat_clicked()
{
    Agregar_Categorias agr_cat(this);
    // Abrir la ventana y evaluar respuesta
    int res = agr_cat.exec();
    if (res == QDialog::Rejected){
        return;
    }
    //Agregar a la tabla
    int fila = ui->tblLista_cat->rowCount();
    Tipo_categoria tp = agr_cat.getTipo();
    Objeto_categoria *cat = new Objeto_categoria(fila+1, tp);
    QString tp_str = cat->Tipo_String();
    ui->tblLista_cat->insertRow(fila);
    ui->tblLista_cat->setItem(fila, ID, new QTableWidgetItem(cat->id()));
    ui->tblLista_cat->setItem(fila, TIPO, new QTableWidgetItem(tp_str));
}


void Categorias::on_btn_cancat_clicked()
{
    this->close();
}


void Categorias::on_btn_borrarcat_clicked()
{

}


void Categorias::on_btn_editcat_clicked()
{

}

