#include "persona_miembro.h"

Persona_miembro::Persona_miembro(QObject *parent)
    : QObject{parent}
{

}

Persona_miembro::Persona_miembro(const QString &nombre, const QString &apellido, const QString &rol) :
    m_nombre(nombre),
    m_apellido(apellido),
    m_rol(rol)
{}

const QString &Persona_miembro::nombre() const
{
    return m_nombre;
}

const QString &Persona_miembro::apellido() const
{
    return m_apellido;
}

const QString &Persona_miembro::rol() const
{
    return m_rol;
}
