#ifndef ACERCA_DE_H
#define ACERCA_DE_H

#include <QDialog>

namespace Ui {
class Acerca_de;
}

class Acerca_de : public QDialog
{
    Q_OBJECT

public:
    explicit Acerca_de(QWidget *parent = nullptr);
    ~Acerca_de();
    void setVersion(const QString &newVersion);

    int valor() const;

private:
    Ui::Acerca_de *ui;
    QString m_version;
    int m_valor;
};

#endif // ACERCA_DE_H
