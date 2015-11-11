#include "centerwidget.h"
#include <QPalette>
#include <QStateMachine>
#include <QState>
#include <QPropertyAnimation>
#include <bottomwidget.h>
#include <QSignalTransition>

CenterWidget::CenterWidget(QWidget *parent) :
    QWidget(parent)
{
    topWidget = new TopBaseWidget(this);
    bottomWidget = new bottomBaseWidget(this);

    topWidget->resize(900, 440);
    bottomWidget->resize(900, 160);
    bottomWidget->move(0, 440);
    //layout = new QVBoxLayout;
    //layout->addWidget(topWidget, 440);
    //layout->addWidget(bottomWidget, 160);

    //layout->setSpacing(0);
    //layout->setMargin(0);

   // setLayout(layout);

    connect(bottomWidget->getOptimizeBtn()->getButton(), SIGNAL(clicked()),
            topWidget, SLOT(startAnimation()));
    connect(topWidget->getTitleBar()->getCloseBtn(),
            SIGNAL(clicked()), this, SLOT(closeClicked()));
}

void CenterWidget::closeClicked()
{
    emit closeBtnClicked();
}


void CenterWidget::InitAnimation()
{
    QStateMachine *topMoveMach = new QStateMachine(topWidget);
    QState *topMoveStart = new QState(topMoveMach);
    QState *topMoveEnd = new QState(topMoveMach);

    topMoveStart->assignProperty(topWidget, "AnimationPos",
                                 QPointF(0, 0));
    topMoveEnd->assignProperty(topWidget, "AnimationPos", QPointF(100, 100));

    topMoveMach->setInitialState(topMoveStart);
    QSignalTransition *trans =
            topMoveStart->addTransition(bottomWidget->getOptimizeBtn()->getButton(),
                                        SIGNAL(clicked()), topMoveEnd);
    QPropertyAnimation *topMoveAnimation = new QPropertyAnimation(topWidget, "AnimationPos");
    topMoveAnimation->setDuration(1000);
    trans->addAnimation(topMoveAnimation);

    topMoveMach->start();
}
