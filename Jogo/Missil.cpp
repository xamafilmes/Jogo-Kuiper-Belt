#include "Missil.h"
#include "Asteroide.h"

Missil::Missil()
{
    // Desenha o retângulo
    setRect(0,0,10,60);

    //temporizador que vai de um número a zero e faz o que tiver que fazer
    QTimer * temporizador = new QTimer();

    // estrutura principal do slot criado 'mover()'
    connect(temporizador, SIGNAL(timeout()), this,SLOT(mover()));
    temporizador->start(50);

    // colocar o missil na frente da nave
}

void Missil::mover()
{
    if (pos().y() < - rect().height())
    {
        scene()->removeItem(this);
        delete this;
        qDebug() << "Míssil deletado";
    }
    else
    {
        setPos(x(),y()-10);
        //checar por colisão
        QList<QGraphicsItem *> itens_colididos = collidingItems();
        for(int i = 0,n = itens_colididos.size();i<n;i++)
        {
            if(typeid(*(itens_colididos[i])) == typeid(Asteroide))
            {
                //remove os dois
                scene()->removeItem(itens_colididos[i]);
                scene()->removeItem(this);
                delete itens_colididos[i];
                delete this;

                //aumenta o placar
                qDebug() << "plcar +1?";
                jogo->adicionar_placar();
            }
        }
    }
}
