#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPropertyAnimation>
#include <QKeyEvent>
#include <QMessageBox>
#include <QTimer>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QThread>
#include "player.h"
#include "polpot.h"
#include "mydialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
protected:
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::Widget *ui;
    Player *p;
    polpot *bg=nullptr;
    QTimer *timer;
    QMediaPlayer *qplayer;
    QAudioOutput *output;
    void playaudio();
    void failed();
    void connectMove();
};
#endif // WIDGET_H
