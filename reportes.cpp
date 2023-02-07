#include "reportes.h"
#include "ui_reportes.h"
#include "QDebug"

Reportes::Reportes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Reportes)
{
    ui->setupUi(this);
    m_cont = new Controlador();
    combo_nom = ui->combo_nombres;
    m_cont->Cargar_Fam(combo_nom);
    lienzo = QPixmap(500,500);
    this->dibujar();
    ui->out_repor1->setPixmap(lienzo);
    ui->out_repor2->setPixmap(lienzo);
    this->cargar_registro();
}

Reportes::~Reportes()
{
    delete ui;
}

void Reportes::on_tabWidget_currentChanged(int index)
{

}

void Reportes::dibujar()
{
    lienzo.fill(Qt::white);

    QPainter painter(&lienzo);

    int x = 0;
    int y = 0;
}

void Reportes::cargar_registro()
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
            if(combo_nom->currentText() == datos.at(1)){

            }
            //qDebug()<<datos.at(1);
        }
        dts.close();
    }
}
