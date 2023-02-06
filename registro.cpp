#include "registro.h"
#include "ui_registro.h"
#include "QDebug"

Registro::Registro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registro)
{
    ui->setupUi(this);
    m_controlador2 = new Controlador();
    combo1 = ui->in_categoria;
    combo2 = ui->in_miembro;
    m_controlador2->Cargar_Cat(combo1);
    m_controlador2->Cargar_Fam(combo2);
    cargar_Reg();
}

Registro::~Registro()
{
    delete ui;
}

void Registro::on_btn_SalirREg_clicked()
{
    this->close();
}

void Registro::on_btnGuardarReg_clicked()
{
    QString dia = ui->in_day->text();
    QString mb = ui->in_miembro->currentText();
    QString des = ui->in_descripcion->toPlainText();
    QString cat = ui->in_categoria->currentText();
    double value = ui->in_valor->value();

    if(ui->in_ingreso->isChecked()){
        tipo_i = Tipo::Ingreso;
    }else if(ui->in_egreso->isChecked()){
        tipo_i = Tipo::Egreso;
    }else{
        QMessageBox::information(this, tr("Error"), tr("Seleccione al menos una opción"));
        return;
    }

    if(!m_controlador2->validar_campo_vacio(mb) || !m_controlador2->validar_campo_vacio(des) || !m_controlador2->validar_campo_vacio(cat) || value == 0){
        QMessageBox::information(this,tr("Registro"),tr("Por favor llene todos los campos"));
        return;
    }

    m_controlador2->setDatos(dia, mb, des, tipo_i, cat, value);
    Objeto_registro *obj = new Objeto_registro(dia, mb, des, tipo_i, cat, value);
    list.append(obj);
    m_controlador2->Guardar_R(list);
}

void Registro::on_btn_limpiar_clicked()
{
    limpiar();
}

void Registro::limpiar()
{
    ui->in_day->clear();
    ui->in_miembro->clearEditText();
    ui->in_descripcion->clear();
    ui->in_ingreso->setChecked(false);
    ui->in_egreso->setChecked(false);
    ui->in_categoria->clearEditText();
    ui->in_valor->setValue(0);
}

void Registro::cargar_Reg()
{
    // Verificar si el archivo existe
    QFile dts("registro_datos.csv");
    if (!dts.exists())
        return;
    // cargar datos
    if (dts.open(QFile::ReadOnly)) {
        QTextStream entrada(&dts);
        while(!entrada.atEnd()){
            QString linea = entrada.readLine();
            QStringList datos = linea.split(";");
            qDebug()<<datos;
        }
        dts.close();
    }
}

