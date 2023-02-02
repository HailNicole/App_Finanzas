#ifndef AGREGAR_MIEMBROS_H
#define AGREGAR_MIEMBROS_H

#include <QDialog>
#include "persona_miembro.h"
#include "controlador.h"

namespace Ui {
class Agregar_Miembros;
}

class Agregar_Miembros : public QDialog
{
    Q_OBJECT

public:
    explicit Agregar_Miembros(QWidget *parent = nullptr);
    void set_datos(QString nom, QString ape, QString rol);
    Persona_miembro *persona() const;
    ~Agregar_Miembros();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void on_in_nom_editingFinished();
    void on_in_ape_editingFinished();

private:
    Ui::Agregar_Miembros *ui;
    Persona_miembro *m_persona;
    Controlador *m_controlador;
};

#endif // AGREGAR_MIEMBROS_H
