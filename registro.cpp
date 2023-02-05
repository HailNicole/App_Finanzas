#include "registro.h"
#include "ui_registro.h"

Registro::Registro(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Registro)
{
    ui->setupUi(this);

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
    }else if(ui->in_ingreso->isChecked()){
        tipo_i = Tipo::Egreso;
    }


    m_controlador2->setDatos(dia, mb, des, tipo_i, cat, value);
}

void Registro::cargar_categoria()
{
    QComboBox *combo1;
    combo1 = ui->in_categoria;
    //combo1.setModelColumn();
}
