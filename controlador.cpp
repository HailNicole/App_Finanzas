#include "controlador.h"
#include "QDebug"

Controlador::Controlador(QObject *parent) : QObject(parent)
{

}

void Controlador::Cargar_M()
{

}

void Controlador::Guardar_M()
{

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
