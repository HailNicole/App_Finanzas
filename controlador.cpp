#include "controlador.h"
#include "QDebug"

Controlador::Controlador(QObject *parent) : QObject(parent)
{
    this->m_registro = nullptr;
}

void Controlador::Cargar_Cat(QComboBox *cb)
{
    QFile cat_data("categorias.csv");
    if (cat_data.open(QFile::ReadOnly)) {
        QTextStream entrada(&cat_data);
        while(!entrada.atEnd()){
            QString linea = entrada.readLine();
            QStringList datos = linea.split(";");
            //Agregar al comboBox
            cb->addItem(datos.back());
        }
        cat_data.close();
    }
}

void Controlador::Cargar_Fam(QComboBox *cb2)
{
    QFile fam_data("familiares.csv");
    if (fam_data.open(QFile::ReadOnly)) {
        QTextStream entrada(&fam_data);
        while(!entrada.atEnd()){
            QString linea = entrada.readLine();
            QStringList datos = linea.split(";");
            //Agregar al comboBox
            cb2->addItem(datos.at(0) + " " + datos.at(1));
        }
        fam_data.close();
    }
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

void Controlador::Guardar_R()
{
    QFile dts("registro_datos.csv");
    QTextStream io;
    dts.open(QIODevice::WriteOnly | QIODevice::Append);
    io.setDevice(&dts);

    dts.close();
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
    if(!QFile("categorias.csv").exists()){
        QFile ct("registro_datos.csv");
        ct.open(QIODevice::ReadWrite | QIODevice::Text);
        ct.close();
    }
    if(!QFile("familiares.csv").exists()){
        QFile mf("familiares.csv");
        mf.open(QIODevice::ReadWrite | QIODevice::Text);
        mf.close();
    }
}

bool Controlador::validar_email(QString email)
{
    if(email.length() == 0){
        return false;
    }

      QRegExp pattern ("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
      return pattern.exactMatch(email);
}

bool Controlador::validar_texto(QString texto)
{
    if(texto.length() == 0){
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

bool Controlador::validar_campo_vacio(QString texto)
{
    if(texto.length() == 0){
        return false;
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
