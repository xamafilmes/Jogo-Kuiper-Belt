#ifndef NAVE_H
#define NAVE_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QObject>

#include "Itens.h"

class Nave: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Nave();
    void keyPressEvent(QKeyEvent *evento);
    //vida
    void decrementar_vida(int dano);
    void incrementar_vida(int vida_adicional);
    int ver_vida_nave();
    void adicionar_itens(Itens item_ad);
signals:
   void vida_nave_mudou();

private:
    int vida_nave;
    Itens numero_de_misseis;
};

#endif // NAVE_H
