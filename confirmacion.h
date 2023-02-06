#ifndef CONFIRMACION_H
#define CONFIRMACION_H

#include "qdialog.h"
#include <QWidget>
#include "controlador.h"

namespace Ui {
class Confirmacion;
}

class Confirmacion : public QDialog
{
    Q_OBJECT

public:
    explicit Confirmacion(QWidget *parent = nullptr);
    ~Confirmacion();

    bool getFlag() const;
    void setFlag(bool newFlag);

private slots:
    bool on_btn_confi_clicked();

private:
    Ui::Confirmacion *ui;
    Controlador *m_controlador;
    bool flag;
};

#endif // CONFIRMACION_H
