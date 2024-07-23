#include "Nave.h"
#include "Missil.h"

#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>

Nave::Nave()
{
    vida_nave = 6;
}


void Nave::keyPressEvent(QKeyEvent *evento)
{
    if (evento->key() == Qt::Key_Right)
    {
        if (x() + rect().width() + 3 >= scene()->width())
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
        missil->setPos(x() + (this->rect().width()/2)-(missil->rect().width()),y()- (int)(missil->rect().height()));
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
    emit vida_nave_mudou();
}

int Nave::ver_vida_nave()
{
    return vida_nave;
};


