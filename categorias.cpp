#include "categorias.h"
#include "ui_categorias.h"
#include "QDebug"
Categorias::Categorias(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Categorias)
{
    ui->setupUi(this);
    setWindowTitle(tr("Categorias"));
    // Configurar la tabla
    ui->tblLista_cat->setColumnCount(2);
    QStringList titulo;
    titulo <<tr("ID") << tr("Tipo");
    ui->tblLista_cat->setHorizontalHeaderLabels(titulo);
    cargarCategorias();
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
        QMessageBox::information(this,tr("Seleccion"),tr("No se ha seleccionado ninguna fila"));
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
        QMessageBox::information(this,tr("Seleccion"),tr("No se ha seleccionado ninguna fila"));
        return;
    }

    QList<QModelIndex>::iterator i;

    for (auto &&i : seleccion){
        cont++;
    }

    if(cont>1){
        QMessageBox::information(this,tr("Seleccion"),tr("Seleccione SOLO UNA fila"));
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

void Categorias::on_btn_guardarcat_clicked()
{
    // Verificar que exista datos para guardar
    int filas = ui->tblLista_cat->rowCount();
    if (filas == 0){
        QMessageBox::warning(this,tr("Guardar Categorias"),tr("Sin datos para guardar"));
        return;
    }

    // Abrir el archivo y guardar
    QFile archivo2(ARCHIVO2);
    if (archivo2.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream salida(&archivo2);
        for (int i=0; i<filas; i++) {
            QTableWidgetItem *id = ui->tblLista_cat->item(i, ID);
            QTableWidgetItem *tipo = ui->tblLista_cat->item(i, TIPO);
            salida << id->text() << ";" << tipo->text() << "\n";
        }
        archivo2.close();
        QMessageBox::information(this,tr("Guardar Categorias"),tr("Datos guardados con éxito"));
    }else{
        QMessageBox::critical(this,tr("Guardar Categorias"), tr("No se puede escribir sobre ") + ARCHIVO2);
    }
}

void Categorias::cargarCategorias()
{
    // Verificar si el archivo existe
    QFile arc(ARCHIVO2);
    if (!arc.exists())
        return;

    // cargar datos
    if (arc.open(QFile::ReadOnly)) {
        QTextStream entrada(&arc);
        int fila;
        while(!entrada.atEnd()){
            QString linea = entrada.readLine();
            QStringList datos = linea.split(";");
            //Agregar a la tabla
            fila = ui->tblLista_cat->rowCount();
            ui->tblLista_cat->insertRow(fila);
            ui->tblLista_cat->setItem(fila, ID, new QTableWidgetItem(datos[ID]));
            ui->tblLista_cat->setItem(fila, TIPO, new QTableWidgetItem(datos[TIPO]));
        }
        arc.close();
    }
}
