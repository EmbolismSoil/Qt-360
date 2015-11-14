#include "lowerspeedbutton.h"
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>
#include <QDebug>
#include <QCheckBox>
#include <QPushButton>

lowerSpeedButton::lowerSpeedButton(QVector<QPixmap> &colorpixmap,
                                   QVector<QPixmap> &graypixmap, QWidget *parent):
        QPushButton(parent)
{
    colorPixmap = colorpixmap;
    grayPixmap = graypixmap;

    curPixmap = &colorPixmap;
    curIndex = 0;

    connect(this, SIGNAL(clicked()), this, SLOT(sChanged()));
}

lowerSpeedButton *lowerSpeedButton::factory(int index, QWidget *parent)
{
    QVector<QPixmap> colorpixmap;
    QVector<QPixmap> graypixmap;

    if (index == 1){
           QPixmap fgpixmap(":/background/start_check.png");
           QPixmap bgpixmap(":/background/cat_hover.png");
           QPixmap grayfg(":/background/start_uncheck.png");
           QPixmap graybg(":/background/cat_gray_hover.png");
            QPixmap ckpixmap(":/background/cat_checkbox.png");

           QVector<QPixmap> CKPixmap;

           for (int cnt = 0; cnt < 12; cnt ++)
               CKPixmap.push_back(ckpixmap.copy(cnt * ckpixmap.width() / 12, 0,
                                                ckpixmap.width() / 12, ckpixmap.height()));

           int x = fgpixmap.width() - CKPixmap[0].width() - 14;
           int y = fgpixmap.height() - CKPixmap[0].height() - 14;

           QPainter normalPainter(&fgpixmap);
           normalPainter.drawPixmap(x, y, CKPixmap[4]);
            colorpixmap.push_back(fgpixmap);
            QPainter painter(&bgpixmap);
            painter.drawPixmap(0, 0, fgpixmap);
            painter.drawPixmap(x, y, CKPixmap[5]);
            colorpixmap.push_back(bgpixmap);

            QPainter graynormalPainter(&grayfg);
            graynormalPainter.drawPixmap(x, y, CKPixmap[0]);
            graypixmap.push_back(grayfg);
            QPainter grayPainter(&graybg);
            grayPainter.drawPixmap(0, 0, grayfg);
            grayPainter.drawPixmap(x, y, CKPixmap[1]);
            graypixmap.push_back(graybg);

            return new lowerSpeedButton(colorpixmap, graypixmap, parent);
     }else if (index == 2){
        QPixmap fgpixmap(":/background/sys_check.png");
        QPixmap bgpixmap(":/background/cat_hover.png");
        QPixmap grayfg(":/background/sys_uncheck.png");
        QPixmap graybg(":/background/cat_gray_hover.png");
         QPixmap ckpixmap(":/background/cat_checkbox.png");

        QVector<QPixmap> CKPixmap;

        for (int cnt = 0; cnt < 12; cnt ++)
            CKPixmap.push_back(ckpixmap.copy(cnt * ckpixmap.width() / 12, 0,
                                             ckpixmap.width() / 12, ckpixmap.height()));

        int x = fgpixmap.width() - CKPixmap[0].width() - 14;
        int y = fgpixmap.height() - CKPixmap[0].height() - 14;

        QPainter normalPainter(&fgpixmap);
        normalPainter.drawPixmap(x, y, CKPixmap[4]);
         colorpixmap.push_back(fgpixmap);
         QPainter painter(&bgpixmap);
         painter.drawPixmap(0, 0, fgpixmap);
         painter.drawPixmap(x, y, CKPixmap[5]);
         colorpixmap.push_back(bgpixmap);

         QPainter graynormalPainter(&grayfg);
         graynormalPainter.drawPixmap(x, y, CKPixmap[0]);
         graypixmap.push_back(grayfg);
         QPainter grayPainter(&graybg);
         grayPainter.drawPixmap(0, 0, grayfg);
         grayPainter.drawPixmap(x, y, CKPixmap[1]);
         graypixmap.push_back(graybg);

         return new lowerSpeedButton(colorpixmap, graypixmap, parent);
    }else if (index == 3){
        QPixmap fgpixmap(":/background/net_check.png");
        QPixmap bgpixmap(":/background/cat_hover.png");
        QPixmap grayfg(":/background/net_uncheck.png");
        QPixmap graybg(":/background/cat_gray_hover.png");
         QPixmap ckpixmap(":/background/cat_checkbox.png");

        QVector<QPixmap> CKPixmap;

        for (int cnt = 0; cnt < 12; cnt ++)
            CKPixmap.push_back(ckpixmap.copy(cnt * ckpixmap.width() / 12, 0,
                                             ckpixmap.width() / 12, ckpixmap.height()));

        int x = fgpixmap.width() - CKPixmap[0].width() - 14;
        int y = fgpixmap.height() - CKPixmap[0].height() - 14;

        QPainter normalPainter(&fgpixmap);
        normalPainter.drawPixmap(x, y, CKPixmap[4]);
         colorpixmap.push_back(fgpixmap);
         QPainter painter(&bgpixmap);
         painter.drawPixmap(0, 0, fgpixmap);
         painter.drawPixmap(x, y, CKPixmap[5]);
         colorpixmap.push_back(bgpixmap);

         QPainter graynormalPainter(&grayfg);
         graynormalPainter.drawPixmap(x, y, CKPixmap[0]);
         graypixmap.push_back(grayfg);
         QPainter grayPainter(&graybg);
         grayPainter.drawPixmap(0, 0, grayfg);
         grayPainter.drawPixmap(x, y, CKPixmap[1]);
         graypixmap.push_back(graybg);

         return new lowerSpeedButton(colorpixmap, graypixmap, parent);
    }else if (index == 4){
        QPixmap fgpixmap(":/background/disk_check.png");
        QPixmap bgpixmap(":/background/cat_hover.png");
        QPixmap grayfg(":/background/disk_uncheck.png");
        QPixmap graybg(":/background/cat_gray_hover.png");
         QPixmap ckpixmap(":/background/cat_checkbox.png");

        QVector<QPixmap> CKPixmap;

        for (int cnt = 0; cnt < 12; cnt ++)
            CKPixmap.push_back(ckpixmap.copy(cnt * ckpixmap.width() / 12, 0,
                                             ckpixmap.width() / 12, ckpixmap.height()));

        int x = fgpixmap.width() - CKPixmap[0].width() - 14;
        int y = fgpixmap.height() - CKPixmap[0].height() - 14;

        QPainter normalPainter(&fgpixmap);
        normalPainter.drawPixmap(x, y, CKPixmap[4]);
         colorpixmap.push_back(fgpixmap);
         QPainter painter(&bgpixmap);
         painter.drawPixmap(0, 0, fgpixmap);
         painter.drawPixmap(x, y, CKPixmap[5]);
         colorpixmap.push_back(bgpixmap);

         QPainter graynormalPainter(&grayfg);
         graynormalPainter.drawPixmap(x, y, CKPixmap[0]);
         graypixmap.push_back(grayfg);
         QPainter grayPainter(&graybg);
         grayPainter.drawPixmap(0, 0, grayfg);
         grayPainter.drawPixmap(x, y, CKPixmap[1]);
         graypixmap.push_back(graybg);

         return new lowerSpeedButton(colorpixmap, graypixmap, parent);
    }

    return NULL;
}

void lowerSpeedButton::sChanged()
{
    if (curPixmap == &grayPixmap)
        curPixmap = &colorPixmap;
    else curPixmap = &grayPixmap;
    update();
}

void lowerSpeedButton::paintEvent(QPaintEvent *event)
{
    //QPushButton::paintEvent(event);
    QPainter painter(this);
    painter.drawPixmap(event->rect(), (*curPixmap)[curIndex]);
}

void lowerSpeedButton::enterEvent(QEvent *event)
{
    QPushButton::enterEvent(event);
    curIndex = 1;
    update();
}

void lowerSpeedButton::leaveEvent(QEvent *event)
{
    QPushButton::leaveEvent(event);
    curIndex = 0;
    update();
}

QSize lowerSpeedButton::sizeHint() const
{
    if (colorPixmap.size() > 0)
        return QSize(colorPixmap[0].width(), colorPixmap[0].height());
    else if (grayPixmap.size() > 0)
        return QSize(grayPixmap[0].width(), grayPixmap[0].height());
    else  return QPushButton::sizeHint();
}
