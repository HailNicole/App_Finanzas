#include "objeto_categoria.h"
#include "QDebug"

Objeto_categoria::Objeto_categoria(QObject *parent)
    : QObject{parent}
{

}

Objeto_categoria::Objeto_categoria(const int &id, Tipo_categoria &tipo):
    m_id(id),
    m_tipo(tipo)
{}

const Tipo_categoria &Objeto_categoria::tipo() const
{
    return m_tipo;
}

const int &Objeto_categoria::id() const
{
    return m_id;
}

const QString &Objeto_categoria::tipo2() const
{
    return m_tipo2;
}

void Objeto_categoria::setTipo(Tipo_categoria newTipo)
{
    m_tipo = newTipo;
}

void Objeto_categoria::setTipo2(QString newTipo2)
{
    m_tipo2 = newTipo2;
}

void Objeto_categoria::setId(int newId)
{
    m_id = newId;
}

QString Objeto_categoria::Tipo_String()
{
    switch (m_tipo) {
    case Tipo_categoria::Salud:
        return tr("Salud");
        break;
    case Tipo_categoria::Arriendo:
        return tr("Arriendo");
        break;
    case Tipo_categoria::Académico:
        return tr("Académico");
        break;
    case Tipo_categoria::Comida:
        return tr("Comida");
        break;
    case Tipo_categoria::Servicios_Basicos:
        return tr("Servicios Básicos");
        break;
    case Tipo_categoria::Personales:
        return tr("Personales");
        break;
    case Tipo_categoria::Otros:
        return tipo2();
        break;
    default:
        return "";
    }
}
