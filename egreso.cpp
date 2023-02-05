#include "egreso.h"
#include "ui_egreso.h"

Egreso::Egreso(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Egreso)
{
    ui->setupUi(this);
}

Egreso::~Egreso()
{
    delete ui;
}
