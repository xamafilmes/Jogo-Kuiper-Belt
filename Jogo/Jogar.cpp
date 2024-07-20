#include "Jogar.h"
#include <QGraphicsScene>
#include <QFont>
#include <QGraphicsTextItem>

Jogar::Jogar()
{
    // cria uma cena

    cena_de_jogo = new QGraphicsScene;

    // adicionar um vizualização de cena

    foco_de_jogo = new QGraphicsView;
    foco_de_jogo->setScene(cena_de_jogo); // como o foco (view) é uma janela (widget) tem que chamar a função membro 'show'
    foco_de_jogo->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // tira as merdas das barras inferiores
    foco_de_jogo->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // tira as merdas das barras laterais

    foco_de_jogo->setFixedSize(800,600); // coloca o foco fixo em uma janela de 800,600
    cena_de_jogo->setSceneRect(0,0,800,600); // seta a cena para comçar no 0,0 do foco e ter o mesmo tamanho que o foco

    // pontuação = a 0
    pontos = 0;

    // criar o objeto do placar
    placar_obj = new QGraphicsTextItem;
    placar_obj->setDefaultTextColor("Red");
    placar_obj->setFont(QFont("Arial",18));
    placar_obj->setPlainText("Pontuação: "+ QString::number(pontos));

    //Colocar a pontuação na cena
    cena_de_jogo->addItem(placar_obj);

    //Fazer a pontuação visivel


    tempo_inimigo = new QTimer;
    connect(tempo_inimigo , SIGNAL(timeout()),this,SLOT(add_inimigos()));
    tempo_inimigo->start(2000);
}


bool Jogar::jogar()
{
    // criar um novo item para a cena

    nave = new Nave;
    nave->setRect(0,0,100,100);

    // colocar o retângulo na cena

    cena_de_jogo->addItem(nave);

    // fazer o item poder ser focado
    nave->setFlag(QGraphicsItem::ItemIsFocusable);
    nave->setFocus();

    // arruma a origem do retangulo
    nave->setPos((foco_de_jogo->width() - nave->rect().width())/2,foco_de_jogo->height() - nave->rect().height());

    foco_de_jogo->show();

    return 1;
}

void Jogar::adicionar_placar()
{
    pontos++;
    qDebug() << "sim";
    imprimir_placar();
}

void Jogar::imprimir_placar()
{
    placar_obj->setPlainText("Pontuação: "+ QString::number(pontos));
}


void Jogar::add_inimigos()
{
    Asteroide *asteroide = new Asteroide;
    cena_de_jogo->addItem(asteroide);
    qDebug() << "Asteroide Vindo";
}
