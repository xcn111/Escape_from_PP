#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("逃离金边");
    p=new Player(this);
    playaudio();
    timer = new QTimer(this);
    bg=new polpot();
    bg->setLabel(this);
    connectMove();
    connect(timer, &QTimer::timeout, this, [&](){
        delete bg;
        bg=new polpot();
        bg->setLabel(this);
        connectMove();
    });
    timer->start(5000);  // 5000 milliseconds (5 seconds)
}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    int key=event->key();
    if(key==Qt::Key_Space) p->jump();
}

void Widget::playaudio()
{
    qplayer=new QMediaPlayer();
    output=new QAudioOutput();
    qplayer->setAudioOutput(output);
    output->setVolume(50);
    qplayer->setSource(QUrl("qrc:/audio/Sat_Tee_Touy.mp3"));
    qplayer->play();
}

void Widget::failed()
{
    qplayer->pause();
    qplayer->setSource(QUrl("qrc:/audio/gun_shot.aiff"));
    qplayer->play();
    MyDialog dialog(this);
    dialog.exec();
}

void Widget::connectMove()
{
    connect(bg->moveAnimation,&QPropertyAnimation::valueChanged,[&](){
        int x1,y1,x2,y2,a1,b1,a2,b2;
        x1=p->l->pos().x(); y1=p->l->pos().y();
        a1=p->l->pixmap().width();
        b1=p->l->pixmap().height();
        if(bg!=nullptr){
            x2=bg->p->pos().x(); y2=bg->p->pos().y();
            a2=bg->p->pixmap().width();
            b2=bg->p->pixmap().height();
        } else return;
        if((x2<x1+a1&&x1+a1<x2+a2)||(x2<x1&&x1<x2+a2)){
            if((y2<y1&&y1<y2+b2)||(y2<y1+b1&&y1+b1<y2+b2)){
                failed();
            }
        }
        if((x1<x2&&x2<x1+a1)||(x1<x2+a1&&x2+a2<x1+a1)){
            if((y1<y2&&y2<y1+b1)||(y1<y2+b2&&y2+b2<y1+b1))
                failed();
        }
    });
}
