#ifndef CATEGORIAS_H
#define CATEGORIAS_H

#include <QDialog>
#include <QWidget>
#include "agregar_categorias.h"
#include <QMessageBox>

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
    void on_btn_agrcat_clicked();

    void on_btn_cancat_clicked();

    void on_btn_borrarcat_clicked();

    void on_btn_editcat_clicked();

private:
    Ui::Categorias *ui;
    enum Columna
    {
        ID, TIPO
    };
};

#endif // CATEGORIAS_H
