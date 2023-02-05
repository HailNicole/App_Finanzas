#include "reportes.h"
#include "ui_reportes.h"

Reportes::Reportes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Reportes)
{
    ui->setupUi(this);
}

Reportes::~Reportes()
{
    delete ui;
}
