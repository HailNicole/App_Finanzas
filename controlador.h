#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <QObject>
#include <QMessageBox>
#include <QDir>
#include <QTextStream>

class Controlador : public QObject
{
    Q_OBJECT
private:
    const QString ARCHIVO1 = "registro_usuarios.csv";
public:
    explicit Controlador(QObject *parent = nullptr);
    void Cargar_M();
    void Guardar_M();

    bool validar_email(QString email);
    bool validar_texto(QString texto);
    bool entrar(bool validar);
signals:

};

#endif // CONTROLADOR_H


