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

    Objeto_registro *registro = new Objeto_registro();
}

