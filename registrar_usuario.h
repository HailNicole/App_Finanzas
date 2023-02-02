#ifndef REGISTRAR_USUARIO_H
#define REGISTRAR_USUARIO_H

#include <QDialog>
#include <QFile>
#include <QMessageBox>
#include <QMap>
#include "controlador.h"

namespace Ui {
class Registrar_usuario;
}

class Registrar_usuario : public QDialog
{
    Q_OBJECT

public:
    explicit Registrar_usuario(QWidget *parent = nullptr);
    ~Registrar_usuario();
    QMap<QString, QString> getUsuarios() const;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_toolButton_released();

    void on_toolButton_pressed();

private:
    Ui::Registrar_usuario *ui;
    Controlador *m_controlador;
    QMap<QString,QString> usuarios;
};

#endif // REGISTRAR_USUARIO_H
