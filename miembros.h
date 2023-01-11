#ifndef MIEMBROS_H
#define MIEMBROS_H

#include <QDialog>
#include "agregar_miembros.h"
namespace Ui {
class Miembros;
}

class Miembros : public QDialog
{
    Q_OBJECT

public:
    explicit Miembros(QWidget *parent = nullptr);
    ~Miembros();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Miembros *ui;
};

#endif // MIEMBROS_H
