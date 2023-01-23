#include "login.h"
#include "ui_login.h"

#include "QDebug"

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
    cargarUsuarios();
}

login::~login()
{
    delete ui;
}

void login::on_btn_Registrar_clicked()
{

    Registrar_usuario *reg = new Registrar_usuario(this);
    reg->setWindowTitle("Registrar Usuario");
    int res = reg->exec();
    if (res == QDialog::Rejected){
        return;
    }
    if(!reg->getUsuarios().isEmpty()){
        QMapIterator<QString, QString> i(reg->getUsuarios());
            i.next();
            usuarios2.insert(i.key(), i.value());
    }

    QFile archivo(ARCHIVO);
    if (archivo.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream salida(&archivo);
        QMapIterator<QString, QString> i(usuarios2);
        while (i.hasNext())
        {
            i.next();
            salida << i.key() << ";" << i.value() << "\n";
        }
        archivo.close();
    }else{
        QMessageBox::critical(this,"Guardar Usuario", "No se puede escribir sobre " + ARCHIVO);
    }
}

bool login::on_btn_Ingresar_clicked()
{
    QMapIterator<QString, QString> i(usuarios2);
    while (i.hasNext())
    {
        i.next();
        if(i.key() == ui->in_Usuario->text() && (i.value()) == ui->in_Contra->text())
        {
           return true;
        }
    }
    QMessageBox::warning(this, tr("Administrador"), tr("Usuario y/o Contraseña Incorrecta"), tr("Aceptar"));
    return false;
}

void login::cargarUsuarios()
{
    // Verificar si el archivo existe
   QFile archivo(ARCHIVO);
    if (!archivo.exists())
        return;

    // cargar datos
    if (archivo.open(QFile::ReadOnly)) {
        QTextStream entrada(&archivo);
        while(!entrada.atEnd()){
            QString linea = entrada.readLine();
            QStringList datos = linea.split(";");
            //qDebug()<<datos;
            usuarios2.insert(datos[USUARIO],datos[CONTRASENIA]);
        }
        archivo.close();
    }
}
