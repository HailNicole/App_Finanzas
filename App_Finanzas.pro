QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    acceso.cpp \
    acerca_de.cpp \
    admin.cpp \
    agregar_categorias.cpp \
    agregar_miembros.cpp \
    categorias.cpp \
    controlador.cpp \
    main.cpp \
    miembros.cpp \
    objeto_categoria.cpp \
    objeto_registro.cpp \
    persona_miembro.cpp \
    principal.cpp \
    registrar_usuario.cpp \
    registro.cpp \
    reportes.cpp \
    usuarios_admin.cpp

HEADERS += \
    acceso.h \
    acerca_de.h \
    admin.h \
    agregar_categorias.h \
    agregar_miembros.h \
    categorias.h \
    controlador.h \
    miembros.h \
    objeto_categoria.h \
    objeto_registro.h \
    persona_miembro.h \
    principal.h \
    registrar_usuario.h \
    registro.h \
    reportes.h \
    usuarios_admin.h

FORMS += \
    acceso.ui \
    acerca_de.ui \
    admin.ui \
    agregar_categorias.ui \
    agregar_miembros.ui \
    categorias.ui \
    miembros.ui \
    principal.ui \
    registrar_usuario.ui \
    registro.ui \
    reportes.ui \
    usuarios_admin.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    recursos.qrc

DISTFILES += \
    recursos/safe home.png
