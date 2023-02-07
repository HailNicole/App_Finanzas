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
    Objeto_registro(QString fecha, QString miembro, QString descripcion, QString tipo_string, QString categoria, double valor);

    const QString &fecha() const;
    void setFecha(const QString &newFecha);

    const QString &miembro() const;
    void setMiembro(const QString &newMiembro);

    const QString &descripcion() const;
    void setDescripcion(const QString &newDescripcion);

    const Tipo &tipo() const;
    void setTipo(Tipo &newTipo);

    const QString &tipo_string() const;
    void setTipo_string(const QString &newTipo_string);

    const QString &categoria() const;
    void setCategoria(const QString &newCategoria);

    double valor() const;
    void setValor(double newValor);

    QString tipo2string(Tipo tp);

private:
    QString m_fecha;
    QString m_miembro;
    QString m_descripcion;
    QString m_tipo_string;
    Tipo m_tipo;
    QString m_categoria;
    double m_valor;
};

#endif // OBJETO_REGISTRO_H
