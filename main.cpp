#include "principal.h"
#include "registrar_usuario.h"
#include "acceso.h"
#include "registro.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Usuarios_admin w;
    w.show();
    /*
    if(w.acceso()){
        w.show();
    }else{
        return -1;
    }*/
    return a.exec();
}
