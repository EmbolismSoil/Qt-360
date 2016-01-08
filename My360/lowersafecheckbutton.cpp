#include "lowersafecheckbutton.h"
#include <QPainter>
#include <QPaintEvent>
#include <QTimeLine>
#include <QTimer>
#include <QDebug>
#include <QMouseEvent>
#include <common.h>

lowerSafeCheckButton::lowerSafeCheckButton(QString path,
                                           QString AnimationPath, QWidget *parent):
    Button(path, 4, parent, 1)
{    
    QPixmap animationPixmap(AnimationPath);
    for (int cnt = 0; cnt < 8; cnt ++)
        pixmapAnimation.push_back(animationPixmap.copy(cnt * animationPixmap.width() / 8, 0,
                                                       animationPixmap.width() / 8, animationPixmap.height()));

    curPixmap = getPixmapList();
    InitAnimation();
    InitConnect();
}

lowerSafeCheckButton::~lowerSafeCheckButton()
{
    delete  animation;
}

void lowerSafeCheckButton::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    if (curPixmap->size() > curIndex)
        painter.drawPixmap(event->rect(), (*curPixmap)[curIndex]);
}

void lowerSafeCheckButton::enterEvent(QEvent *event)
{
    __UNUSED(event);
    curPixmap = &pixmapAnimation;
    animation->start();
}

void lowerSafeCheckButton::leaveEvent(QEvent *event)
{
    animation->stop();
    curPixmap = getPixmapList();
    Button::leaveEvent(event);
}

void lowerSafeCheckButton::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton){
        animation->stop();
        curPixmap = getPixmapList();
     }

    Button::mousePressEvent(event);
}


void lowerSafeCheckButton::InitAnimation()
{
    animation = new QPropertyAnimation(this, "curIndex");
    animation->setStartValue(0);
    animation->setEndValue(6);
    animation->setDuration(600);
}

void lowerSafeCheckButton::InitConnect()
{
    connect(animation, SIGNAL(finished()), this,  SLOT(Animation()));
}


