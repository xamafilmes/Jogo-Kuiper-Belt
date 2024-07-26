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
    Itens(int asteroide_tamanho);
    int * ver_numero_misseis();
    int adicionar_item_a_nave(Itens asteroide_item); // o inteiro que a função retorna é a vida a ser adicionada
    // como a classe Itens não tem signals, a vida deve ser adicionada na própria classe da nave
    void decrementar_misseis(int tamanho_missil);
    bool ver_item_existe();
private:
    bool item_existe = false;
    int vida_adicional_item;
    int missil_adicional[2]; // int missil_adicional[tipo_missil -1]; implicitamente definido para não incluir 'Missil.h'
};


#endif // ITENS_H
