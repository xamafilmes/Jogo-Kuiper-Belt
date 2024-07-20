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
        //while(1)
      //  {

         qDebug() << "rotação";
        setRotation(rotation()-1);
      //  }
    }
    if(evento->key() == Qt::Key_Space)
    {

        Missil *missil = new Missil;
        missil->setPos(x(),y()-60);
        scene()->addItem(missil);
        qDebug() << "Míssil lançado";
    }


};
