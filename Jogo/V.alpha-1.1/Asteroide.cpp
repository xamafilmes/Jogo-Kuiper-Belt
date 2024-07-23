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

    som_explosao_asteroide = new QMediaPlayer;
    som_explosao_asteroide->setMedia(QUrl("qrc:/sons/Asteroide_Explosao.wav"));

    setPos(nr_randomico,0);

    QTimer * rotacao_as_e_translacao = new QTimer();

    connect(rotacao_as_e_translacao, SIGNAL(timeout()),this, SLOT(mover()));
    connect(rotacao_as_e_translacao, SIGNAL(timeout()),this, SLOT(girar()));
    rotacao_as_e_translacao->start(50);

}

void Asteroide::explosao()
{
    som_explosao_asteroide->play();
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

tipo_asteroide Asteroide::obter_tamanho_asteroide()
{
    return tamanho_asteroide;
}

void Asteroide::mover()
{
    setPos(x(),y()+5);

    //checar por colisão
    QList<QGraphicsItem *> itens_colididos = collidingItems();
    for(int i = 0,n = itens_colididos.size();i<n;i++)
        {
            if(typeid(*(itens_colididos[i])) == typeid(Nave))
            {

                //tipo_asteroide
                // pequeno = 0
                // medio = 1
                // grande  = 2

                //dano: pequeno = 2
                //dano: medio   = 4
                //dano: grande  = 6

                //ou seja
                // dn = 2 + 2*( (int) tipo_asteroide)

                int dn = 2 + 2*(int)(obter_tamanho_asteroide());
                qDebug() << "Dano -"<< dn<<"?";
                ((Nave *)(itens_colididos[i]))->decrementar_vida(dn);

                //asteroide explode
                explosao();

                //tira o asteroide da cena e paga ele depois
                scene()->removeItem(this);
                delete this;
                return ;
                //morte do jogador

                //if (((Nave *)itens_colididos[i])->ver_vida_nave() - dn <= 0)
                //{
                    //remove o jogador e o Asteroide
                //    scene()->removeItem(itens_colididos[i]);

                //    delete itens_colididos[i];
                //    delete this;
                //}
            }
        }

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
