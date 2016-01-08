#include "nunberwidget.h"
#include <QPixmap>
#include <QPaintEvent>
#include <QPainter>

NunberWidget::NunberWidget(QWidget *parent) :
    QWidget(parent)
{
    for (int cnt = 0; cnt < 10; cnt++){
        QString path =QString(":/background/tijian_score/%1.png").arg(QString::number(cnt, 10));
        pixmapVec.push_back(QPixmap(path));
    }

    background = new QPixmap(":/background/tijian_score/examine_score.png");
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

NunberWidget::~NunberWidget()
{
    delete background;
}

void NunberWidget::setNum(int num)
{
        num > 99 ? num = 99 : num ;
        index.clear();

        if (num >= 10){
            index.push_back(num/10);
            index.push_back(num % 10);
        }else{
            index.push_back(num);
        }
}

void NunberWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect rect = event->rect();

    if (index.isEmpty()) return;

     painter.drawPixmap(rect.x(), rect.y(), *background);
     int x = rect.x() + (background->width() - pixmapVec[0].width()) / 2;
     int y = rect.y() + (background->height() - pixmapVec[0].height()) / 2;

    if (index.size() < 2){
        painter.drawPixmap(x, y, pixmapVec[index[0]]);
    }else{
       x = rect.x() + (background->width() - 2*pixmapVec[0].width()) / 2;
       y = rect.y() + (background->height() - pixmapVec[0].height()) / 2;
       painter.drawPixmap(x, y, pixmapVec[index[0]]);
       x += pixmapVec[0].width();
       painter.drawPixmap(x, y, pixmapVec[index[1]]);
    }

}

QSize NunberWidget::sizeHint() const
{
    return QSize(background->width(), background->height());
}
