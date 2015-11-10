#include "bottomwidget.h"
#include <QPainter>
#include <QPaintEvent>

bottomBaseWidget::bottomBaseWidget( QWidget *parent) :
    QWidget(parent)
{
    setAutoFillBackground(true);
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QColor(255,255,255));
    this->setPalette(palette);
}

QSize bottomBaseWidget::sizeHint() const
{
    return QSize(900, 150);
}
