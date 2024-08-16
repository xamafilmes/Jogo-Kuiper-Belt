#ifndef TELAFINAL_H
#define TELAFINAL_H

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

class Finalizar : public QWidget
{
    Q_OBJECT

public:
    explicit Finalizar(QWidget *parent = nullptr);
    ~Finalizar();

private slots:
    void reStartButtonClicked();

private:
    QPushButton *restartButton;
    QLabel *messageLabel;
    QVBoxLayout *layout;
};

#endif // TELAFINAL_H
