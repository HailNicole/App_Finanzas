#ifndef USUARIOS_ADMIN_H
#define USUARIOS_ADMIN_H

#include <QDialog>
#include <QWidget>
#include "controlador.h"
#include <QMap>
#include "confirmacion.h"

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
    void cargar_cuentas();
    Controlador *m_controlador;
    QMap<QString,QString> new_usuarios;
};

#endif // USUARIOS_ADMIN_H
