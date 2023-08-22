#include "polpot.h"

//polpot::polpot(QWidget *ui,QWidget *parent)
//    : QWidget{parent}
//{
//    p=new QLabel(ui);
//    QPixmap originalPixmap(":/image/polpot1.jpg");
//    QPixmap scaledPixmap = originalPixmap.scaled(QSize(220, 250), Qt::KeepAspectRatio, Qt::SmoothTransformation);
//    p->setPixmap(scaledPixmap);
//    p->move(QPoint(900,200));
//    p->show();

//    moveAnimation=new QPropertyAnimation(p,"pos");
//    moveAnimation->setDuration(5000);
//    moveAnimation->setEndValue(QPoint(-100,200));
//    moveAnimation->start();
//}

polpot::polpot(QWidget *parent): QWidget{parent}
{

}

void polpot::setLabel(QWidget *ui)
{
    int minValue = 50;
    int maxValue = 232;
    int x = QRandomGenerator::system()->bounded(minValue, maxValue + 1);
    p->setParent(ui);

    minValue=0;
    maxValue=9;
    int k = QRandomGenerator::system()->bounded(minValue, maxValue + 1);
    QPixmap originalPixmap(":/image/polpot"+QString((char)('0'+k))+".jpg");
    QPixmap scaledPixmap = originalPixmap.scaled(QSize(x, x), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    minValue=0;
    maxValue=600-scaledPixmap.height();
    int y = QRandomGenerator::system()->bounded(minValue, maxValue + 1);
    p->setPixmap(scaledPixmap);
    p->move(QPoint(900,y));
    p->show();

    moveAnimation=new QPropertyAnimation(p,"pos");
    moveAnimation->setDuration(5000);
    moveAnimation->setEndValue(QPoint(-300,y));
    moveAnimation->start();
}

polpot::~polpot()
{
    moveAnimation->stop();
    delete moveAnimation;
    delete p;
}
