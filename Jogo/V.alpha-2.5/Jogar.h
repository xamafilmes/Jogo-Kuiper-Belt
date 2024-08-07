#ifndef JOGAR_H
#define JOGAR_H

#include "Nave.h"
#include "Asteroide.h"
#include "misseis_placar.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include <QDebug>
#include <QGraphicsScene>

//#include <QMediaPlayer> //retirado devido a necessidade

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
        //void tocar_denovo(); //retirado devido a necessidade
        // criar itens para a nave
        void criar_itens_para_nave(int asteroide_tamanho);;
        // tira o texto do item da tela
        void retira_texto_item();
        // missil medio
        void missil_medio_placar_decrementar();
        // missil grande
        void missil_grande_placar_decrementar();
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
        //placar de misseis
        Misseis_Placar placar_misseis;
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
        //QMediaPlayer *musica_de_fundo = new QMediaPlayer; //retirado devido a necessidade
};

#endif // JOGAR_H
