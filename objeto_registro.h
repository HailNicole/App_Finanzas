#ifndef OBJETO_REGISTRO_H
#define OBJETO_REGISTRO_H

#include <QObject>

class Objeto_registro : public QObject
{
    Q_OBJECT
public:
    explicit Objeto_registro(QObject *parent = nullptr);
    Objeto_registro(const QString &fecha, const QString &miembro, const QString &descripcion, const QString &tipo, const QString &categoria, const int valor);

    const QString &fecha() const;
    void setFecha(const QString &newFecha);

    const QString &miembro() const;
    void setMiembro(const QString &newMiembro);

    const QString &descripcion() const;
    void setDescripcion(const QString &newDescripcion);

    const QString &tipo() const;
    void setTipo(const QString &newTipo);

    const QString &categoria() const;
    void setCategoria(const QString &newCategoria);

    int valor() const;
    void setValor(int newValor);

private:
    QString m_fecha;
    QString m_miembro;
    QString m_descripcion;
    QString m_tipo;
    QString m_categoria;
    int m_valor;
};

#endif // OBJETO_REGISTRO_H
