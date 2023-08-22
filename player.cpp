#include "player.h"

Player::Player(QWidget *ui,QWidget* parent):QWidget(parent)
{
    l=new QLabel(ui);
    QPixmap originalPixmap(":/image/player.png");
    QPixmap scaledPixmap = originalPixmap.scaled(QSize(100, 150), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    l->setPixmap(scaledPixmap);
    l->move(QPoint(100,450));
    l->show();

    jumpAnimation=new QPropertyAnimation (l,"pos");
    fallAnimation=new QPropertyAnimation (l,"pos");
    connect(jumpAnimation,&QPropertyAnimation::finished,[&](){
        fall();
        int y=l->pos().y();
//        qDebug()<<y<<" down"<<'\n';
    });

}
void Player::jump()
{
    jumpAnimation->stop();
    int y=l->pos().y();
//    qDebug()<<y<<" up"<<'\n';
    jumpAnimation->setDuration(500);
    jumpAnimation->setStartValue(QPoint(100,y));
    jumpAnimation->setEndValue(QPoint(100,y-100>=0?y-100:0));
    jumpAnimation->setEasingCurve(QEasingCurve::OutQuad);
    jumpAnimation->start();

}

void Player::fall()
{
    int y=l->pos().y();
    fallAnimation->setDuration(500);
    fallAnimation->setStartValue(QPoint(100,y));
    fallAnimation->setEndValue(QPoint(100,450));
    fallAnimation->setEasingCurve(QEasingCurve::InQuad);
    fallAnimation->start();
}
