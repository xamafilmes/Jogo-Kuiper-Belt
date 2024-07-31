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
        void texto_item_adquirido(Itens item_adquirido);
public slots:
        void add_asteroides();
        //vida da nave/jogador
        void imprimir_vida();
        // musica de fundo
        void tocar_denovo();
        // criar itens para a nave
        void criar_itens_para_nave(int asteroide_tamanho);;
        // tira o texto do item da tela
        void retira_texto_item();
    private:
        // parte gráfica
        QGraphicsScene *cena_de_jogo;
        QGraphicsView *foco_de_jogo;
        // temporização dos asteroides
        QTimer * tempo_asteroide;
        // Itens na tela
        Nave *nave;
        // placar
        int pontos;
        // imagem estática da contagem de misseis medios na tela          // <---- fazer
        QGraphicsPixmapItem * imag_estatica_missil_medio;                 // <---- fazer
        // imagem estática da contagem de misseis grandes na tela         // <---- fazer
        QGraphicsPixmapItem * imag_estatica_missil_grande;                // <---- fazer
        // display placar
        QGraphicsTextItem * placar_texto_obj;
        // display da vida
        QGraphicsTextItem * vida_texto_obj;
        // display das mensagens de itens
        QGraphicsTextItem * itens_texto_vida_obj;
        // display das mensagens de itens
        QGraphicsTextItem * itens_texto_missil_obj;
        // temporizador para tirar o texto da tela
        QTimer * tempo_texto_obg;
        //musica de fundo
        QMediaPlayer *musica_de_fundo = new QMediaPlayer;
};

#endif // JOGAR_H
