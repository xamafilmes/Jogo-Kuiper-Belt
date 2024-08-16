#ifndef MISSEIS_PLACAR_H
#define MISSEIS_PLACAR_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>

#define ESPACO_ITENS 20

class Misseis_Placar : public QObject, public QGraphicsPolygonItem
{
    Q_OBJECT
public:
     Misseis_Placar(int posicao_x, int posicao_y);
     // imagem estática da contagem de misseis medios na tela          // <---- fazer
     // envoltoria
     QGraphicsPixmapItem envoltoria;
     // texto missil medio
     QGraphicsTextItem texto_missil_medio;
     // texto missi grande
     QGraphicsTextItem texto_missil_grande;
     void adicionar_item_a_tela();
     // quantidade de misseis medios
     int missil_medio = 0;
     // quantidade de misseis grandes
     int missil_grande = 0;

     //funções

     // mostrar texto
     void mostrar_texto();
     void adicionar_missil_medio();
     void adicionar_missil_grande();
     void retirar_missil_medio();
     void retirar_missil_grande();
};

#endif // MISSEIS_PLACAR_H
