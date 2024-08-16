#include "TelaInicio.h"
#include <QGraphicsScene>
#include <QFont>
#include <QGraphicsTextItem>

#include <QtWidgets>
#include "config.h"
#include <Jogar.h>

Jogar *jogo;

Iniciar::Iniciar(QWidget *parent)
    : QWidget(parent)
{
    // Cria o botão "Iniciar"
    startButton = new QPushButton("Iniciar", this);
    connect(startButton, &QPushButton::clicked, this, &Iniciar::onStartButtonClicked);

    // Cria o QLabel para a imagem de fundo
    backgroundLabel = new QLabel(this);
    backgroundLabel->setPixmap(QPixmap(":/icones/FundoInicio.png")); // Substitua pelo caminho da sua imagem
    backgroundLabel->setScaledContents(true);

    // Cria o layout e adiciona widgets
    layout = new QVBoxLayout(this);
    layout->addWidget(backgroundLabel);
    layout->addWidget(startButton);

    setLayout(layout);
}

Iniciar::~Iniciar()
{

}

void Iniciar::onStartButtonClicked()
{
    // Lógica para iniciar o jogo
    this->hide(); // Esconde a tela inicial

    // Cria e mostra a tela do jogo
    jogo = new Jogar();
    jogo->jogar();
}

