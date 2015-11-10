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

    safeCheckBtn = new Button(":/background/safe_check.png", 4, this);
    cleanBtn = new Button(":/background/clean.png", 4, this);
    optimizeBtn = new Button(":/background/youhua.png", 4, this);

    layout = new QHBoxLayout;
    layout->addWidget(safeCheckBtn, 0, Qt::AlignVCenter	);
    layout->addWidget(cleanBtn, 0, Qt::AlignVCenter);
    layout->addWidget(optimizeBtn, 0, Qt::AlignVCenter	);
    layout->addStretch(10);

    setLayout(layout);
}

QSize bottomBaseWidget::sizeHint() const
{
    return QSize(900, 150);
}
