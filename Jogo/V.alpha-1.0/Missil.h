#ifndef MISSIL_H
#define MISSIL_H

#include <QGraphicsRectItem>
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>

#include "Placar.h"

#include "Jogar.h"
extern Jogar *jogo;

//incluir QList para ver a colizão entre objetos
#include <QList>

//toda classe que tenha sinais e slotes tem ue derivar de QObject
#include <QObject>

enum tipo_missil
{
    missil_normal,
    missil_medio,
    missil_grande
};

class Missil: public QObject, public QGraphicsRectItem
{
    // além de derivar do QObject tem que declarar a macro QObject aqui dentro também
    Q_OBJECT
public:
    Missil();
public slots:
    void mover();
private:
    tipo_missil missil_t;
};

#endif // MÍSSIL_H
