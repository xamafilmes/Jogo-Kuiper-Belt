#ifndef NAVE_H
#define NAVE_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QObject>
#include <QTimer>

#include "Itens.h"
#include "config.h"

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
    void envia_tempo(int);
    void nave_explodiu();

public slots:
    void posMouse(int ponto);  // <- a fazer
    void contagem_tempo();
    void nave_reset_tiro();

private:
    int vida_nave;
    double tempo;
    double cursor;
    bool flag_nave_pode_atirar = true;
    Itens numero_de_misseis;
    QTimer tempo_movimento;
    QTimer tempo_missil;
};

#endif // NAVE_H
