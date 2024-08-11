#ifndef ESPACO_H
#define ESPACO_H
#include <QGraphicsScene>
#include <QEvent>
#include <QGraphicsSceneMouseEvent>
#include <config.h>
#include <QMouseEvent>
#include <QDebug>

class Espaco: public QGraphicsScene
{
    Q_OBJECT
public:
    Espaco();
    void mouseMoveEvent(QGraphicsSceneMouseEvent *evento);

signals:
    void mover_mouse(int pos);
};


#endif // ESPACO_H
