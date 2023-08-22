#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QLabel>
#include <QWidget>
#include <QKeyEvent>
#include <QPropertyAnimation>

class Player: public QWidget
{
    Q_OBJECT
public:
    explicit Player(QWidget *ui,QWidget *parent = nullptr);
    void jump();
    void fall();
    QPropertyAnimation *jumpAnimation;
    QPropertyAnimation *fallAnimation;
    QLabel *l;
};

#endif // PLAYER_H
