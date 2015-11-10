#include "centerwidget.h"
#include <QPalette>

CenterWidget::CenterWidget(QWidget *parent) :
    QWidget(parent)
{
    topWidget = new TopBaseWidget;
    bottomWidget = new bottomBaseWidget;

    layout = new QVBoxLayout;
    layout->addWidget(topWidget, 440);
    layout->addWidget(bottomWidget, 160);

    layout->setSpacing(0);
    layout->setMargin(0);

    setLayout(layout);

    connect(topWidget->getTitleBar()->getCloseBtn(),
            SIGNAL(clicked()), this, SLOT(closeClicked()));
}

void CenterWidget::closeClicked()
{
    emit closeBtnClicked();
}
