#include "lowerbottomwidget.h"
#include <QFont>
#include <QPalette>
#include <QLabel>
#include <lowerspeedbutton.h>
#include <lowersafecheckbutton.h>
#include <QLabel>
#include <buttonwithname.h>
#include <QHBoxLayout>

LowerBottomWidget::LowerBottomWidget(QWidget *parent) :
    QWidget(parent)
{
    setAutoFillBackground(true);
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QColor(255,255,255));
    this->setPalette(palette);

    Layout = new QVBoxLayout(this);
}

LowerBottomWidget *LowerBottomWidget::factory(LowerBottomWidget::widgetT Type, QWidget *parent)
{
        LowerBottomWidget *BottomWidget;
    if (Type == speed){
        BottomWidget = new LowerBottomWidget(parent);

        lowerSpeedButton *btnstart = lowerSpeedButton::factory(1, BottomWidget);
        lowerSpeedButton *btnsys = lowerSpeedButton::factory(2, BottomWidget);
        lowerSpeedButton *btnnet = lowerSpeedButton::factory(3, BottomWidget);
        lowerSpeedButton *btndisk = lowerSpeedButton::factory(4, BottomWidget);

        QFont ft;
        ft.setPointSize(15);
        ft.setBold(true);
        QPalette palette;
        palette.setColor(QPalette::WindowText, Qt::black);
        QLabel *startTopLabel = new QLabel(tr("开机加速"), parent);
        QLabel *sysTopLabel = new QLabel(tr("系统加速"), parent);
        QLabel *netTopLabel = new QLabel(tr("网络加速"), parent);
        QLabel *diskTopLabel = new QLabel(tr("硬盘加速"), parent);
        startTopLabel->setFont(ft);
        startTopLabel->setPalette(palette);
        sysTopLabel->setFont(ft);
        sysTopLabel->setPalette(palette);
        netTopLabel->setFont(ft);
        netTopLabel->setPalette(palette);
        diskTopLabel->setFont(ft);
        diskTopLabel->setPalette(palette);

        ft.setPointSize(11);
        ft.setBold(false);
        palette.setColor(QPalette::WindowText, Qt::gray);
        QLabel *startBtmLabel = new QLabel(tr("优化软件自动启动状态"), parent);
        QLabel *sysBtmLabel = new QLabel(tr("优化系统与内存设置"), parent);
        QLabel *netBtmLabel = new QLabel(tr("优化网络配置与性能"), parent);
        QLabel *diskBtmLabel = new QLabel(tr("优化硬盘传输速率"), parent);
        startBtmLabel->setFont(ft);
        startBtmLabel->setPalette(palette);
        sysBtmLabel->setFont(ft);
        sysBtmLabel->setPalette(palette);
        netBtmLabel->setFont(ft);
        netBtmLabel->setPalette(palette);
        diskBtmLabel->setFont(ft);
        diskBtmLabel->setPalette(palette);

        int spacing(5);
        QVBoxLayout *startLayout = new QVBoxLayout;
        startLayout->addWidget(btnstart, 0, Qt::AlignHCenter);
        startLayout->addWidget(startTopLabel, 0, Qt::AlignHCenter);
        startLayout->addWidget(startBtmLabel, 0, Qt::AlignHCenter);
        startLayout->setSpacing(spacing);
        startLayout->setMargin(0);

        QVBoxLayout *systLayout = new QVBoxLayout;
        systLayout->addWidget(btnsys, 0, Qt::AlignHCenter);
        systLayout->addWidget(sysTopLabel, 0, Qt::AlignHCenter);
        systLayout->addWidget(sysBtmLabel, 0, Qt::AlignHCenter);
        systLayout->setSpacing(spacing);
        systLayout->setMargin(0);

        QVBoxLayout *netLayout = new QVBoxLayout;
        netLayout->addWidget(btnnet, 0,  Qt::AlignHCenter);
        netLayout->addWidget(netTopLabel, 0,  Qt::AlignHCenter);
        netLayout->addWidget(netBtmLabel, 0,  Qt::AlignHCenter);
        netLayout->setSpacing(spacing);
        netLayout->setMargin(0);

        QVBoxLayout *diskLayout = new QVBoxLayout;
        diskLayout->addWidget(btndisk, 0,  Qt::AlignHCenter);
        diskLayout->addWidget(diskTopLabel, 0,  Qt::AlignHCenter);
        diskLayout->addWidget(diskBtmLabel, 0,  Qt::AlignHCenter);
        diskLayout->setSpacing(spacing);
        diskLayout->setMargin(0);

        QVBoxLayout *btnlayout = new QVBoxLayout;
        QHBoxLayout *hbtnlayout = new QHBoxLayout;
        hbtnlayout->addStretch(10);
        hbtnlayout->addLayout(startLayout, 0);
        hbtnlayout->addLayout(systLayout, 0);
        hbtnlayout->addLayout(netLayout, 0);
        hbtnlayout->addLayout(diskLayout, 0);
        hbtnlayout->addStretch(10);
        hbtnlayout->setSpacing(70);
        hbtnlayout->setContentsMargins(0, 10, 0, 0);

        btnlayout->addStretch(10);
        btnlayout->addLayout(hbtnlayout, 0);
        btnlayout->addStretch(10);
        BottomWidget->InsertLayout(btnlayout, 0, 0);
    }else if (Type == safe){
        BottomWidget = new LowerBottomWidget(parent);
        lowerSafeCheckButton *scan_custom =
                new lowerSafeCheckButton(":/background/scan_button_custom.png"
                                                           ,":/background/scan_button_custom_hover.png",
                                                            BottomWidget);
        lowerSafeCheckButton *scan_full =
                new lowerSafeCheckButton(":/background/scan_button_full.png"
                                                           ,":/background/scan_button_full_hover.png",
                                                            BottomWidget);
        lowerSafeCheckButton *scan_quick =
                new lowerSafeCheckButton(":/background/scan_button_quick.png"
                                                           ,":/background/scan_button_quick_hover.png",
                                                            BottomWidget);

        QFont ft;
        ft.setPointSize(11);
        QLabel *customLabel = new QLabel(tr("自定义扫描"), parent);
        QLabel *quickLabel = new QLabel(tr("快速扫描"), parent);
        QLabel *fullLabel = new QLabel(tr("全盘扫描"), parent);
        customLabel->setFont(ft);
        quickLabel->setFont(ft);
        fullLabel->setFont(ft);

        int spacing  = 20;
        QVBoxLayout *customLayout = new QVBoxLayout;
        QVBoxLayout *quickLayout = new QVBoxLayout;
        QVBoxLayout *fullLayout = new QVBoxLayout;
        customLayout->addWidget(scan_custom, 0, Qt::AlignHCenter);
        customLayout->addWidget(customLabel, 0, Qt::AlignHCenter);
        customLayout->setSpacing(spacing);
        customLayout->setMargin(0);
        quickLayout->addWidget(scan_quick, 0, Qt::AlignHCenter);
        quickLayout->addWidget(quickLabel, 0, Qt::AlignHCenter);
        quickLayout->setSpacing(spacing);
        quickLayout->setMargin(0);
        fullLayout->addWidget(scan_full, 0, Qt::AlignHCenter);
        fullLayout->addWidget(fullLabel, 0, Qt::AlignHCenter);
        fullLayout->setSpacing(spacing);
        fullLayout->setMargin(0);

        QVBoxLayout *vbtmLayout = new QVBoxLayout;
        QHBoxLayout *hbtmlayout = new QHBoxLayout;

        hbtmlayout->addStretch(10);
        hbtmlayout->addLayout(quickLayout,0);
        hbtmlayout->addLayout(fullLayout, 0);
        hbtmlayout->addLayout(customLayout, 0);
        hbtmlayout->addStretch(10);
        hbtmlayout->setSpacing(150);
        hbtmlayout->setMargin(0);
        vbtmLayout->addStretch(10);
        vbtmLayout->addLayout(hbtmlayout, 0);
        vbtmLayout->addStretch(10);
        vbtmLayout->setSpacing(0);
        vbtmLayout->setMargin(0);

        ButtonWithName *fixBtn = new ButtonWithName(":/background/system_fix.png",
                                                                                                    4, parent, 1,  tr("常规修复"));
        ButtonWithName  *patchBtn = new ButtonWithName(":/background/system_patch.png",
                                                                                                    4, parent, 1, tr("漏洞修复"));
        fixBtn->setSpacing(10);
        patchBtn->setSpacing(10);

       QHBoxLayout *BtnLayout = new QHBoxLayout;
       BtnLayout->addStretch(10);
       BtnLayout->addWidget(fixBtn, 0);
       BtnLayout->addWidget(patchBtn, 0);
       BtnLayout->setSpacing(10);
       BtnLayout->setContentsMargins(0, 0, 0, 23);

        BottomWidget->addStretch(10);
        BottomWidget->InsertLayout(vbtmLayout, 1, 0);
        BottomWidget->InsertLayout(BtnLayout, 2, 0);
    }

    return BottomWidget;
}

