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
    Itens * itens_da_nave();
signals:
   void vida_nave_mudou();
    void atirou_missil_grande();
    void atirou_missil_medio();

private:
    int vida_nave;
    Itens numero_de_misseis;
};

#endif // NAVE_H
