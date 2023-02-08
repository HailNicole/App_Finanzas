#include "reportes.h"
#include "ui_reportes.h"
#include "QDebug"

Reportes::Reportes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Reportes)
{
    ui->setupUi(this);
    setWindowTitle(tr("REPORTES"));
    m_cont = new Controlador();
    combo_nom = ui->combo_nombres;
    m_cont->Cargar_Fam(combo_nom);
    lienzo = QPixmap(1043,610);
    ui->out_repor1->setPixmap(lienzo);
    ui->out_repor2->setPixmap(lienzo);
    ui->verticalLayoutWidget->hide();
}

Reportes::~Reportes()
{
    delete ui;
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
                if(datos.at(3)==tr("Ingreso")){
                    ingresos.append(datos.at(4));
                    ingresos_count.append(datos.at(4));
                }else if(datos.at(3)==tr("Egreso")){
                    egresos.append(datos.at(4));
                    egresos_count.append(datos.at(4));
                }
            }
        }
        dts.close();
    }
}

void Reportes::contador()
{
    QListIterator<QString> i(ingresos);
    while(i.hasNext()){
        qDebug()<<ingresos.count(i.next());
    }
}

void Reportes::on_combo_nombres_currentIndexChanged(int index)
{
    if(!combo_nom->currentText().isEmpty()){
        ingresos.clear();
        egresos.clear();
        ui->verticalLayoutWidget->show();
        this->cargar_R();
    }
}

void Reportes::dibujarE()
{
    lienzo.fill(Qt::white);

    QPainter painter(&lienzo);

    int x = 0;
    int y = 0;

    egresos.removeDuplicates();
    for(int i=0; i<egresos.size(); i++){
        // Crear un pincel para los bordes
        QPen pincel;
        pincel.setWidth(5);
        pincel.setColor(Qt::red);
        pincel.setJoinStyle(Qt::MiterJoin);

        painter.setPen(pincel);

        int y2 = egresos_count.count(egresos.at(i));

        painter.drawRect(x+5,y+(610-y2),30,y2);

        x+=50;
    }

    ui->out_repor2->setPixmap(lienzo);
}

void Reportes::dibujarI()
{
    lienzo.fill(Qt::white);

    QPainter painter(&lienzo);

    int x = 0;
    int y = 0;

    ingresos.removeDuplicates();

    for(int i=0; i<ingresos.size(); i++){
        // Crear un pincel para los bordes
        QPen pincel;
        pincel.setWidth(5);
        pincel.setColor(Qt::red);
        pincel.setJoinStyle(Qt::MiterJoin);

        painter.setPen(pincel);

        int y2 = ingresos_count.count(ingresos.at(i));

        painter.drawRect(x+5,y+(610-y2),30,y2);

        x+=50;
    }

    ui->out_repor1->setPixmap(lienzo);
}

void Reportes::on_tabWidget_tabBarClicked(int index)
{
    if(index==0){
        dibujarI();
    }else if(index==1){
        dibujarE();
    }
}

void Reportes::on_btn_atras_clicked()
{
    this->close();
}


void Reportes::on_btn_imp_clicked()
{

}
