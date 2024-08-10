#ifndef SPACE_H
#define SPACE_H

#include <QGraphicsScene>
#include <QObject>

class Space : public QGraphicsScene
{
     Q_OBJECT
    // QGraphicsScene interface
public:
    explicit Space(QObject *parent = nullptr);

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

signals:
    void mouse_moveu(int pos);//

};

#endif // SPACE_H
