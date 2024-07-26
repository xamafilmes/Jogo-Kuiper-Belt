#include "Nave.h"
#include <QDebug>
#include <QGraphicsScene>

#include "Missil.h"

Nave::Nave()
{
    vida_nave = 6;
    numero_de_misseis = new Itens(0);
}


void Nave::keyPressEvent(QKeyEvent *evento)
{
    if (evento->key() == Qt::Key_Right)
    {
        if (x() + boundingRect().width() + 3 >= scene()->width())
        {

        }
        else
        {
            qDebug() << "direita";
            setPos(x()+10,y());
        }
    }
    if (evento->key() == Qt::Key_Left)
    {
        if (x() - 3 <= 0)
        {

        }
        else
        {
            qDebug() << "esquerda";
            setPos(x()-10,y());
        }
    }
    if (evento->key() == Qt::Key_R)
    {
        qDebug() << "rotação";
        setRotation(rotation()-1);
    }
    if(evento->key() == Qt::Key_Space)
    {
        Missil *missil = new Missil;
        missil->setPos(x() + (this->boundingRect().width()/2)-((missil->boundingRect()).width()),y()- (int)(missil->boundingRect().height()));
        scene()->addItem(missil);
        qDebug() << "Míssil lançado";
    }
}

void Nave::decrementar_vida(int dano)
{
    vida_nave = vida_nave - dano;
    emit vida_nave_mudou();
}

void Nave::incrementar_vida(int vida_adicional)
{
    vida_nave = vida_nave + vida_adicional;
    if (vida_nave > 6)
    {
        vida_nave = 6;
    }
    emit vida_nave_mudou();
}

int Nave::ver_vida_nave()
{
    return vida_nave;
}

void Nave::adicionar_itens(Itens item_ad)
{
  incrementar_vida(numero_de_misseis->adicionar_item_a_nave(item_ad));
}
