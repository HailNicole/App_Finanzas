#ifndef OBJETO_CATEGORIA_H
#define OBJETO_CATEGORIA_H

#include <QObject>

enum class Tipo_categoria
{
    Salud,
    Arriendo,
    Académico,
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

    void setTipo(Tipo_categoria newTipo);
    void setId(int newId);
    QString Tipo_String();
signals:

private:
    int m_id;
    Tipo_categoria m_tipo;

};

#endif // OBJETO_CATEGORIA_H
