#ifndef ACCESO_H
#define ACCESO_H

#include <QWidget>
#include "registrar_usuario.h"
#include "controlador.h"
#include <QTranslator>

namespace Ui {
class Acceso;
}

class Acceso : public QDialog
{
    Q_OBJECT

public:
    explicit Acceso(QWidget *parent = nullptr);
    ~Acceso();
    bool getBandera() const;
    void setBandera(bool newBandera);

private slots:
    bool on_btn_Ingresar_clicked();
    void on_btn_Registrar_clicked();

    void on_btn_ingles_clicked();

    void on_btn_francia_clicked();

private:
    Ui::Acceso *ui;
    QMap<QString,QString> usuarios2;
    Controlador *m_controlador;
    bool bandera;
    enum Columna
    {
        USUARIO, CONTRASENIA
    };
};

#endif // ACCESO_H
