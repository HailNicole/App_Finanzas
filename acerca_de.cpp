#include "acerca_de.h"
#include "ui_acerca_de.h"

Acerca_de::Acerca_de(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Acerca_de)
{
    ui->setupUi(this);
}

Acerca_de::~Acerca_de()
{
    delete ui;
}

void Acerca_de::setVersion(const QString &newVersion)
{
    m_version = newVersion;
    ui->outVersion->setText("v " + m_version);
}

int Acerca_de::valor() const
{
     return m_valor;
}
