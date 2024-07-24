#include "Jogar.h"
#include <QGraphicsScene>
#include <QFont>
#include <QGraphicsTextItem>


#define ESPACO_PLACAR_E_VIDA 5 // numero em pixeis

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

    // colocar o background como sendo uma imagem
    // precisa adicionar "QImage" header
    cena_de_jogo->setBackgroundBrush(QBrush(QImage(":/icones/Fundo.png")));

    // pontuação = a 0
    pontos = 0;

    // criar o objeto do placar
    placar_obj = new QGraphicsTextItem;
    placar_obj->setDefaultTextColor("Blue");
    placar_obj->setFont(QFont("Arial",18));
    placar_obj->setPlainText("Pontuação: "+ QString::number(pontos));

    //Coloca o objeto da pontuação na cena
    cena_de_jogo->addItem(placar_obj);

    //criar o objeto da vida
    vida_obj = new QGraphicsTextItem;
    vida_obj->setDefaultTextColor("Red");
    vida_obj->setFont(QFont("Arial",18));
    vida_obj->setPlainText("Vida: "+ QString::number(6));
    vida_obj->setPos(0,placar_obj->pos().y()+ placar_obj->font().pointSize()+ ESPACO_PLACAR_E_VIDA);

    //Coloca o objeto da vida na cena
    cena_de_jogo->addItem(vida_obj);

    //Temporização dos inimigos
    tempo_inimigo = new QTimer;
    connect(tempo_inimigo , SIGNAL(timeout()),this,SLOT(add_inimigos()));
    tempo_inimigo->start(2000);

    //colocar son de backgraund
    musica_de_fundo->setMedia(QUrl("qrc:/sons/Musica_de_Fundo.mp3"));
    musica_de_fundo->play();

    //faz ela tocar de novo com o auxilio do sinal de mudança de estado do player de musica
    connect(musica_de_fundo, SIGNAL(stateChanged(QMediaPlayer::State)),this,SLOT(tocar_denovo()));
}


bool Jogar::jogar()
{
    // criar um novo item para a cena

    nave = new Nave;
    nave->setPixmap(QPixmap(":/icones/Nave.png"));

    // conectar os sinais da nave ao jogo

    connect(nave,SIGNAL(vida_nave_mudou()),this,SLOT(imprimir_vida()));

    // colocar o retângulo na cena

    cena_de_jogo->addItem(nave);

    // fazer o item poder ser focado
    nave->setFlag(QGraphicsItem::ItemIsFocusable);
    nave->setFocus();

    // arruma a origem do retangulo
    nave->setPos((foco_de_jogo->width() - nave->boundingRect().width())/2,foco_de_jogo->height() - nave->boundingRect().height());

    foco_de_jogo->show();

    return 1;
}

void Jogar::adicionar_placar(int ponto_extra)
{
    pontos = pontos + ponto_extra;
    qDebug() << "sim";
    imprimir_placar();
}

void Jogar::imprimir_placar()
{
    placar_obj->setPlainText("Pontuação: "+ QString::number(pontos));
}

void Jogar::imprimir_vida()
{
    int vida = nave->ver_vida_nave();
    vida_obj->setPlainText("Vida: "+ QString::number(vida));
}

void Jogar::tocar_denovo()
{
    if(musica_de_fundo->state() == QMediaPlayer::StoppedState )
    {
       musica_de_fundo->play();
       qDebug()<< "musica voltoi";
    }

}

void Jogar::add_inimigos()
{
    Asteroide *asteroide = new Asteroide;
    cena_de_jogo->addItem(asteroide);
    qDebug() << "Asteroide Vindo";
}
