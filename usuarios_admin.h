#ifndef USUARIOS_ADMIN_H
#define USUARIOS_ADMIN_H

#include "qdialog.h"
#include <QWidget>
#include "acceso.h"
#include "controlador.h"
#include <QLabel>
#include <QLineEdit>

namespace Ui {
class Usuarios_admin;
}

class Usuarios_admin : public QDialog
{
    Q_OBJECT

public:
    explicit Usuarios_admin(QWidget *parent = nullptr);
    ~Usuarios_admin();

private slots:


    void on_btn_borrarUser_clicked();

    void on_btn_exit_clicked();

    void on_btn_elimadmin_clicked();

private:
    Ui::Usuarios_admin *ui;
    enum Columna
    {
        Usuario, Contrasenia
    };
    Acceso *acces;
    void cargar_cuentas();
    void crear_dialog();
    Controlador *m_controlador;
};

#endif // USUARIOS_ADMIN_H
