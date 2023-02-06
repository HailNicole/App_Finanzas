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

QString Controlador::Cargar_Admin(QString *dat)
{
    QFile archivo(tr("admin.csv"));
        if (!archivo.exists())
            return nullptr;

        // cargar datos
        if (archivo.open(QFile::ReadOnly)) {
            QTextStream entrada(&archivo);
            while(!entrada.atEnd()){
                QString linea = entrada.readLine();
                QStringList datos = linea.split(";");
                *dat = datos.at(1);
            }
            archivo.close();

        }
        return *dat;
}

void Controlador::Guardar_U(QMap<QString, QString> usr)
{
    QFile usuario("registro_usuarios.csv");
    QTextStream io;
    usuario.open(QIODevice::WriteOnly | QIODevice::Truncate);
    io.setDevice(&usuario);
    QMapIterator<QString, QString> i(usr);
    while (i.hasNext())
    {
        i.next();
        io<< i.key() << ";" << i.value() << "\n";
    }
    usuario.close();
}

void Controlador::Guardar_Admin(QMap<QString, QString> usr)
{
    QFile admin("admin.csv");
    QTextStream io;
    admin.open(QIODevice::WriteOnly | QIODevice::Append);
    io.setDevice(&admin);
    QMapIterator<QString, QString> i(usr);
    while (i.hasNext())
    {
        i.next();
        io<< i.key() << ";" << i.value() << "\n";
    }
    admin.close();
}

void Controlador::Guardar_R(QList<Objeto_registro*> reg)
{
    QFile dts("registro_datos.csv");
    QTextStream io;
    dts.open(QIODevice::WriteOnly | QIODevice::Truncate);
    io.setDevice(&dts);
    int x=0;
    QListIterator<Objeto_registro*> i(reg);
    while(i.hasNext()){
        m_registro=reg.at(x);
        io<< m_registro->fecha() << ";" << m_registro->miembro() << ";";
        io<< m_registro->descripcion() << ";" << m_registro->categoria() << ";";
        io<< m_registro->tipo2string() << ";" << m_registro->valor() << "\n";
        i.next();
        x++;
    }
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
    if(!QFile("admin.csv").exists()){
        QFile admin("familiares.csv");
        admin.open(QIODevice::ReadWrite | QIODevice::Text);
        admin.close();
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

QString Controlador::tipoString()
{
    return m_registro->tipo2string();
}

Objeto_registro *Controlador::registro() const
{
    return m_registro;
}
