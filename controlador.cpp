#include "controlador.h"
#include "QDebug"

Controlador::Controlador(QObject *parent) : QObject(parent)
{
    this->m_registro = nullptr;
}

void Controlador::Guardar_U(QMap<QString, QString> usr)
{
    QFile usuario("registro_usuarios.csv");
    QTextStream io;
    usuario.open(QIODevice::WriteOnly | QIODevice::Append);
    io.setDevice(&usuario);
    QMapIterator<QString, QString> i(usr);
    while (i.hasNext())
    {
        i.next();
        io<< i.key() << ";" << i.value() << "\n";
    }
    usuario.close();
}

void Controlador::crear_archivo()
{
    if(!QFile("registro_usuarios.csv").exists())
    {
        QFile usr("registro_usuarios.csv");
        usr.open(QIODevice::ReadWrite | QIODevice::Text);
        usr.close();
    }
    if(!QFile("registro_datos.csv").exists()){
        QFile data("registro_datos.csv");
        data.open(QIODevice::ReadWrite | QIODevice::Text);
        data.close();
    }
}

bool Controlador::validar_email(QString email)
{
    if(email.isEmpty()){
        return false;
    }

      QRegExp pattern ("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
      return pattern.exactMatch(email);
}

bool Controlador::validar_texto(QString texto)
{
    if(texto.isEmpty()){
        return false;
    }
    int tam = texto.length();
    QChar aux[tam];

    for(int i = 0; i < tam; i++)
    {
        aux[i] = texto[i];
    }

    for(int i = 0; i < tam; i++)
    {
        if(aux[i].isDigit()==1){
            return false;
            break;
        }
    }
    return true;
}

bool Controlador::entrar(bool validar)
{
    if(!validar){
        return false;
    }
    return true;
}

void Controlador::setDatos(QString fecha, QString miembro, QString descripcion, Tipo tipo, QString categoria, double valor)
{
    this->m_registro = new Objeto_registro(fecha, miembro, descripcion, tipo, categoria, valor);
}

