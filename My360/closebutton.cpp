#include "closebutton.h"
#include <QPainter>
#include <QPaintEvent>
#include <QPixmap>


Button::Button( QString FileName, int num , QWidget *parent, int ynum):
    QPushButton(parent)
{
    QPixmap pixmap(FileName);
    for (int cnt = 0; cnt < num; ++cnt){
        for (int y = 0; y < ynum; ++ y){
            pixmatpList.push_back( pixmap.copy(cnt * (pixmap.width() / num),  y * (pixmap.height() / ynum),
                                           pixmap.width() / num , pixmap.height() / ynum));
        }
    }

    setSizePolicy(QSizePolicy::Fixed	, QSizePolicy::Fixed	);
    //resize(pixmap.width() / num + 1, pixmap.height() + 1);
    curIndex = 0;
}

Button::Button(QVector<QString> &list, QWidget *parent):QPushButton(parent)
{
    setPixmapList(list);
    setSizePolicy(QSizePolicy::Fixed	, QSizePolicy::Fixed	);
    //resize(pixmap.width() / num + 1, pixmap.height() + 1);
    curIndex = 0;
}

void Button::setPixmapList(QVector<QString> &list)
{
    if (list.size() <= 0) return;
    pixmatpList.clear();

    for (QVector<QString>::iterator pos = list.begin();
             pos != list.end(); ++pos){
        pixmatpList.push_back(QPixmap(*pos));
    }
}


 void Button::paintEvent ( QPaintEvent * event)
 {
     QPainter painter(this);

     QRect rect = event->rect();
     painter.drawPixmap(event->rect(), pixmatpList[curIndex]);
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

void Button::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton){
        if (pixmatpList.size() > 2){
            curIndex = 2;
             update();
        }
    }
    QPushButton::mousePressEvent(event);
}

void Button::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton){
        if (pixmatpList.size() > 1){
            curIndex = 1;
             update();
        }
    }
    QPushButton::mouseReleaseEvent(event);
}



QSize Button::sizeHint() const
{
    return QSize(pixmatpList[0].width(), pixmatpList[0].height());
}


