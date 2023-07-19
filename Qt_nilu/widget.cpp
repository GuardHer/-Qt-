#include "widget.h"
#include <QSoundEffect>
#include <QDir>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QResource::registerResource("./nilu.rcc");

    QSoundEffect *startsound=new QSoundEffect();
    startsound->setSource(QUrl::fromLocalFile("./Untitled.wav"));
    startsound->setLoopCount(QSoundEffect::Infinite); //注释掉只播放一次，打开循环播放
    startsound->setVolume(0.1f);
    startsound->play();


    setWindowFlag(Qt::FramelessWindowHint);
    setWindowFlags (windowFlags () | Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setMouseTracking(true);
    setMinimumSize(1400, 1400);
    auto hlayout = new QHBoxLayout(this);
    auto l = new QLabel();
    hlayout->addWidget(l);
    this->idx = 1;
    //    l->setStyleSheet(QString("background: url(:/static/nilu/%1.png) no-repeat;").arg(this->idx));
    auto time = new QTimer(this);
    time->setInterval(45);
    connect(time, &QTimer::timeout, this, [this, l]() {
        this->idx = (this->idx + 1 ) % 5584 + 1;
        l->setStyleSheet(QString("background: url(:/static/nilu/%1.png) no-repeat;").arg(this->idx));
    });
    time->start();

}

Widget::~Widget()
{
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    diff_ = event->globalPosition().toPoint() - this->pos();
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    diff_ = QPoint();
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPosition().toPoint() - diff_);
}
