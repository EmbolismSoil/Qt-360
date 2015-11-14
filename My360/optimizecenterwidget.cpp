#include "optimizecenterwidget.h"
#include <lowerbottomwidget.h>
#include <lowertopwidget.h>
#include <QFont>
#include <QPalette>
#include <QLabel>
#include <lowerspeedbutton.h>

OptimizeCenterWidget::OptimizeCenterWidget(QWidget *parent):
    AbsLowerCenterWidget(parent)
{
    InitUi();
}

void OptimizeCenterWidget::InitUi()
{

    TopWidget = new LowerTopWidget(":/background/speedlogo.png",
                                   ":/background/btn_start_scan.png",4, 1,tr("一键优化，让电脑快如闪电"),
                                   tr("全面提高电脑开机速度、系统速度、上网速度、硬盘速度"), this);

    layout = new QVBoxLayout;

    BottomWidget = LowerBottomWidget::factory(LowerBottomWidget::speed);

    layout->addWidget(TopWidget, 150);
    layout->addWidget(BottomWidget, 450);
    layout->setMargin(0);
    layout->setSpacing(0);
    setLayout(layout);

    resize(900, 600);
}
