#include "controlador.h"
#include "QDebug"

Controlador::Controlador(QObject *parent) : QObject(parent)
{

}

void Controlador::Cargar_U(QMap<QString, QString> usr)
{    
    QFile usuario("registro_usuarios.csv");
    QTextStream io;
    usuario.open(QIODevice::ReadOnly);
    io.setDevice(&usuario);

    while(!io.atEnd())
    {
        QString linea = io.readLine();
        QStringList datos = linea.split(";");
        usr.insert(datos[USUARIO],datos[CONTRASENIA]);
        qDebug()<<usr;
    }
    usuario.close();
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
