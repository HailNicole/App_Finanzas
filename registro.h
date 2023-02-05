#ifndef REGISTRO_H
#define REGISTRO_H

#include <QWidget>
#include "objeto_registro.h"
#include "controlador.h"
#include "categorias.h"
#include "objeto_categoria.h"

namespace Ui {
class Registro;
}

class Registro : public QWidget
{
    Q_OBJECT

public:
    explicit Registro(QWidget *parent = nullptr);
    ~Registro();

private slots:
    void on_btn_SalirREg_clicked();
    void on_btnGuardarReg_clicked();

private:
    Ui::Registro *ui;
    Tipo tipo_i;
    Controlador *m_controlador2;
    void cargar_miembros();
    void cargar_categoria();
};

#endif // REGISTRO_H
