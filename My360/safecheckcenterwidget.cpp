#include "safecheckcenterwidget.h"
#include <lowertopwidget.h>
#include <lowerbottomwidget.h>
#include <lowersafecheckbutton.h>

SafeCheckCenterWidget::SafeCheckCenterWidget(QWidget *parent):
AbsLowerCenterWidget(parent)
{
    InitUi();
}

void SafeCheckCenterWidget::InitUi()
{
    TopWidget = new LowerTopWidget(":/background/safelogo.png",
                                   ":/background/start_btn.png",4, 1,tr("安全扫描"),
                                   tr("谢谢使用"), this);

    BottomWidget = LowerBottomWidget::factory(LowerBottomWidget::safe, this);

    layout = new QVBoxLayout;
    layout->addWidget(TopWidget, 150);
    layout->addWidget(BottomWidget, 450);
    layout->setMargin(0);
    layout->setSpacing(0);
    setLayout(layout);

    resize(900, 600);
}
