#ifndef REGISTRO_H
#define REGISTRO_H

#include <QWidget>
#include "objeto_registro.h"

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
};

#endif // REGISTRO_H
