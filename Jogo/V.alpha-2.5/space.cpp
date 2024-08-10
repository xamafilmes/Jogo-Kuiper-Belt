#include "space.h"
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

#include "config.h"



Space::Space(QObject *parent)
    : QGraphicsScene{parent}
{
    // colocar o background como sendo uma imagem
    // precisa adicionar "QImage" header
    setBackgroundBrush(QBrush(QImage(":/icones/Fundo.png")));

    // seta a cena para comçar no 0,0 do foco e ter o mesmo tamanho que o foco
    setSceneRect(FOCO_DA_TELA_X,FOCO_DA_TELA_Y,LARGURA_TELA_X,ALTURA_TELA_Y);
}


// evento capturado em relação a cena de jogo
void Space::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    //qDebug() << "Mouse moved! " << event->scenePos().x() << "," << event->scenePos().y();
    emit this->mouse_moveu((int)(event->scenePos().x()));//
}

