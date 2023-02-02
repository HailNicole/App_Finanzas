#ifndef PERSONA_MIEMBRO_H
#define PERSONA_MIEMBRO_H

#include <QObject>

class Persona_miembro : public QObject
{
    Q_OBJECT
public:
    explicit Persona_miembro(QObject *parent = nullptr);
    Persona_miembro(const QString &nombre, const QString &apellido, const QString &rol);

    const QString &nombre() const;
    const QString &apellido() const;
    const QString &rol() const;

signals:

private:
    QString m_nombre;
    QString m_apellido;
    QString m_rol;
};

#endif // PERSONA_MIEMBRO_H
