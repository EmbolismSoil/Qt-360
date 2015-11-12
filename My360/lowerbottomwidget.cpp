#include "lowerbottomwidget.h"

LowerBottomWidget::LowerBottomWidget(QWidget *parent) :
    QWidget(parent)
{
    setAutoFillBackground(true);
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QColor(255,255,255));
    this->setPalette(palette);

}

