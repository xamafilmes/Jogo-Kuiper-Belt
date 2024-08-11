#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>

#include <TelaInicio.h>
#include <Jogar.h>



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Iniciar iniciar;
    iniciar.show();

    return app.exec();
}



// int main(int argc, char *argv[])
// {
//     QApplication a(argc, argv);
//     inicio = new Iniciar;
//     inicio->iniciar();
//     jogo = new Jogar;
//     jogo->jogar();

//     return a.exec();
// }
