#include "buttonwithname.h"
#include <QVBoxLayout>
#include <QPainter>
#include <QPaintEvent>
#include <common.h>

ButtonWithName::ButtonWithName(QString FileName, int xnum, QWidget *parent, int ynum, QString name):
   QWidget(parent),
   nameLabel (new QLabel(name, this)),
   Btn(new Button(FileName, xnum, this, ynum)),
   font(new QFont),
    layout(new QVBoxLayout),
     m_isEnter(false)
{
        layout->addWidget(&(*Btn), 0,  Qt::AlignHCenter);
        if (name != 0){
            font->setPointSize(11);
            nameLabel->setFont(*font);
            layout->addWidget(&(*nameLabel), 0, Qt::AlignHCenter);
        }

        layout->setSpacing(0);
        layout->setContentsMargins(0, 9, 0, 0);
        setLayout(&(*layout));
}

void ButtonWithName::SetBackGround(QString path, int xnum, int ynum)
{
    QPixmap pixmap(path);

    for (int cnt = 0; cnt < xnum; ++cnt){
        for (int y = 0; y < ynum; ++ y){
            backGd.push_back( pixmap.copy(cnt * (pixmap.width() / xnum),  y * (pixmap.height() / ynum),
                                           pixmap.width() / xnum , pixmap.height() / ynum));
        }
    }
}

void ButtonWithName::paintEvent(QPaintEvent *event)
{
    if (backGd.size() <= 0) return;

    QPainter painter(this);
    if (m_isEnter && backGd.size() > 2)
        painter.drawPixmap(event->rect(), backGd[1]);
    else if (!m_isEnter && backGd.size() > 1)
        painter.drawPixmap(event->rect(), backGd[0]);
}
void ButtonWithName::enterEvent(QEvent *event)
{
  __UNUSED(event);
    m_isEnter = true;
    update();
}

void ButtonWithName::leaveEvent(QEvent *event)
{
    __UNUSED(event);
    m_isEnter = false;
    update();
}

QSize ButtonWithName::sizeHint() const
{
    if (backGd.size() > 0)
        return QSize(backGd[0].width(), backGd[1].height());
    else return QWidget::sizeHint();
}
