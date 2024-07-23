#ifndef NAVE_H
#define NAVE_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QObject>

class Nave: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Nave();
    void keyPressEvent(QKeyEvent *evento);
    //vida
    void decrementar_vida(int dano);
    void incrementar_vida(int vida_adicional);
    int ver_vida_nave();

signals:
   void vida_nave_mudou();

private:
    int vida_nave;
};

#endif // NAVE_H
