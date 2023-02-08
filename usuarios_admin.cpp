#include "usuarios_admin.h"
#include "ui_usuarios_admin.h"
#include "QDebug"

Usuarios_admin::Usuarios_admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Usuarios_admin)
{
    ui->setupUi(this);
    setWindowTitle(tr("ADMINISTRADOR"));
    // Configurar la tabla
    ui->tblAdmin->setColumnCount(2);
    QStringList titulo;
    titulo << tr("Usuario") << tr("Contraseña");
    ui->tblAdmin->setHorizontalHeaderLabels(titulo);
    cargar_cuentas();
}

Usuarios_admin::~Usuarios_admin()
{
    delete ui;
}

void Usuarios_admin::cargar_cuentas()
{
    // Verificar si el archivo existe
   QFile archivo("registro_usuarios.csv");
    if (!archivo.exists())
        return;

    // cargar datos
    if (archivo.open(QFile::ReadOnly)) {
        QTextStream entrada(&archivo);
        int fila;
        while(!entrada.atEnd()){
            QString linea = entrada.readLine();
            QStringList datos = linea.split(";");
            fila = ui->tblAdmin->rowCount();
            ui->tblAdmin->insertRow(fila);
            ui->tblAdmin->setItem(fila, Usuario, new QTableWidgetItem(datos[Usuario]));
            ui->tblAdmin->setItem(fila, Contrasenia, new QTableWidgetItem(datos[Contrasenia]));
        }
        archivo.close();
    }
}

bool Usuarios_admin::getCradmin() const
{
    return cradmin;
}

void Usuarios_admin::setCradmin(bool newCradmin)
{
    cradmin = newCradmin;
}

void Usuarios_admin::on_btn_borrarUser_clicked()
{
    QList<QModelIndex>big = ui->tblAdmin->selectionModel()->selectedRows();
    if(big.isEmpty()){
        QMessageBox::information(this,tr("Seleccion"),tr("No se ha seleccionado ninguna fila"));
        return;
    }

    QMessageBox::StandardButton replied;
    replied = QMessageBox::question(this, tr("Confirmacion"), tr("Desea borrar esta cuenta permanentemente?"),
            QMessageBox::Yes | QMessageBox::Cancel);

    if(replied == QMessageBox::Yes){
        QList<int> list;
        QList<int>::iterator x;
        QList<QModelIndex>::iterator i;

        for (auto &&i : big){
            list.append(i.row());
        }

        for (auto &&x : list){
            ui->tblAdmin->removeRow(x);
        }
        int filas = ui->tblAdmin->rowCount();
            for (int i=0; i<filas; i++) {
                QTableWidgetItem *key = ui->tblAdmin->item(i, Usuario);
                QTableWidgetItem *value = ui->tblAdmin->item(i, Contrasenia);
                new_usuarios.insert(key->text(), value->text());
            }
        m_controlador->Guardar_U(new_usuarios);
    }else{
        return;
    }
}

void Usuarios_admin::on_btn_exit_clicked()
{
    setCradmin(false);
    this->close();
}

void Usuarios_admin::on_btn_elimadmin_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("Confirmacion"), tr("Desea borrar su cuenta de administrador?"),
            QMessageBox::Yes | QMessageBox::Cancel);
    if(reply == QMessageBox::Yes){
        Confirmacion confi(this);
        confi.exec();
        if(m_controlador->entrar(confi.getFlag())){
            QFile archivo("admin.csv");
                if (!archivo.exists())
                    return;
                archivo.remove();
                setCradmin(true);
                QMessageBox::information(this,tr("Borrar Cuenta Admin"),tr("Su cuenta ha sido borrada exitosamente"));
                this->close();
        }else{
            setCradmin(false);
            QMessageBox::information(this,tr("Borrar Cuenta Admin"),tr("No se pudo eliminar la cuenta"));
        }
    }
}
