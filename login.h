#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QMessageBox>
#include "registrar_usuario.h"

QT_BEGIN_NAMESPACE
namespace Ui { class login; }
QT_END_NAMESPACE

class login : public QMainWindow
{
    Q_OBJECT

public:
    login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_btn_Registrar_clicked();
    bool on_btn_Ingresar_clicked();

private:
    Ui::login *ui;
    const QString ARCHIVO = "registros.csv";
    QMap<QString,QString> usuarios2;
    void cargarUsuarios();
    enum Columna
    {
        USUARIO, CONTRASENIA
    };
};
#endif // LOGIN_H

