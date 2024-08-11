#ifndef CONFIG_H
#define CONFIG_H

//aparentemente, a cada mudança de configuração, precisa fazer um rebuilde.

#define LARGURA_TELA_X 800               // Dimensões da tela
#define ALTURA_TELA_Y 600                //

#define FOCO_DA_TELA_X 0                 // Foco da tela
#define FOCO_DA_TELA_Y 0                 //

#define FONTE_TEXTO_VIDA   18            // Fontes:vida
#define FONTE_TEXTO_PLACAR 18            // placar
#define FONTE_TEXTO_ITEM   13            // item

#define ESPACO_PLACAR_E_VIDA 5           // Numero em pixeis
#define ESPACO_TEXTO_ITEM    200

#define ESPACO_ITEM_VIDA_Y 0             // Começo do item de vida no eixo y
#define ESPACO_ITEM_VIDA_E_MISSIL_Y 20   // espaço entre os texto de item da vida e de missil

#define POSICAO_X_OFFSEET_NAVE 0         // Posição da Nave
#define POSICAO_Y_OFFSET_NAVE 0          //


#define POSICAO_X_DO_MISSIL 600
#define POSICAO_Y_DO_MISSIL 100

#define CONSTANTE_DE_TEMPO_MOVIMENTO_NAVE 0.5

#define TEMPO_ASTEROIDDE 2               //segundos
#define TEMPO_MISSIL     0.3             //segundos


#endif // CONFIG_H
