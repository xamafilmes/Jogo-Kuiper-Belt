#include "Nave.h"
#include <QDebug>
#include <QGraphicsScene>

#include "Missil.h"

#define POS_ADICIONAL_ESQUERDA_NAVE -10
#define POS_ADICIONAL_DIREITA_NAVE 10

//------------------------------------------------------------------------------------
// Quando implementar a troca de misseis ou misseis atirados de teclas diferentes,
// emitir os sinais atirou_missil_grande() e atirou_missil_medio();
// atraves de 'emit ......;'
//------------------------------------------------------------------------------------

Nave::Nave(): numero_de_misseis(0) // construtor dos itens 'numero de misseis'
{
    vida_nave = 6;
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
        Missil *missil = new Missil;
        missil->setPos(x() + (this->boundingRect().width()/2)-((missil->boundingRect()).width()),y()- (int)(missil->boundingRect().height()));
        scene()->addItem(missil);
        //qDebug() << "Míssil lançado";
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
  qDebug()<<"Misseis Médios: "<< numero_de_misseis.ver_numero_misseis()[0]<< "Misseis Grandes: "<< numero_de_misseis.ver_numero_misseis()[1];
}

Itens * Nave::itens_da_nave()
{
    return &numero_de_misseis;
}
