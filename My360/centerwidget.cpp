#include "centerwidget.h"
#include <QPalette>

CenterWidget::CenterWidget(QWidget *parent) :
    QWidget(parent)
{
    //topWidget = new TopBaseWidget;
    //bottomWidget = new bottomBaseWidget;

    TopLayer = qMakePair(new TopBaseWidget(this), new bottomBaseWidget(this));
    layout = new QVBoxLayout;
    layout->addWidget(TopLayer.first, 440);
    layout->addWidget(TopLayer.second, 160);

    layout->setSpacing(0);
    layout->setMargin(0);

    setLayout(layout);

    connect(TopLayer.first->getTitleBar()->getCloseBtn(),
            SIGNAL(clicked()), this, SLOT(closeClicked()));
}

void CenterWidget::closeClicked()
{
    emit closeBtnClicked();
}
