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
    lienzo = new QPixmap(ui->out_repor1->width(),ui->out_repor1->height());
    lienzo2 = new QPixmap(ui->out_repor2->width(),ui->out_repor2->height());
    lienzo->fill(Qt::white);
    lienzo2->fill(Qt::white);
    ui->out_repor1->setPixmap(*lienzo);
    ui->out_repor2->setPixmap(*lienzo2);
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
       QPainter painter(lienzo2);
       QPen pincel;

       int x = 5;
       int y = 0;

       egresos.removeDuplicates();

       for(int i=0; i<egresos.size(); i++){
           QColor *colorBorde = new QColor(165+i+5,42+i+5,42+i+5);

           pincel.setWidth(5);
           pincel.setColor(*colorBorde);
           pincel.setJoinStyle(Qt::MiterJoin);
           painter.setPen(pincel);

           int y2 = egresos_count.count(egresos.at(i));

           painter.drawRect(x,y+(ui->out_repor2->height()-y2),60,y2);
           painter.setFont(QFont("Arial", 12));
           pincel.setColor(Qt::black);
           painter.setPen(pincel);
           painter.drawText(x-2, y+(ui->out_repor1->height()-y2)-3, egresos.value(i));

           x+=75;
       }

       ui->out_repor2->setPixmap(*lienzo2);
}

void Reportes::dibujarI()
{
        QPainter painter(lienzo);
        QPen pincel;

        int x = 5;
        int y = 0;

        ingresos.removeDuplicates();

        for(int i=0; i<ingresos.size(); i++){
            QColor *colorBorde = new QColor(165+i+5,42+i+5,42+i+5);

            pincel.setWidth(5);
            pincel.setColor(*colorBorde);
            pincel.setJoinStyle(Qt::MiterJoin);

            painter.setPen(pincel);

            int y2 = ingresos_count.count(ingresos.at(i));

            painter.drawRect(x,y+(ui->out_repor1->height()-y2),60,y2);

            painter.setFont(QFont("Arial", 12));
            pincel.setColor(Qt::black);
            painter.setPen(pincel);
            painter.drawText(x-2, y+(ui->out_repor1->height()-y2)-3, ingresos.value(i));

            x+=75;
        }
        ui->out_repor1->setPixmap(*lienzo);
}

void Reportes::on_tabWidget_tabBarClicked(int index)
{
    if(index==0){
        lienzo->fill(Qt::white);
        dibujarI();
    }else if(index==1){
        lienzo2->fill(Qt::white);
        dibujarE();
    }
}

void Reportes::on_btn_atras_clicked()
{
    this->close();
}


void Reportes::on_btn_imp_clicked()
{
    //Crear un objeto QDir a partir del directorio del usuario
    QDir directorio = QDir::home();
    QString pathArchivo = directorio.absolutePath() + "/Reportes.pdf";

    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(pathArchivo);

    QPainter painter;
    if(!painter.begin(&printer)){
        return;
    }

    painter.drawPixmap(0,100, *lienzo);

    if(!printer.newPage()){
        return;
    }
    painter.drawPixmap(0,100,*lienzo2);
    painter.end();

    QDesktopServices::openUrl(QUrl::fromLocalFile(pathArchivo));
}

void Reportes::on_btn_savereport_clicked()
{
    // Abrir cuadro de diálogo para obtener el nombre del archivo
    QString nombreArchivo = QFileDialog::getSaveFileName(this,
                                                         "Guardar imagen",
                                                         QDir::home().absolutePath() + "/reportes.png",
                                                         "Imágenes .png (*.png)");
    // Validar que el nombre del archivo no sea vacío
    if ( !nombreArchivo.isEmpty()){
        // Guardar imagen
        if(ui->tab->isVisible()){
            if (lienzo->save(nombreArchivo)){
                // Si todo va bien, muestra un mensaje de información
                QMessageBox::information(this,
                                         "Guardar imagen",
                                         "Archivo almacenado en: " + nombreArchivo);
            } else{
                // Si hay algún error, muestro advertencia
                QMessageBox::warning(this,
                                     "Guardar imagen",
                                     "No se pudo almacenar la imagen.");
            }
        };
        if(ui->tab_2->isVisible()){
            if (lienzo2->save(nombreArchivo)){
                // Si todo va bien, muestra un mensaje de información
                QMessageBox::information(this,
                                         "Guardar imagen",
                                         "Archivo almacenado en: " + nombreArchivo);
            } else{
                // Si hay algún error, muestro advertencia
                QMessageBox::warning(this,
                                     "Guardar imagen",
                                     "No se pudo almacenar la imagen.");
            }
        };

    }
}

