#include "espaco.h"




Espaco::Espaco()
{

    // colocar o background como sendo uma imagem
    // precisa adicionar "QImage" header
    setBackgroundBrush(QBrush(QImage(":/icones/Fundo.png")));

    // seta a cena para comçar no 0,0 do foco e ter o mesmo tamanho que o foco
    setSceneRect(FOCO_DA_TELA_X,FOCO_DA_TELA_Y,LARGURA_TELA_X,ALTURA_TELA_Y);
}

void Espaco::mouseMoveEvent(QGraphicsSceneMouseEvent *evento)
{
    emit mover_mouse((int)(evento->scenePos().x()));
}

/*void Espaco::mover_mouse(int pos)
{
    qDebug()<<"WTF "<<pos;
}*/
