#include "closebutton.h"
#include <QPainter>
#include <QPaintEvent>
#include <QPixmap>


Button::Button( QString FileName, int num , QWidget *parent):
    QPushButton(parent)
{
    QPixmap pixmap(FileName);
    for (int cnt = 0; cnt < num; ++cnt){
        pixmatpList.push_back( pixmap.copy(cnt * (pixmap.width() / num), 0,
                                           pixmap.width() / num , pixmap.height()));
    }

    setSizePolicy(QSizePolicy::Fixed	, QSizePolicy::Fixed	);
    //resize(pixmap.width() / num + 1, pixmap.height() + 1);
    curIndex = 0;
}


 void Button::paintEvent ( QPaintEvent * event)
 {
     QPainter painter(this);

     QRect rect = event->rect();
     painter.drawPixmap(rect.x(), rect.y(), pixmatpList[curIndex]);
 }

 void Button::enterEvent(QEvent *event)
 {
    if (pixmatpList.size() > 1)
        curIndex = 1;
    else curIndex = 0;
    update();
 }

void Button::leaveEvent(QEvent *event)
{
    curIndex = 0;
    update();
}

QSize Button::sizeHint() const
{
    return QSize(pixmatpList[0].width(), pixmatpList[0].height());
}


