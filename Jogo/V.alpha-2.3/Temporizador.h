#ifndef TEMPORIZADOR_H
#define TEMPORIZADOR_H

#include <QTimer>
#include <QObject>

class Temporizador: public QTimer
{
    Temporizador();
public slots:
    void esgotou();

};

#endif // TEMPORIZADOR_H
