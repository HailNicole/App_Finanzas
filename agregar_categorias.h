#ifndef AGREGAR_CATEGORIAS_H
#define AGREGAR_CATEGORIAS_H

#include <QDialog>

namespace Ui {
class Agregar_Categorias;
}

class Agregar_Categorias : public QDialog
{
    Q_OBJECT

public:
    explicit Agregar_Categorias(QWidget *parent = nullptr);
    ~Agregar_Categorias();

private:
    Ui::Agregar_Categorias *ui;
};

#endif // AGREGAR_CATEGORIAS_H
