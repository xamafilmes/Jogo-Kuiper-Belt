#ifndef MISSIL_H
#define MISSIL_H

#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>
//#include <QMediaPlayer> //retirado devido a necessidade

#include <QDebug>

#include "Jogar.h"
extern Jogar *jogo; //foi usado para adicionar o placar sem usar signals e slots porem não é o ideal, para adicionar
// a vida, a implementação foi feita de maneira correta

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

class Missil: public QObject, public QGraphicsPixmapItem
{
    // além de derivar do QObject tem que declarar a macro QObject aqui dentro também
    Q_OBJECT
public:
    Missil(tipo_missil tipo = missil_normal);
    // Missil();
    void setTipo(tipo_missil tipo);
    tipo_missil tipo() const;
public slots:
    void mover();
private:
    tipo_missil missil_t;

    //QMediaPlayer * som_missil; //retirado devido a necessidade

 //   QMediaPlayer * som_missil;
    QTimer temporizador;

};

#endif // MÍSSIL_H
