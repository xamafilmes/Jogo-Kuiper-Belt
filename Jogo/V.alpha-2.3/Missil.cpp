#include "Missil.h"
#include "Asteroide.h"

Missil::Missil()
{
    //temporizador que vai de um número a zero e faz o que tiver que fazer
    temporizador = QTimer();

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
        // Desenha o Tiro normal
        setPixmap(QPixmap(":/icones/Tiro.png"));
        //som_missil->setMedia(QUrl("qrc:/sons/Missil_1.mp3")); //retirado devido a necessidade
        //som_missil->play(); //retirado devido a necessidade
        break;
    case missil_medio:
        // Desenha o Missil
        setPixmap(QPixmap(":/icones/Missil.png"));
        //som_missil->setMedia(QUrl("qrc:/sons/Missil_2.mp3"));  //retirado devido a necessidade
        //som_missil->play();  //retirado devido a necessidade
        break;
    case missil_grande:
        // Desenha o Missil
        setPixmap(QPixmap(":/icones/Missil.png"));
        //som_missil->setMedia(QUrl("qrc:/sons/Missil_3.mp3"));   //retirado devido a necessidade
        //som_missil->play();   //retirado devido a necessidade
        break;
    }
}

void Missil::mover()
{
    if (pos().y() < - boundingRect().height())
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

                Asteroide * asteroide = (Asteroide *)(itens_colididos[i]);

                //diminuir a vida do asteroide

                asteroide->diminuir_vida_asteroide((2+ (int)(this->missil_t)));

                if (asteroide->ver_vida_asteroide()<=0)
                {
                    tipo_asteroide tipo_asteroide = (asteroide)->obter_tamanho_asteroide();
                    int pnt = 2 + 2*(int)tipo_asteroide;
                    qDebug() << "plcar +"<< pnt<<"?";
                    jogo->adicionar_placar(pnt);

                    // quando o asteroide medio ou grande é destruido uma mensagem é enviada para o 'Jogo' que então cria o item
                    // e o adiciona à nave

                    if (((int)tipo_asteroide) > 0)
                    {
                        // emite um sinal para o jogo criar um item, pasando a semente que criou o asteroide
                        // é possivel saber o tamanho dele e utilizar esse numero randomico para criar aprobanilidade
                        // do asteroide dar 'itens'
                        emit (asteroide)->criar_item_de_asteroide((int)(asteroide)->obter_semente_criacao_asteroide());
                    }

                    //asteroide explode
                    ((Asteroide *)itens_colididos[i])->explosao();

                    //remove o missil, o asteroide foi deletado pela 'explosao()'
                    scene()->removeItem(this);
                    delete this;
                }
                else
                {
                    scene()->removeItem(this);
                    delete this;
                }

            }
        }
    }
}
