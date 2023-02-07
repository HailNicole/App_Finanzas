#ifndef REGISTRO_H
#define REGISTRO_H

#include <QWidget>
#include <QMessageBox>
#include "objeto_registro.h"
#include "controlador.h"
#include <QList>
namespace Ui {
class Registro;
}

class Registro : public QDialog
{
    Q_OBJECT

public:
    explicit Registro(QWidget *parent = nullptr);
    ~Registro();

private slots:
    void on_btn_SalirREg_clicked();
    void on_btnGuardarReg_clicked();
    void on_btn_limpiar_clicked();

private:
    Ui::Registro *ui;
    Tipo tipo_i;
    Controlador *m_controlador2;
    QComboBox *combo1, *combo2;
    QList<Objeto_registro*> list;
    void limpiar();
    void Cargar_Registro();
};

#endif // REGISTRO_H
