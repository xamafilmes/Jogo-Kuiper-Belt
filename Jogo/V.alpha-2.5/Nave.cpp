#include "Nave.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

#include "Missil.h"
#include <math.h>

#define POS_ADICIONAL_ESQUERDA_NAVE -10
#define POS_ADICIONAL_DIREITA_NAVE 10


Nave::Nave(): numero_de_misseis(0) // construtor dos itens 'numero de misseis'
{
    vida_nave = 6;
    cursor = pos().x();
    tempo_movimento.start(1);

    //setTransformOriginPoint(boundingRect().x()/2,boundingRect().y()/2);
    connect(&tempo_movimento,SIGNAL(timeout()),this,SLOT(contagem_tempo()));
    connect(this, SIGNAL(envia_tempo(int)),this,SLOT(posMouse(int)));
    connect(&tempo_missil, SIGNAL(timeout()), this, SLOT(nave_reset_tiro()));
}

void Nave::keyPressEvent(QKeyEvent *evento)
{
    int nr_medios = (numero_de_misseis.ver_numero_misseis())[0];
    int nr_grandes = (numero_de_misseis.ver_numero_misseis())[1];

    if (evento->key() == Qt::Key_Right)
    {
        if (x() + boundingRect().width() + 3 >= scene()->width())
        {

        }
        else
        {
            //qDebug() << "direita";
            setPos(x()+POS_ADICIONAL_DIREITA_NAVE,y());
        }
    }
    if (evento->key() == Qt::Key_Left)
    {
        if (x() - 3 <= 0)
        {

        }
        else
        {
            //qDebug() << "esquerda";
            setPos(x()+POS_ADICIONAL_ESQUERDA_NAVE,y());
        }
    }
    if (evento->key() == Qt::Key_R)
    {
        //qDebug() << "rotação";
        setRotation(rotation()-1);
    }
    if(evento->key() == Qt::Key_Space)
    {
        if (flag_nave_pode_atirar)
        {
            Missil *missil = new Missil;
            missil->setPos(x() + (this->boundingRect().width()/2)-((missil->boundingRect()).width()),y()- (int)(missil->boundingRect().height()));
            scene()->addItem(missil);
            //qDebug() << "Míssil lançado";
            flag_nave_pode_atirar = false;
            tempo_missil.start((int)(TEMPO_MISSIL*1000));
        }
    }
    if ((evento->key() == Qt::Key_X) & (nr_medios>0)) {
        Missil *missil = new Missil(missil_medio);  // Passa o tipo desejado ao criar o míssil
        missil->setPos(x() + (this->boundingRect().width()/2) - (missil->boundingRect().width()/2), y() - (int)(missil->boundingRect().height()));
        numero_de_misseis.decrementar_misseis(0);
        emit atirou_missil_medio();
        scene()->addItem(missil);
        qDebug() << "Míssil médio lançado: " <<nr_medios;
    }
    if ((evento->key() == Qt::Key_Z) & (nr_grandes>0)) {
       Missil *missil = new Missil(missil_grande);  // Passa o tipo desejado ao criar o míssil
       missil->setPos(x() + (this->boundingRect().width()/2) - (missil->boundingRect().width()/2), y() - (int)(missil->boundingRect().height()));
       numero_de_misseis.decrementar_misseis(1);
       emit atirou_missil_grande();
       scene()->addItem(missil);
       qDebug() << "Míssil grande lançado: "<<nr_grandes;
       }
}

void Nave::nave_reset_tiro()
{
    flag_nave_pode_atirar = true;
    tempo_missil.stop();
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
  incrementar_vida(numero_de_misseis.adicionar_item_a_nave(item_ad));
  //qDebug()<<"Misseis Médios: "<< numero_de_misseis.ver_numero_misseis()[0]<< "Misseis Grandes: "<< numero_de_misseis.ver_numero_misseis()[1];
}

Itens * Nave::itens_da_nave()
{
    return &numero_de_misseis;
}

void Nave::posMouse(int ponto)
{
    //int direcao;
    double posicao;

    if(ponto < 0) //significa que veio da contagem de tempo
    {
        if (tempo >= 5*CONSTANTE_DE_TEMPO_MOVIMENTO_NAVE)
        {
            return;

        }
        else
        {
            tempo = tempo + 0.001;
            //qDebug()<<"tempo add";  // <- a fazer
        }
    }
    else
    {
        cursor = ponto - 50.0;
        tempo = 0.0;
    }
    if(pos().x() < cursor)
    {
        posicao = pos().x() + (cursor - pos().x())*(1 - exp(-(1/CONSTANTE_DE_TEMPO_MOVIMENTO_NAVE)*tempo));
        //qDebug()<<"cursor direita";  // <- a fazer
    }
    else
    {
        posicao = cursor + (pos().x() - cursor)*(exp(-(1/CONSTANTE_DE_TEMPO_MOVIMENTO_NAVE)*tempo));
        //qDebug()<<"cursor esquerda";  // <- a fazer
    }
    setPos(posicao, pos().y());
}

void Nave::contagem_tempo()
{
    emit envia_tempo(-1);
}
