#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QDebug>
#include "acerca_de.h"
#include "miembros.h"
#include "categorias.h"
#include "login.h"
#include "registrar_usuario.h"

#define VERSION "0.2"
namespace Ui {
class Principal;
}

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    explicit Principal(QWidget *parent = nullptr);
    ~Principal();

private slots:
    void on_actionAcerca_de_triggered();

    void on_actionMiembros_triggered();

    void on_actionCategorias_triggered();

    void on_actionRegistrar_triggered();

private:
    Ui::Principal *ui;
    bool entrar();
};

#endif // PRINCIPAL_H
