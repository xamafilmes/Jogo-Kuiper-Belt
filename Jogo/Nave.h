#ifndef NAVE_H
#define NAVE_H

#include <QGraphicsRectItem>
#include <QKeyEvent>

class Nave: public QGraphicsRectItem
{
public:
    Nave();
    void keyPressEvent(QKeyEvent *evento);
private:
    int vida_nave;
};

#endif // NAVE_H
