#include "ingreso.h"
#include "ui_ingreso.h"

Ingreso::Ingreso(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ingreso)
{
    ui->setupUi(this);
}

Ingreso::~Ingreso()
{
    delete ui;
}
