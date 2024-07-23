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
    //*************Foi feito na implementação da Nave 'KeyPressEvent()'**************//

    //exemplo com missil fraco
    missil_t = missil_normal;

    //criar um media de som
    som_missil = new QMediaPlayer;

    //coloca o som do missil para tocar
    switch (missil_t) {
    case missil_normal:
        som_missil->setMedia(QUrl("qrc:/sons/Missil_1.mp3"));
        som_missil->play();
        break;
    case missil_medio:
        som_missil->setMedia(QUrl("qrc:/sons/Missil_2.mp3"));
        som_missil->play();
        break;
    case missil_grande:
        som_missil->setMedia(QUrl("qrc:/sons/Missil_3.mp3"));
        som_missil->play();
        break;
    }
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
                //aumenta o placar

                //tipo_asteroide
                // pequeno = 0
                //medio = 1
                //grande  = 2

                //ponos: pequeno = 2
                //ponos: medio   = 4
                //ponos: grande  = 6

                //ou seja
                // pnt = 2 + 2*( (int) tipo_asteroide)

                int pnt = 2 + 2*(int)((Asteroide *)itens_colididos[i])->obter_tamanho_asteroide();
                qDebug() << "plcar +"<< pnt<<"?";
                jogo->adicionar_placar(pnt);

                //asteroide explode
                ((Asteroide *)itens_colididos[i])->explosao();

                //remove os dois
                scene()->removeItem(itens_colididos[i]);
                scene()->removeItem(this);
                delete itens_colididos[i];
                delete this;
            }
        }
    }
}
