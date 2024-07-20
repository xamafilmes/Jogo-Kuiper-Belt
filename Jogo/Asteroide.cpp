#include "Asteroide.h"

#define TAMANHO_X_TELA 800

Asteroide::Asteroide()
{
    // colocar numa posição randomica
    srand(clock()<<10);
    int nr_randomico = (rand() % (TAMANHO_X_TELA - 120)) + 60 ; //deixa o asteroide dentro do tamanho da tela menos o tamanho do retângulo'(scene()->width())'

    // escolhendo o tipo de asteroide

    tamanho_asteroide = (tipo_asteroide) (nr_randomico % 3);

    switch (tamanho_asteroide)
    {
    case asteroide_normal:
        vida_asteroide = 2;
        dano_asteroide = 2;
        setRect(0,0,40,40);
        setTransformOriginPoint(20,20);
    break;
    case asteroide_medio:
        vida_asteroide = 4;
        dano_asteroide = 4;
        setRect(0,0,70,70);
        setTransformOriginPoint(25,25);
    break;
    case asteroide_grande:
        vida_asteroide = 6;
        dano_asteroide = 6;
        setRect(0,0,100,100);
        setTransformOriginPoint(20,20);
    break;
    }

    setPos(nr_randomico,0);

    QTimer * rotacao_as_e_translacao = new QTimer();

    connect(rotacao_as_e_translacao, SIGNAL(timeout()),this, SLOT(mover()));
    connect(rotacao_as_e_translacao, SIGNAL(timeout()),this, SLOT(girar()));
    rotacao_as_e_translacao->start(50);

}

void Asteroide::diminuir_vida_asteroide(int missil)
{
    vida_asteroide = vida_asteroide - missil;
}

int Asteroide::ver_vida_asteroide()
{
    return vida_asteroide;
}

int Asteroide::dar_dano_asteroide()
{
    return dano_asteroide;
}

void Asteroide::mover()
{
    setPos(x(),y()+5);
    if(y() > scene()->height()+rect().height()*4)
    {
        delete this;
        qDebug() << "Asteroide Fora de tela destruido";
    }
}

void Asteroide::girar()
{
    setRotation(rotation()-2);
}
