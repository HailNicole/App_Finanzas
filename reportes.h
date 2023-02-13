#ifndef REPORTES_H
#define REPORTES_H

#include "qdialog.h"
#include <QWidget>
#include "controlador.h"
#include <QPainter>
#include <QPixmap>
#include <QFileDialog>
#include <QFile>
#include <QDir>
#include <QMessageBox>
#include <QList>
#include <QDesktopServices>
#include <QUrl>
#include <QPdfWriter>
#include <QPrinter>
#include <QPrintDialog>

namespace Ui {
class Reportes;
}

class Reportes : public QDialog
{
    Q_OBJECT

public:
    explicit Reportes(QWidget *parent = nullptr);
    ~Reportes();

private slots:

    void on_combo_nombres_currentIndexChanged(int index);

    void on_tabWidget_tabBarClicked(int index);

    void on_btn_atras_clicked();

    void on_btn_imp_clicked();

    void on_btn_savereport_clicked();

private:
    Ui::Reportes *ui;
    Controlador *m_cont;
    QComboBox *combo_nom;
    QPixmap *lienzo, *lienzo2;

    void dibujarI();
    void dibujarE();
    void cargar_R();
    void contador();


    QList<QString> ingresos;
    QList<QString> egresos;

    QList<QString> ingresos_count;
    QList<QString> egresos_count;

};

#endif // REPORTES_H
