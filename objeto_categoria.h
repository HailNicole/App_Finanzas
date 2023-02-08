#ifndef OBJETO_CATEGORIA_H
#define OBJETO_CATEGORIA_H

#include <QObject>

enum class Tipo_categoria
{
    Salud,
    Arriendo,
    Academico,
    Comida,
    Servicios_Basicos,
    Personales,
    Otros
};

class Objeto_categoria : public QObject
{
    Q_OBJECT
public:
    explicit Objeto_categoria(QObject *parent = nullptr);
    Objeto_categoria(const int &id, Tipo_categoria &tipo);

    const Tipo_categoria &tipo() const;
    const int &id() const;
    const QString &tipo2() const;

    void setTipo(Tipo_categoria newTipo);
    void setTipo2(QString newTipo2);
    void setId(int newId);
    QString Tipo_String();
signals:

private:
    int m_id;
    Tipo_categoria m_tipo;
    QString m_tipo2;
};

#endif // OBJETO_CATEGORIA_H
