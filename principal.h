#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QDebug>
#include <QTranslator>
#include <QEvent>
#include "acerca_de.h"
#include "miembros.h"
#include "categorias.h"
#include "controlador.h"
#include "acceso.h"
#include "registro.h"
#include "reportes.h"
#include "admin.h"
#include "usuarios_admin.h"

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
    bool acceso();

private slots:
    void on_actionAcerca_de_triggered();

    void on_actionMiembros_triggered();

    void on_actionCategorias_triggered();

    void on_actionRegistrar_triggered();

    void on_actionSalir_triggered();

    void on_actionReporte_triggered();

    void on_actionAdministrador_triggered();

    void on_actionIngles_triggered();

    void on_actionFrances_triggered();

protected:
    void changeEvent(QEvent * event) override;
private:
    Ui::Principal *ui;
    Controlador *m_controlador;
    QTranslator traducion;
};

#endif // PRINCIPAL_H
