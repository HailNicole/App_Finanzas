#ifndef MIEMBROS_H
#define MIEMBROS_H

#include <QWidget>
#include "agregar_miembros.h"
#include <QMessageBox>

namespace Ui {
class Miembros;
}

class Miembros : public QDialog
{
    Q_OBJECT

public:
    explicit Miembros(QWidget *parent = nullptr);
    ~Miembros();

private slots:
    void on_btn_agregar_clicked();

    void on_btn_borrar_clicked();

    void on_btn_editar_clicked();

    void on_btn_cancelar_clicked();

    void on_btn_guardar_clicked();

private:
    Ui::Miembros *ui;
    enum Columna
    {
        NOMBRE, APELLIDO, ROL
    };
    void cargarFamiliares();
};

#endif // MIEMBROS_H
