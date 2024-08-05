#include "Jogar.h"
#include <QGraphicsScene>
#include <QFont>
#include <QGraphicsTextItem>

#define LARGURA_TELA_X 800               // Dimensões da tela
#define ALTURA_TELA_Y 600                //

#define FOCO_DA_TELA_X 0                 // Foco da tela
#define FOCO_DA_TELA_Y 0                 //

#define FONTE_TEXTO_VIDA   18            // Fontes:vida
#define FONTE_TEXTO_PLACAR 18            // placar
#define FONTE_TEXTO_ITEM   13            // item

#define ESPACO_PLACAR_E_VIDA 5           // Numero em pixeis
#define ESPACO_TEXTO_ITEM    200

#define ESPACO_ITEM_VIDA_Y 0             // Começo do item de vida no eixo y
#define ESPACO_ITEM_VIDA_E_MISSIL_Y 20   // espaço entre os texto de item da vida e de missil

#define POSICAO_X_OFFSEET_NAVE 0         // Posição da Nave
#define POSICAO_Y_OFFSET_NAVE 0          //


#define POSICAO_X_DO_MISSIL 600
#define POSICAO_Y_DO_MISSIL 100


Jogar::Jogar(): placar_misseis(POSICAO_X_DO_MISSIL,POSICAO_Y_DO_MISSIL)
{
    // cria uma cena

    cena_de_jogo = new QGraphicsScene;

    // adicionar um vizualização de cena

    foco_de_jogo = new QGraphicsView;
    foco_de_jogo->setScene(cena_de_jogo); // como o foco (view) é uma janela (widget) tem que chamar a função membro 'show'
    foco_de_jogo->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // tira as merdas das barras inferiores
    foco_de_jogo->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // tira as merdas das barras laterais

    foco_de_jogo->setFixedSize(LARGURA_TELA_X,ALTURA_TELA_Y); // coloca o foco fixo em uma janela de 800,600
    cena_de_jogo->setSceneRect(FOCO_DA_TELA_X,FOCO_DA_TELA_Y,LARGURA_TELA_X,ALTURA_TELA_Y); // seta a cena para comçar no 0,0 do foco e ter o mesmo tamanho que o foco

    // colocar o background como sendo uma imagem
    // precisa adicionar "QImage" header
    cena_de_jogo->setBackgroundBrush(QBrush(QImage(":/icones/Fundo.png")));

    // pontuação = a 0
    pontos = 0;

//---------------------------------------------------------------------------------------------------------------------//
//                                 Itens de texto Inicio
//---------------------------------------------------------------------------------------------------------------------//
    // criar o objeto do texto do placar
    placar_texto_obj = new QGraphicsTextItem;
    placar_texto_obj->setDefaultTextColor("Blue");
    placar_texto_obj->setFont(QFont("Arial",FONTE_TEXTO_PLACAR));
    placar_texto_obj->setPlainText("Pontuação: "+ QString::number(pontos));

    //Coloca o objeto do texto da pontuação na cena
    cena_de_jogo->addItem(placar_texto_obj);

    //criar o objeto do texto da vida
    vida_texto_obj = new QGraphicsTextItem;
    vida_texto_obj->setDefaultTextColor("Red");
    vida_texto_obj->setFont(QFont("Arial",FONTE_TEXTO_VIDA ));
    vida_texto_obj->setPlainText("Vida: "+ QString::number(6)); // Vida sempre inicia com 6
    vida_texto_obj->setPos(FOCO_DA_TELA_X,placar_texto_obj->pos().y()+ placar_texto_obj->font().pointSize()+ ESPACO_PLACAR_E_VIDA);

    //Coloca o objeto do texto da vida na cena
    cena_de_jogo->addItem(vida_texto_obj);

    // Criar o objeto de texto para os itens de vida
    itens_texto_vida_obj = new QGraphicsTextItem;
    itens_texto_vida_obj->setDefaultTextColor("Purple");
    itens_texto_vida_obj->setFont(QFont("Arial",FONTE_TEXTO_ITEM ));
    itens_texto_vida_obj->setPos(LARGURA_TELA_X - ESPACO_TEXTO_ITEM,ESPACO_ITEM_VIDA_Y);

    //Colocar o objeto de texto do item vida na cena
    cena_de_jogo->addItem(itens_texto_vida_obj);

    // Colocar ele translucido
    itens_texto_vida_obj->setOpacity(0);

    // Criar o objeto de texto para os itens de vida
    itens_texto_missil_obj = new QGraphicsTextItem;
    itens_texto_missil_obj->setDefaultTextColor("Purple");
    itens_texto_missil_obj->setFont(QFont("Arial",FONTE_TEXTO_ITEM ));
    itens_texto_missil_obj->setPos(LARGURA_TELA_X - ESPACO_TEXTO_ITEM,ESPACO_ITEM_VIDA_Y +ESPACO_ITEM_VIDA_E_MISSIL_Y);

    //Colocar o objeto de texto do item vida na cena
    cena_de_jogo->addItem(itens_texto_missil_obj);

    // Colocar ele translucido
    itens_texto_missil_obj->setOpacity(0);

//---------------------------------------------------------------------------------------------------------------------//
    //                                 Itens de texto FIM
//---------------------------------------------------------------------------------------------------------------------//

//---------------------------------------------------------------------------------------------------------------------//
    //                                 Misseis na tela INICIO
//---------------------------------------------------------------------------------------------------------------------//

    cena_de_jogo->addItem(&placar_misseis);
    // depois, ainda precisa adicionar o item na tela
    placar_misseis.adicionar_item_a_tela();

//---------------------------------------------------------------------------------------------------------------------//
    //                                 Misseis na tela INICIO
//---------------------------------------------------------------------------------------------------------------------//

    // Temporizador de retirada do texto de item
    tempo_texto_obg = new QTimer;

    //Temporização dos asteroides
    tempo_asteroide = new QTimer;
    connect(tempo_asteroide , SIGNAL(timeout()),this,SLOT(add_asteroides()));
    tempo_asteroide->start(2000);

    //colocar son de backgraund
    //musica_de_fundo->setMedia(QUrl("qrc:/sons/Musica_de_Fundo.mp3"));   //retirado devido a necessidade
    //musica_de_fundo->play(); //retirado devido a necessidade

    //faz ela tocar de novo com o auxilio do sinal de mudança de estado do player de musica
    //connect(musica_de_fundo, SIGNAL(stateChanged(QMediaPlayer::State)),this,SLOT(tocar_denovo())); //retirado devido a necessidade
}


bool Jogar::jogar()
{
    // criar um novo item para a cena

    nave = new Nave;
    nave->setPixmap(QPixmap(":/icones/Nave.png"));

    // conectar os sinais da nave ao jogo

    connect(nave,SIGNAL(vida_nave_mudou()),this,SLOT(imprimir_vida()));
    connect(nave,SIGNAL(atirou_missil_grande()), this,SLOT(missil_grande_placar_decrementar()));
    connect(nave,SIGNAL(atirou_missil_medio()),this,SLOT(missil_medio_placar_decrementar()));

    // colocar o retângulo na cena

    cena_de_jogo->addItem(nave);

    // fazer o item poder ser focado
    nave->setFlag(QGraphicsItem::ItemIsFocusable);
    nave->setFocus();

    // arruma a origem do retangulo
    nave->setPos((foco_de_jogo->width() - nave->boundingRect().width())/2 + POSICAO_X_OFFSEET_NAVE,foco_de_jogo->height() - nave->boundingRect().height() + POSICAO_Y_OFFSET_NAVE);

    foco_de_jogo->show();

    return 1;
}

void Jogar::adicionar_placar(int ponto_extra)
{
    pontos = pontos + ponto_extra;
    //qDebug() << "sim";
    imprimir_placar();
}

void Jogar::imprimir_placar()
{
    placar_texto_obj->setPlainText("Pontuação: "+ QString::number(pontos));
}

void Jogar::texto_item_adquirido(Itens item_adquirido)
{
    int missil_medio = item_adquirido.ver_numero_misseis()[0];
    int missil_grande = item_adquirido.ver_numero_misseis()[1];
    int vida_adicional = item_adquirido.vida_adicional();
    if(missil_medio)
    {
        itens_texto_missil_obj->setPlainText("+1 missil médio");
        // adiciona placar
        placar_misseis.adicionar_missil_medio();
        itens_texto_missil_obj->setOpacity(1);
    }
    if(missil_grande)
    {
        itens_texto_missil_obj->setPlainText("+1 missil grande");
        // adiciona placar
        placar_misseis.adicionar_missil_grande();
        itens_texto_missil_obj->setOpacity(1);
    }
    if(vida_adicional)
    {
        itens_texto_vida_obj->setPlainText("Vida adicional: "+ QString::number(vida_adicional));
        itens_texto_vida_obj->setOpacity(1);
    }
    tempo_texto_obg->start(1500);
    connect(tempo_texto_obg, SIGNAL(timeout()),this,SLOT(retira_texto_item()));
}

void Jogar::imprimir_vida()
{
    int vida = nave->ver_vida_nave();
    vida_texto_obj->setPlainText("Vida: "+ QString::number(vida));
}

/*void Jogar::tocar_denovo()
{
    if(musica_de_fundo->state() == QMediaPlayer::StoppedState )
    {
       musica_de_fundo->play();
       qDebug()<< "musica voltoi";
    }
}*/ //retirado devido a necessidade

void Jogar::criar_itens_para_nave(int semente_criacao_asteroide)
{
    qDebug()<<"ITEM CRIADO , nr_seed: "<< semente_criacao_asteroide;
    Itens item_criado = Itens(semente_criacao_asteroide);
    // adicionar um item a nave
    nave->adicionar_itens(item_criado);
    // mostra o texto dos misseis e vidas
    texto_item_adquirido(item_criado);
    qDebug()<<"Item missil médio:" << item_criado.ver_numero_misseis()[0]<< "\n missil grande "<<item_criado.ver_numero_misseis()[1] ;
}


void Jogar::retira_texto_item()
{
    //qDebug()<<"Entrou 'retira_texto_item'";
    itens_texto_missil_obj->setOpacity(0);
    itens_texto_vida_obj->setOpacity(0);
    disconnect(tempo_texto_obg, SIGNAL(timeout()),this,SLOT(retira_texto_item()));
}

void Jogar::missil_medio_placar_decrementar()
{
    qDebug()<<"retirou medio?";
    // decrementa o item do placar
    placar_misseis.retirar_missil_medio();
}

void Jogar::missil_grande_placar_decrementar()
{
    qDebug()<<"retirou grande?";
    // decrementa o item do placar
    placar_misseis.retirar_missil_grande();
}

void Jogar::add_asteroides()
{
    Asteroide *asteroide = new Asteroide;
    cena_de_jogo->addItem(asteroide);
    connect(asteroide,SIGNAL(criar_item_de_asteroide(int)),this,SLOT(criar_itens_para_nave(int)));
    //qDebug() << "Asteroide Vindo";
}
