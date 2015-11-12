#include "cleancenterwidget.h"
#include <lowertopwidget.h>
#include <lowerbottomwidget.h>

CleanCenterWidget::CleanCenterWidget(QWidget *parent):
    AbsLowerCenterWidget(parent)
{
    InitUi();
}

void CleanCenterWidget::InitUi()
{
    TopWidget = new LowerTopWidget(":/background/cleanlogo.png",
                                    ":/background/btn_top_scan.png",4, 1,tr("已选择6项清理类型"),
                                    tr("经常清理，让电脑保持最佳状态"), this);

     BottomWidget = new LowerBottomWidget(this);

     layout = new QVBoxLayout;
     layout->addWidget(TopWidget, 150);
     layout->addWidget(BottomWidget, 450);
     layout->setMargin(0);
     layout->setSpacing(0);
     setLayout(layout);

     resize(900, 600);

}
