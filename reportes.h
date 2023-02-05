#ifndef REPORTES_H
#define REPORTES_H

#include "qdialog.h"
#include <QWidget>

namespace Ui {
class Reportes;
}

class Reportes : public QDialog
{
    Q_OBJECT

public:
    explicit Reportes(QWidget *parent = nullptr);
    ~Reportes();

private:
    Ui::Reportes *ui;
};

#endif // REPORTES_H
