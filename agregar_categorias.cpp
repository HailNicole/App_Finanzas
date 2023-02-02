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

void Agregar_Categorias::on_buttonBox_accepted()
{

    if(ui->r_salud->isChecked()){
        tipo = Tipo_categoria::Salud;
    }else if (ui->r_arriendo->isChecked()){
        tipo = Tipo_categoria::Arriendo;
    }else if(ui->r_aca->isChecked()){
        tipo = Tipo_categoria::Académico;
    }else if(ui->r_comida->isChecked()){
        tipo = Tipo_categoria::Comida;
    }else if(ui->r_sb->isChecked()){
        tipo = Tipo_categoria::Servicios_Basicos;
    }else if(ui->r_pp->isChecked()){
        tipo = Tipo_categoria::Personales;
    }else {
        ui->in_otro->setEnabled(true);
        tipo = Tipo_categoria::Otros;
    }
    accept();
}


void Agregar_Categorias::on_buttonBox_rejected()
{
    reject();
}


void Agregar_Categorias::on_in_otro_editingFinished()
{

}

Tipo_categoria Agregar_Categorias::getTipo() const
{
    return tipo;
}

Objeto_categoria *Agregar_Categorias::categoria() const
{
    return m_categoria;
}

