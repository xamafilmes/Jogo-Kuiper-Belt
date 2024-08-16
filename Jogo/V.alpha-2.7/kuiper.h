#ifndef KUIPER_H
#define KUIPER_H

#include <QGraphicsScene>
#include <QObject>

class Kuiper : public QGraphicsScene
{
     Q_OBJECT
    // QGraphicsScene interface
public:
    explicit Kuiper(QObject *parent = nullptr);

protected:

signals:

};

#endif // KUIPER_H
