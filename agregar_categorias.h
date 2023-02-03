#ifndef AGREGAR_CATEGORIAS_H
#define AGREGAR_CATEGORIAS_H

#include <QDialog>
#include "objeto_categoria.h"
#include <QMessageBox>
#include "controlador.h"

namespace Ui {
class Agregar_Categorias;
}

class Agregar_Categorias : public QDialog
{
    Q_OBJECT

public:
    explicit Agregar_Categorias(QWidget *parent = nullptr);
    ~Agregar_Categorias();
    Objeto_categoria *categoria() const;
    Tipo_categoria getTipo() const;
    QString getValue_tipo2() const;

    bool getBandera() const;
    void setBandera(bool newBandera);

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void on_in_otro_editingFinished();

    void on_r_otro_pressed();

    void on_r_sb_clicked();

    void on_r_aca_clicked();

    void on_r_salud_clicked();

    void on_r_arriendo_clicked();

    void on_r_comida_clicked();

    void on_r_pp_clicked();

private:
    Ui::Agregar_Categorias *ui;
    Objeto_categoria *m_categoria;
    Tipo_categoria tipo;
    QString value_tipo2;
    bool bandera;
    Controlador *m_controlador;
};

#endif // AGREGAR_CATEGORIAS_H
