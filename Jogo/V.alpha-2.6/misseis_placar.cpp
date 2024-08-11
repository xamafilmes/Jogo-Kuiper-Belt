#include "misseis_placar.h"

#include <QDebug>

#define FONTE_TEXTO_ITEM 20

Misseis_Placar::Misseis_Placar(int posicao_x, int posicao_y)
{
    // fazer o retangulo que envolve o placar
    envoltoria.setPixmap(QPixmap(":/icones/Contagem2.png"));
    envoltoria.setPos(posicao_x, posicao_y);

    texto_missil_medio.setDefaultTextColor("Green");
    texto_missil_medio.setFont(QFont("Arial",FONTE_TEXTO_ITEM));
    texto_missil_medio.setPlainText(QString::number(missil_medio));
    texto_missil_medio.setPos(posicao_x + 90, posicao_y + 10);

    // texto missi grande
    texto_missil_grande.setDefaultTextColor("Red");
    texto_missil_grande.setFont(QFont("Arial",FONTE_TEXTO_ITEM));
    texto_missil_grande.setPlainText(QString::number(missil_medio));
    texto_missil_grande.setPos(posicao_x + 90, posicao_y + 85);
}

void Misseis_Placar::adicionar_item_a_tela()
{
    scene()->addItem(&texto_missil_medio);
    scene()->addItem(&texto_missil_grande);
    scene()->addItem(&envoltoria);
}

void Misseis_Placar::mostrar_texto()
{
    texto_missil_grande.setPlainText(QString::number(missil_grande));
    texto_missil_medio.setPlainText(QString::number(missil_medio));
}

void Misseis_Placar::adicionar_missil_medio()
{
    missil_medio++;
    mostrar_texto();
}

void Misseis_Placar::adicionar_missil_grande()
{
    missil_grande++;
    mostrar_texto();
}

void Misseis_Placar::retirar_missil_medio()
{

    missil_medio--;
    //qDebug()<<"sim medio:" <<missil_medio;
    mostrar_texto();
}

void Misseis_Placar::retirar_missil_grande()
{

    missil_grande--;
    //qDebug()<<"sim grande?";
    mostrar_texto();
}

