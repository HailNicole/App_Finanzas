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
    titulo << "User" << "Password";
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
   QFile archivo(tr("registro_usuarios.csv"));
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

void Usuarios_admin::crear_dialog()
{
    QDialog *dialog = new QDialog(this);
    dialog->setWindowModality(Qt::WindowModality::NonModal);
    dialog->setMinimumWidth(500);
    dialog->setMaximumHeight(400);

    QLabel *label1 = new QLabel();
    label1->setText(tr("Confirme su contraseña"));
    label1->setGeometry(10, 10, 200,50);
    label1->setParent(dialog);

    QLineEdit *line = new QLineEdit();
    line->setToolTip("Confirme su contraseña");
    line->setGeometry(200, 18, 200,30);
    line->setParent(dialog);
    line->show();

    QPushButton *button = new QPushButton();
    button->setText("Confirmar");
    button->setParent(dialog);
    button->setGeometry(150, 65, 100,30);
    button->show();

    dialog->show();
}

void Usuarios_admin::on_btn_borrarUser_clicked()
{
    QList<QModelIndex>big = ui->tblAdmin->selectionModel()->selectedRows();
    if(big.isEmpty()){
        QMessageBox::information(this,tr("Seleccion"),tr("No se ha seleccionado ninguna fila"));
        return;
    }

    QList<int> list;
    QList<int>::iterator x;
    QList<QModelIndex>::iterator i;

    for (auto &&i : big){
        list.append(i.row());
    }

    for (auto &&x : list){
        ui->tblAdmin->removeRow(x);
    }
}


void Usuarios_admin::on_btn_exit_clicked()
{
    this->close();
}


void Usuarios_admin::on_btn_elimadmin_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmacion", "Desea borrar su cuenta de administrador?",
            QMessageBox::YesToAll | QMessageBox::Cancel);
    if(reply == QMessageBox::YesToAll){
        crear_dialog();
        /*QFile adm(tr("admin.csv"));
         if (!adm.exists())
             return;
         adm.remove();
         QMessageBox::information(this,tr("Borrar Cuenta Admin"),tr("Su cuenta ha sido borrada exitosamente"));*/
    }
}

