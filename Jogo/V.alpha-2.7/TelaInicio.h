#ifndef TELAINICIO_H
#define TELAINICIO_H

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include <QDebug>
#include <QGraphicsScene>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

//#include <QMediaPlayer> //retirado devido a necessidade

#include <QImage>

class Iniciar : public QWidget
{
    Q_OBJECT

public:
    explicit Iniciar(QWidget *parent = nullptr);
    ~Iniciar();

private slots:
    void onStartButtonClicked();

private:
    QPushButton *startButton;
    QLabel *backgroundLabel;
    QVBoxLayout *layout;
};


#endif // TELAINICIO_H


