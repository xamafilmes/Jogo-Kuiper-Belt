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

typedef struct
{
    QGraphicsTextItem * itens_texto_obj_strct;
    QTimer * tempo_texto_item_tela; // tempo do texto de item na tela
    int posicao_y;
    int quantidade;
    bool itens_em_display[]; //
}itens_em_display;

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
        void criar_itens_para_nave(int asteroide_tamanho);
        // tira o texto do item da tela
        void retira_texto_item();
    private:
        //parte gráfica
        QGraphicsScene *cena_de_jogo;
        QGraphicsView *foco_de_jogo;
        // temporização dos asteroides
        QTimer * tempo_asteroide;
        //Itens na tela
        Nave *nave;
        //placar
        int pontos;
        QGraphicsTextItem * placar_texto_obj;
        //display da vida
        QGraphicsTextItem * vida_texto_obj;
        //display das mensagens de itens                      // <------------------ não usar por enquanto
        QGraphicsTextItem * itens_texto_obj;                  // <------------------
        //musica de fundo
        QMediaPlayer *musica_de_fundo = new QMediaPlayer;
        //teste da estrutura criada
        itens_em_display *itens[]; // *itens[] = {*item1,*item2,...}
};

#endif // JOGAR_H
