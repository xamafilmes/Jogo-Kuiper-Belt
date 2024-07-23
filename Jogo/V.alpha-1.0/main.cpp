#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>

#include <Jogar.h>

Jogar *jogo;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    jogo = new Jogar;
    jogo->jogar();

    return a.exec();
}
