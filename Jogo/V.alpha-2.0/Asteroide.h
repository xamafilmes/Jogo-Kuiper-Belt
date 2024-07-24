#ifndef ASTEROIDE_H
#define ASTEROIDE_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>

#include <QTimer>
#include <QDebug>

#include "Nave.h"

#include <QObject>

#include <stdlib.h>
#include <time.h>

enum tipo_asteroide
{
    asteroide_normal,
    asteroide_medio,
    asteroide_grande
};


class Asteroide: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Asteroide();
    void diminuir_vida_asteroide(int missil);
    int  ver_vida_asteroide();
    int  dar_dano_asteroide();
    tipo_asteroide obter_tamanho_asteroide();
    void explosao();
   public slots:
    void mover();
    void girar();
private:
    int vida_asteroide;
    int dano_asteroide;
    tipo_asteroide tamanho_asteroide;
    QMediaPlayer * som_explosao_asteroide;
};



#endif // ASTEROIDE_H
