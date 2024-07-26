#include <Itens.h>


Itens::Itens(int semente_criacao_asteroide)
{
    int limite_minimo = semente_criacao_asteroide % 3;
    if(limite_minimo > 0)
    {
        item_existe = true; // item existe, usado para não adicionar itens que não foram inicializados

        if (limite_minimo == 1)
        {
            missil_adicional[0] = 1;
            vida_adicional_item = (int)((semente_criacao_asteroide/100)%7)%4;
        }
        else
        {
            missil_adicional[1] = 1;
            vida_adicional_item = (int)(semente_criacao_asteroide/100)%7;
        }
    }
}

int * Itens::ver_numero_misseis()
{
    return missil_adicional;
}

int Itens::adicionar_item_a_nave(Itens asteroide_item)
{
    this->missil_adicional[0] = asteroide_item.missil_adicional[0] + this->missil_adicional[0];
    this->missil_adicional[1] = asteroide_item.missil_adicional[1] + this->missil_adicional[1];
    return asteroide_item.vida_adicional_item;
}

void Itens::decrementar_misseis(int tamanho_missil) //
{
    this->missil_adicional[tamanho_missil] = this->missil_adicional[tamanho_missil] -1;
}

bool Itens::ver_item_existe()
{
    return item_existe;
}
