#include "principal.h"
#include "ui_principal.h"
#include "QDebug"

Principal::Principal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Principal)
{
    ui->setupUi(this);
    setWindowTitle("Safe Home");
}

Principal::~Principal()
{
    delete ui;
}

void Principal::on_actionAcerca_de_triggered()
{
    // Crear un objeto del cuadro de diálogo
    Acerca_de *dialog = new Acerca_de(this);
    dialog->setWindowTitle(tr("Acerca De"));
    // Enviar datos a la otra ventana
    dialog->setVersion(VERSION);
    // Mostrar la venta en modo MODAL
    dialog->exec();
}

void Principal::on_actionMiembros_triggered()
{
    Miembros *m = new Miembros(this);
    this->hide();
    m->exec();
    this->show();

}

void Principal::on_actionCategorias_triggered()
{
    Categorias *c = new Categorias(this);
    this->hide();
    c->exec();
    this->show();
}

void Principal::on_actionRegistrar_triggered()
{
    Registro *reg = new Registro(this);
    this->hide();
    reg->exec();
    this->show();
    ui->in_tti->setText(QString::number(reg->getConting()));
    ui->in_tte->setText(QString::number(reg->getContegr()));
}

bool Principal::acceso()
{
    Acceso *access = new Acceso(this);
    access->exec();

    if(m_controlador->entrar(access->getBandera())){
        return true;
    }
    return false;
}

void Principal::on_actionReporte_triggered()
{
    Reportes *reporte = new Reportes(this);
    this->hide();
    reporte->exec();
    this->show();

}

void Principal::on_actionSalir_triggered()
{
    this->close();
}

void Principal::on_actionAdministrador_triggered()
{
    this->hide();
    Admin *admin = new Admin(this);
    admin->show();
}

void Principal::changeEvent(QEvent *e)
{
    if(e->type() == QEvent::LanguageChange){
        ui->retranslateUi(this);
    }
    qApp->installTranslator(&traducion);
}

void Principal::on_actionIngles_triggered()
{
    traducion.load(":/Calculadora_en.qm");
}

void Principal::on_actionFrances_triggered()
{
    traducion.load(":/Calculadora_fr_FR.qm");
}
