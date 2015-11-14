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

    BottomWidget = new LowerBottomWidget(this);
    lowerSafeCheckButton *scan_custom =
            new lowerSafeCheckButton(":/background/scan_button_custom.png"
                                                       ,":/background/scan_button_custom_hover.png",
                                                        BottomWidget);
    QVBoxLayout *vbtmLayout = new QVBoxLayout;
    QHBoxLayout *hbtmlayout = new QHBoxLayout;

    hbtmlayout->addStretch(10);
    hbtmlayout->addWidget(scan_custom, 0);
    hbtmlayout->addStretch(10);
    hbtmlayout->setSpacing(0);
    hbtmlayout->setMargin(0);
    vbtmLayout->addStretch(10);
    vbtmLayout->addLayout(hbtmlayout, 0);
    vbtmLayout->addStretch(10);
    vbtmLayout->setSpacing(0);
    vbtmLayout->setMargin(0);
    BottomWidget->InsertLayout(vbtmLayout, 0, 0);

    layout = new QVBoxLayout;
    layout->addWidget(TopWidget, 150);
    layout->addWidget(BottomWidget, 450);
    layout->setMargin(0);
    layout->setSpacing(0);
    setLayout(layout);

    resize(900, 600);
}
