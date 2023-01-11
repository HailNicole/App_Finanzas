#ifndef AGREGAR_MIEMBROS_H
#define AGREGAR_MIEMBROS_H

#include <QDialog>

namespace Ui {
class Agregar_Miembros;
}

class Agregar_Miembros : public QDialog
{
    Q_OBJECT

public:
    explicit Agregar_Miembros(QWidget *parent = nullptr);
    ~Agregar_Miembros();

private:
    Ui::Agregar_Miembros *ui;
};

#endif // AGREGAR_MIEMBROS_H
