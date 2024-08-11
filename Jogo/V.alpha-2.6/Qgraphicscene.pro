QT       += core gui \
       #     multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Asteroide.cpp\
    Itens.cpp \
    TelaInicio.cpp \
    Jogar.cpp \
    main.cpp \
    Missil.cpp \
    Nave.cpp \
    misseis_placar.cpp \
    space.cpp

HEADERS += \
    Asteroide.h \
    Itens.h \
    TelaInicio.h \
    Jogar.h \
    Missil.h \
    Nave.h \
    config.h \
    misseis_placar.h \
    space.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Recursos_de_midia.qrc
