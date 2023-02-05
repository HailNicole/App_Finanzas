#ifndef REPORTES_H
#define REPORTES_H

#include <QWidget>

namespace Ui {
class Reportes;
}

class Reportes : public QWidget
{
    Q_OBJECT

public:
    explicit Reportes(QWidget *parent = nullptr);
    ~Reportes();

private:
    Ui::Reportes *ui;
};

#endif // REPORTES_H
