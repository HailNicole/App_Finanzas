#ifndef EGRESO_H
#define EGRESO_H

#include <QWidget>

namespace Ui {
class Egreso;
}

class Egreso : public QWidget
{
    Q_OBJECT

public:
    explicit Egreso(QWidget *parent = nullptr);
    ~Egreso();

private:
    Ui::Egreso *ui;
};

#endif // EGRESO_H
