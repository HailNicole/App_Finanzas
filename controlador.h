#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <QObject>
#include <QMessageBox>
#include <QDir>
#include <QTextStream>
#include <QMap>
#include "objeto_registro.h"

class Controlador : public QObject
{
    Q_OBJECT
private:
    const QString ARCHIVO = "registro_usuarios.csv";
    Objeto_registro *m_registro;
public:
    explicit Controlador(QObject *parent = nullptr);
    void Cargar_U(QMap<QString, QString> usr);
    void Guardar_U(QMap<QString, QString> usr);
    void Guardar_R(QMap<QString, QString> usr);
    void crear_archivo();
    bool validar_email(QString email);
    bool validar_texto(QString texto);
    bool entrar(bool validar);

    void setDatos(QString fecha, QString miembro, QString descripcion, Tipo tipo, QString categoria, double valor);
signals:

};

#endif // CONTROLADOR_H


