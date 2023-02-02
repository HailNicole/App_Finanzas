#include "miembros.h"
#include "ui_miembros.h"

#include "QDebug"

Miembros::Miembros(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Miembros)
{
    ui->setupUi(this);
    setWindowTitle("Miembros de la Familia");
    // Configurar la tabla
    ui->tblLista->setColumnCount(3);
    QStringList titulo;
    titulo << "Nombre" << "Apellido" << "Rol";
    ui->tblLista->setHorizontalHeaderLabels(titulo);
    cargarFamiliares();
}

Miembros::~Miembros()
{
    delete ui;
}

void Miembros::on_btn_agregar_clicked()
{
    // Crear y mostrar el dialogo
    Agregar_Miembros agr(this);
    agr.setWindowTitle("Agregar Familiar");
    // Abrir la ventana y evaluar respuesta
    int res = agr.exec();
    if (res == QDialog::Rejected){
        return;
    }
    // Recuperar el objeto del cuadro de dialogo
    Persona_miembro *per = agr.persona();
    //Agregar a la tabla
    int fila = ui->tblLista->rowCount();
    ui->tblLista->insertRow(fila);
    ui->tblLista->setItem(fila, NOMBRE, new QTableWidgetItem(per->nombre()));
    ui->tblLista->setItem(fila, APELLIDO, new QTableWidgetItem(per->apellido()));
    ui->tblLista->setItem(fila, ROL, new QTableWidgetItem(per->rol()));
}

void Miembros::on_btn_borrar_clicked()
{
    QList<QModelIndex>big = ui->tblLista->selectionModel()->selectedRows();
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
        ui->tblLista->removeRow(x);
    }
}


void Miembros::on_btn_editar_clicked()
{
    int cont=0;
    QList<QModelIndex>seleccion = ui->tblLista->selectionModel()->selectedRows();

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

    int row = ui->tblLista->currentRow();

    QTableWidgetItem *nombre = ui->tblLista->item(row, NOMBRE);
    QTableWidgetItem *apellido = ui->tblLista->item(row, APELLIDO);
    QTableWidgetItem *rol = ui->tblLista->item(row, ROL);

    Agregar_Miembros agr(this);
    agr.setWindowTitle("Agregar Familiar");

    agr.set_datos(nombre->text(), apellido->text(), rol->text());

    int res = agr.exec();
    if (res == QDialog::Rejected){
        return;
    }
    // Recuperar el objeto del cuadro de dialogo
    Persona_miembro *per = agr.persona();

    ui->tblLista->setItem(row, NOMBRE, new QTableWidgetItem(per->nombre()));
    ui->tblLista->setItem(row, APELLIDO, new QTableWidgetItem(per->apellido()));
    ui->tblLista->setItem(row, ROL, new QTableWidgetItem(per->rol()));
}


void Miembros::on_btn_cancelar_clicked()
{
    this->close();
}


void Miembros::on_btn_guardar_clicked()
{
    // Verificar que exista datos para guardar
    int filas = ui->tblLista->rowCount();
    if (filas == 0){
        QMessageBox::warning(0,"Guardar contactos","Agenda sin datos para guardar");
        return;
    }

    // Abrir el archivo y guardar
    QFile archivo(ARCHIVO1);
    if (archivo.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream salida(&archivo);
        for (int i=0; i<filas; i++) {
            QTableWidgetItem *nombre = ui->tblLista->item(i, NOMBRE);
            QTableWidgetItem *apellido = ui->tblLista->item(i, APELLIDO);
            QTableWidgetItem *rol = ui->tblLista->item(i, ROL);
            salida << nombre->text() << ";" << apellido->text() << ";";
            salida << rol->text()<< "\n";
        }
        archivo.close();
        QMessageBox::information(this,"Guardar contactos","Contactos guardados con éxito");
    }else{
        QMessageBox::critical(this,"Guardar contactos", "No se puede escribir sobre " + ARCHIVO1);
    }
}

void Miembros::cargarFamiliares()
{
    // Verificar si el archivo existe
    QFile arc(ARCHIVO1);
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
            fila = ui->tblLista->rowCount();
            ui->tblLista->insertRow(fila);
            ui->tblLista->setItem(fila, NOMBRE, new QTableWidgetItem(datos[NOMBRE]));
            ui->tblLista->setItem(fila, APELLIDO, new QTableWidgetItem(datos[APELLIDO]));
            ui->tblLista->setItem(fila, ROL, new QTableWidgetItem(datos[ROL]));
        }
        arc.close();
    }
}

