#include "categorias.h"
#include "ui_categorias.h"
#include "QDebug"
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
    ui->tblLista_cat->setItem(fila, ID, new QTableWidgetItem(QString::number(cat->id())));
    if(agr_cat.getBandera()){
        cat->setTipo2(agr_cat.getValue_tipo2());
        ui->tblLista_cat->setItem(fila, TIPO, new QTableWidgetItem(cat->tipo2()));
    }else{
         ui->tblLista_cat->setItem(fila, TIPO, new QTableWidgetItem(tp_str));
    }
}


void Categorias::on_btn_cancat_clicked()
{
    this->close();
}


void Categorias::on_btn_borrarcat_clicked()
{
    QList<QModelIndex>big = ui->tblLista_cat->selectionModel()->selectedRows();
    if(big.isEmpty()){
        QMessageBox::information(this,"Seleccion","No se ha seleccionado ninguna fila :|");
        return;
    }

    QList<int> list;
    QList<int>::iterator x;
    QList<QModelIndex>::iterator i;

    for (auto &&i : big){
        list.append(i.row());
    }

    for (auto &&x : list){
        ui->tblLista_cat->removeRow(x);
    }
}


void Categorias::on_btn_editcat_clicked()
{
    int cont=0;
    QList<QModelIndex>seleccion = ui->tblLista_cat->selectionModel()->selectedRows();

    if(seleccion.isEmpty()){
        QMessageBox::information(this,"Seleccion","No se ha seleccionado ninguna fila :|");
        return;
    }

    QList<QModelIndex>::iterator i;

    for (auto &&i : seleccion){
        cont++;
    }

    if(cont>1){
        QMessageBox::information(this,"Seleccion","Seleccione SOLO UNA fila");
        return;
    }

    int row = ui->tblLista_cat->currentRow();

    Agregar_Categorias agr_cat(this);

    int res = agr_cat.exec();
    if (res == QDialog::Rejected){
        return;
    }

    Tipo_categoria tp = agr_cat.getTipo();
    Objeto_categoria *cat = new Objeto_categoria(row+1, tp);
    QString tp_str = cat->Tipo_String();

    ui->tblLista_cat->setItem(row, ID, new QTableWidgetItem(QString::number(cat->id())));
    if(agr_cat.getBandera()){
        cat->setTipo2(agr_cat.getValue_tipo2());
        ui->tblLista_cat->setItem(row, TIPO, new QTableWidgetItem(cat->tipo2()));
    }else{
         ui->tblLista_cat->setItem(row, TIPO, new QTableWidgetItem(tp_str));
    }
}

