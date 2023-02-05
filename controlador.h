#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <QObject>
#include <QMessageBox>
#include <QDir>
#include <QTextStream>
#include <QMap>
#include "objeto_registro.h"
#include "qcombobox.h"

class Controlador : public QObject
{
    Q_OBJECT
private:
    const QString ARCHIVO = "registro_usuarios.csv";
    Objeto_registro *m_registro;
public:
    explicit Controlador(QObject *parent = nullptr);
    void Cargar_Cat(QComboBox *cb);
    void Cargar_Fam(QComboBox *cb2);
    void Guardar_U(QMap<QString, QString> usr);
    void Guardar_Admin(QMap<QString, QString> usr);
    void Guardar_R();
    void crear_archivo();
    bool validar_email(QString email);
    bool validar_texto(QString texto);
    bool validar_campo_vacio(QString texto);
    bool entrar(bool validar);

    void setDatos(QString fecha, QString miembro, QString descripcion, Tipo tipo, QString categoria, double valor);
signals:

};

#endif // CONTROLADOR_H


