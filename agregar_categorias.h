#ifndef AGREGAR_CATEGORIAS_H
#define AGREGAR_CATEGORIAS_H

#include <QDialog>
#include "objeto_categoria.h"

namespace Ui {
class Agregar_Categorias;
}

class Agregar_Categorias : public QDialog
{
    Q_OBJECT

public:
    explicit Agregar_Categorias(QWidget *parent = nullptr);
    ~Agregar_Categorias();
    Objeto_categoria *categoria() const;

    Tipo_categoria getTipo() const;

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void on_in_otro_editingFinished();

private:
    Ui::Agregar_Categorias *ui;
    Objeto_categoria *m_categoria;
    Tipo_categoria tipo;
};

#endif // AGREGAR_CATEGORIAS_H
