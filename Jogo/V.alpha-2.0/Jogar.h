#ifndef JOGAR_H
#define JOGAR_H

#include "Nave.h"
#include "Asteroide.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include <QDebug>
#include <QGraphicsScene>

#include <QMediaPlayer>

#include <QImage>

class Jogar: public QObject
{
    Q_OBJECT
    public:
        Jogar();
        bool jogar();
        //placar
        void adicionar_placar(int potos_extra);
        void imprimir_placar();
public slots:
        void add_inimigos();
        //vida da nave/jogador
        void imprimir_vida();
        // musica de fundo
        void tocar_denovo();
    private:
        //parte gráfica
        QGraphicsScene *cena_de_jogo;
        QGraphicsView *foco_de_jogo;
        //Itens na tela
        Nave *nave;
        // temporização de inimigos
        QTimer * tempo_inimigo;
        //placar
        int pontos;
        QGraphicsTextItem * placar_obj;
        //display da vida
        QGraphicsTextItem * vida_obj;
        //musica de fundo
        QMediaPlayer *musica_de_fundo = new QMediaPlayer;
};

#endif // JOGAR_H
