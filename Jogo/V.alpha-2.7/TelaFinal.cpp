#include "TelaFinal.h"
#include <QGraphicsScene>
#include <QFont>
#include <QGraphicsTextItem>

#include <QtWidgets>
#include "config.h"
#include <Jogar.h>

// Jogar *jogo;
extern Jogar *jogo;

Finalizar::Finalizar(QWidget *parent)
    : QWidget(parent)
{
    // Cria o botão "Reiniciar"
    restartButton = new QPushButton("Reiniciar", this);
    connect(restartButton, &QPushButton::clicked, this, &Finalizar::reStartButtonClicked);

    // Cria o QLabel para a imagem de fundo
    messageLabel = new QLabel(this);
    messageLabel->setPixmap(QPixmap(":/icones/TelaFinal.png")); // Substitua pelo caminho da sua imagem
    messageLabel->setScaledContents(true);

    // Cria o layout e adiciona widgets
    layout = new QVBoxLayout(this);
    layout->addWidget(messageLabel);
    layout->addWidget(restartButton);

    setLayout(layout);
}

Finalizar::~Finalizar()
{

}

void Finalizar::reStartButtonClicked()
{
    // Lógica para iniciar o jogo
    this->hide(); // Esconde a tela inicial

    // Cria e mostra a tela do jogo
    jogo = new Jogar();
    jogo->jogar();
}

// Finalizar finalizar;
// finalizar.show();
