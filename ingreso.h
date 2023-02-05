#ifndef INGRESO_H
#define INGRESO_H

#include <QWidget>

namespace Ui {
class Ingreso;
}

class Ingreso : public QWidget
{
    Q_OBJECT

public:
    explicit Ingreso(QWidget *parent = nullptr);
    ~Ingreso();

private:
    Ui::Ingreso *ui;
};

#endif // INGRESO_H
