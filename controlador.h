#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <QObject>
#include <QMessageBox>
#include <QDir>
#include <QTextStream>
#include <QMap>

class Controlador : public QObject
{
    Q_OBJECT
private:
    const QString ARCHIVO = "registro_usuarios.csv";
    enum Columna
    {
        USUARIO, CONTRASENIA
    };

public:
    explicit Controlador(QObject *parent = nullptr);
    void Cargar_U(QMap<QString, QString> usr);
    void Guardar_U(QMap<QString, QString> usr);
    void crear_archivo();
    bool validar_email(QString email);
    bool validar_texto(QString texto);
    bool entrar(bool validar);
signals:

};

#endif // CONTROLADOR_H


