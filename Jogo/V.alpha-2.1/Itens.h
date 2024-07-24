#ifndef ITENS_H
#define ITENS_H

#include <QGraphicsPixmapItem>
#include <QDebug>

// Como usar essa classe:
// um objeto para a nave que contêm os misseis dropados dos asteróides
// um objeto criado depois da destruição do asteroide que contêm os misseis dropados e vida
// quando pertence a nave, está em contato com a cena e a parte gráfica para mostrar duas coisas
// 1) Mensagens de "+N Vidas" e "+N Misseis 'tipo_missil'"
// 2) Misseis diferentes que a nave tem na parte inferior do display

class Itens
{
public:
    Itens(int probabilidade);
private:
    int vida_adicional_item;
    int missil_adicional[3]; // int missil_adicional[tipo_missil]; implicitamente definido para não incluir 'Missil.h'
};


#endif // ITENS_H
