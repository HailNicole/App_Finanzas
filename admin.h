#ifndef ADMIN_H
#define ADMIN_H

#include <QMainWindow>
#include "registrar_usuario.h"
#include "controlador.h"
#include "usuarios_admin.h"
#include "acceso.h"
#include "principal.h"

namespace Ui {
class Admin;
}

class Admin : public QMainWindow
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();
    bool inreso;
    bool getInreso() const;
    void setInreso(bool newInreso);

private slots:
    bool on_btn_acceder_clicked();
    void on_btn_crear_clicked();
    void on_actionPrincipal_triggered();

private:
    Ui::Admin *ui;
    QMap<QString,QString> usuario_admin;
    Controlador *m_controlador;
    void cargar_admin();
    void crear_interfaz();
    enum Columna
    {
        USUARIO, CONTRASENIA
    };
};

#endif // ADMIN_H
