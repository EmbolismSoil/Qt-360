#include "loginbutton.h"
#include <QPainter>
#include <QRect>
#include <closebutton.h>
#include <QPaintEvent>
#include <math.h>

LoginButton::LoginButton(QString FileName, int num , QWidget *parent ):
    Button(FileName, num, parent)
{
    background = new QPixmap(":/background/def_head.png");
}

LoginButton::~LoginButton()
{
    delete background;
}

void LoginButton::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect rect = event->rect();
    QRect frontRect(rect);

    int x = (rect.x() + (pixmatpList[0].width() -  background->width()) / 2);
    int y = (rect.y() + (pixmatpList[0].height() - background->height()) / 2);

    painter.drawPixmap(x, y, *background);

    Button::paintEvent(event);
}



