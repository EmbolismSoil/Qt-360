#include "titlebar.h"
#include <QLabel>

titleBar::titleBar(QWidget *parent) :
    QWidget(parent)
{
    closeBtn = new Button(":/background/sys_button_close.png", 4, this);
    minimizeBtn =new Button(":/background/min.png", 4, this);
    menuBtn = new Button(":/background/Menu.png", 4, this);
    skinBtn = new Button(":/background/Skin.png", 4, this);
    videoBtn = new Button(":/background/playvideo.png", 4, this);

    WidgetLayoutInit();
}

void titleBar::InsertUserLayout(QLayout *UserLayout, int pos, int stretch)
{
    layout->insertLayout(pos, UserLayout, stretch);
}

void titleBar::WidgetLayoutInit()
{
    layout = new QHBoxLayout;

     QVBoxLayout *Toolvlayout = new QVBoxLayout;
     QHBoxLayout *Toolhlayout  = new QHBoxLayout;

    Toolhlayout->addStretch(10);
    Toolhlayout->addWidget(videoBtn, 0);
    Toolhlayout->addWidget(skinBtn, 0);
    Toolhlayout->addWidget(menuBtn, 0);
    Toolhlayout->addWidget(minimizeBtn, 0);
    Toolhlayout->addWidget(closeBtn, 0);
    Toolhlayout->setSpacing(0);
    Toolhlayout->setMargin(0);

    Toolvlayout->addLayout(Toolhlayout, 3);
    Toolvlayout->addStretch(1);
    Toolvlayout->setSpacing(0);
    Toolvlayout->setMargin(0);

    layout->addStretch(10);
    layout->addLayout(Toolvlayout, 0);

    layout->setSpacing(0);
    //layout->setMargin(0);
    layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);
}

#if 0
void titleBar::UserLayoutInit()
{
    logo = new Button(":/background/360logo.png", 1, this);
    updateBtn = new Button(":/background/update_btn.png", 4 , this);

    QLabel* text = new QLabel(tr("360安全管家 10.0 Beta"));
    QHBoxLayout *hlayout = new QHBoxLayout;
    QVBoxLayout *vlayout = new QVBoxLayout;

    hlayout->addWidget(logo, 0);
    hlayout->addWidget(text, 0);
    hlayout->addWidget(updateBtn, 0);
    hlayout->addStretch(10);
    hlayout->setSpacing(6);
    hlayout->setMargin(0);
    vlayout->addLayout(hlayout, 3);
    vlayout->setSpacing(0);
    vlayout->setContentsMargins(10, 10, 0, 0);

    layout->insertLayout(0, vlayout, 0);
    //layout->addLayout(vlayout, 0);
}
#endif
