#include "lowersafecheckbutton.h"
#include <QPainter>
#include <QPaintEvent>

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

void lowerSafeCheckButton::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(event->rect(), (*curPixmap)[curIndex]);
}

void lowerSafeCheckButton::enterEvent(QEvent *event)
{
    curPixmap = &pixmapAnimation;
    hoverAnimation->start();
}

void lowerSafeCheckButton::InitAnimation()
{
    hoverAnimation = new QPropertyAnimation(this, "curIndex");
    hoverAnimation->setStartValue(0);
    hoverAnimation->setEndValue(7);
    hoverAnimation->setDuration(500);
}

void lowerSafeCheckButton::InitConnect()
{
    connect(hoverAnimation, SIGNAL(finished()), this,  SLOT(AnimationEnd()));
}


