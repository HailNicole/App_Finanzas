#ifndef OBJETO_REGISTRO_H
#define OBJETO_REGISTRO_H

#include <QObject>

enum class Tipo
{
    Ingreso,
    Egreso
};

class Objeto_registro : public QObject
{
    Q_OBJECT
public:
    explicit Objeto_registro(QObject *parent = nullptr);
    Objeto_registro(const QString &fecha, const QString &miembro, const QString &descripcion, Tipo &tipo, const QString &categoria, double valor);

    const QString &fecha() const;
    void setFecha(const QString &newFecha);

    const QString &miembro() const;
    void setMiembro(const QString &newMiembro);

    const QString &descripcion() const;
    void setDescripcion(const QString &newDescripcion);

    const Tipo &tipo() const;
    void setTipo(Tipo &newTipo);

    const QString &categoria() const;
    void setCategoria(const QString &newCategoria);

    double valor() const;
    void setValor(double newValor);

    QString tipo2string();

private:
    QString m_fecha;
    QString m_miembro;
    QString m_descripcion;
    Tipo m_tipo;
    QString m_categoria;
    double m_valor;
};

#endif // OBJETO_REGISTRO_H
