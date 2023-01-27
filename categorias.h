#ifndef CATEGORIAS_H
#define CATEGORIAS_H

#include <QDialog>
#include "agregar_categorias.h"

namespace Ui {
class Categorias;
}

class Categorias : public QDialog
{
    Q_OBJECT

public:
    explicit Categorias(QWidget *parent = nullptr);
    ~Categorias();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Categorias *ui;
};

#endif // CATEGORIAS_H
