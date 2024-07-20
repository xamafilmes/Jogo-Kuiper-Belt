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


class Jogar: public QObject
{
    Q_OBJECT
    public:
        Jogar();
        bool jogar();
        void adicionar_placar();
        void imprimir_placar();
    public slots:
        void add_inimigos();
    private:
        QGraphicsScene *cena_de_jogo;
        QGraphicsView *foco_de_jogo;
        Nave *nave;
        QTimer * tempo_inimigo;
        int pontos;
        QGraphicsTextItem * placar_obj;
};

#endif // JOGAR_H
