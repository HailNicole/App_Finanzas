#ifndef REPORTES_H
#define REPORTES_H

#include "qdialog.h"
#include <QWidget>
#include "controlador.h"
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>

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
    void on_tabWidget_currentChanged(int index);

private:
    Ui::Reportes *ui;
    Controlador *m_cont;
    QComboBox *combo_nom;
    QPixmap lienzo;
    void dibujar();
    void cargar_registro();
};

#endif // REPORTES_H
