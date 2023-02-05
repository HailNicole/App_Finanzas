#include "agregar_categorias.h"
#include "ui_agregar_categorias.h"
#include "QDebug"

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
    }else if(ui->r_otro->isChecked()){
        tipo = Tipo_categoria::Otros;
        value_tipo2=ui->in_otro->text();
        if(value_tipo2.isEmpty()){
            QMessageBox::information(this, tr("Error"), tr("Por favor llene la casilla"));
            return;
        }
        setBandera(true);
    }else{
        QMessageBox::information(this, tr("Error"), tr("Seleccione al menos una opción"));
        return;
    }
    accept();
}

void Agregar_Categorias::on_buttonBox_rejected()
{
    reject();
}


void Agregar_Categorias::on_in_otro_editingFinished()
{
    QString txt = ui->in_otro->text();
    if(!m_controlador->validar_texto(txt)){
        ui->in_otro->setStyleSheet("background-color: rgb(255, 105, 180)");
        QMessageBox::information(this, tr("Error"), tr("Solo se permiten letras"));
    }
    else{
        ui->in_otro->setStyleSheet("background-color: rgb(153, 193, 241)");
    }
}

Tipo_categoria Agregar_Categorias::getTipo() const
{
    return tipo;
}

Objeto_categoria *Agregar_Categorias::categoria() const
{
    return m_categoria;
}

QString Agregar_Categorias::getValue_tipo2() const
{
    return value_tipo2;
}

void Agregar_Categorias::on_r_otro_pressed()
{
    ui->in_otro->setEnabled(true);

}

void Agregar_Categorias::on_r_sb_clicked()
{
    ui->in_otro->setEnabled(false);
}


void Agregar_Categorias::on_r_aca_clicked()
{
    ui->in_otro->setEnabled(false);
}


void Agregar_Categorias::on_r_salud_clicked()
{
    ui->in_otro->setEnabled(false);
}


void Agregar_Categorias::on_r_arriendo_clicked()
{
    ui->in_otro->setEnabled(false);
}


void Agregar_Categorias::on_r_comida_clicked()
{
    ui->in_otro->setEnabled(false);
}


void Agregar_Categorias::on_r_pp_clicked()
{
    ui->in_otro->setEnabled(false);
}

bool Agregar_Categorias::getBandera() const
{
    return bandera;
}

void Agregar_Categorias::setBandera(bool newBandera)
{
    bandera = newBandera;
}
