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
    ui->out_repor1->setPixmap(lienzo);
    ui->out_repor2->setPixmap(lienzo);
    ui->verticalLayoutWidget->hide();
}

Reportes::~Reportes()
{
    delete ui;
}

void Reportes::on_tabWidget_currentChanged(int index)
{

}

void Reportes::cargar_R()
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
                if(datos.at(3)=="Ingreso"){
                    ingresos.append(datos.at(4));
                }else if(datos.at(3)=="Egreso"){
                    egresos.append(datos.at(4));
                }
            }
        }
        dts.close();
    }
}

void Reportes::on_combo_nombres_currentIndexChanged(int index)
{
    if(!combo_nom->currentText().isEmpty()){
        ui->verticalLayoutWidget->show();
        this->cargar_R();
        /*
        ingresos.count("Comida");
        ingresos.removeDuplicates();
        egresos.removeDuplicates();*/
    }
    qDebug()<<ingresos;
    qDebug()<<egresos;
}

void Reportes::dibujarE()
{
    lienzo.fill(Qt::white);

    QPainter painter(&lienzo);

    int x = 0;
    int y = 0;

    // Crear un pincel para los bordes
    QPen pincel;
    pincel.setWidth(5);
    pincel.setColor(Qt::red);
    pincel.setJoinStyle(Qt::MiterJoin);
}

void Reportes::dibujarI()
{
    lienzo.fill(Qt::white);

    QPainter painter(&lienzo);

    int x = 0;
    int y = 0;

    // Crear un pincel para los bordes
    QPen pincel;
    pincel.setWidth(5);
    pincel.setColor(Qt::red);
    pincel.setJoinStyle(Qt::MiterJoin);
}

void Reportes::on_tabWidget_tabBarClicked(int index)
{

}

