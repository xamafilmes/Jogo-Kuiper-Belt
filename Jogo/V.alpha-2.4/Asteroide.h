#ifndef ASTEROIDE_H
#define ASTEROIDE_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
//#include <QMediaPlayer> //retirado devido a necessidade

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
    int obter_semente_criacao_asteroide();
   public slots:
    void mover();
    void girar();
private:
    int semente_criacao_asteroide;
    int vida_asteroide;
    int dano_asteroide;
    tipo_asteroide tamanho_asteroide;
    //QMediaPlayer * som_explosao_asteroide; //retirado devido a necessidade
    QTimer rotacao_as_e_translacao;
signals:
    int criar_item_de_asteroide(int nr_randomico);
};



#endif // ASTEROIDE_H
