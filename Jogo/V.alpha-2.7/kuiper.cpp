#include "kuiper.h"
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

#include "config.h"



Kuiper::Kuiper(QObject *parent)
    : QGraphicsScene{parent}
{
    // colocar o background como sendo uma imagem
    // precisa adicionar "QImage" header
    setBackgroundBrush(QBrush(QImage(":/icones/FundoInicio.png")));

    // seta a cena para comçar no 0,0 do foco e ter o mesmo tamanho que o foco
    setSceneRect(FOCO_DA_TELA_X,FOCO_DA_TELA_Y,LARGURA_TELA_X,ALTURA_TELA_Y);
}



