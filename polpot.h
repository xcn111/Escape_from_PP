#ifndef POLPOT_H
#define POLPOT_H

#include <QWidget>
#include <QLabel>
#include <QPropertyAnimation>
#include <QRandomGenerator>
#include <QDateTime>

class polpot : public QWidget
{
    Q_OBJECT
public:
    explicit polpot(QWidget *parent = nullptr);
    QPropertyAnimation *moveAnimation;
    QLabel *p=new QLabel();
    void setLabel(QWidget *ui);
    ~polpot();
signals:
};

#endif // POLPOT_H
