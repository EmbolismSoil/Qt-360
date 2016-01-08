#include "bottomwidget.h"
#include <QPainter>
#include <QPaintEvent>
#include <QLabel>
#include <buttonwithname.h>

bottomBaseWidget::bottomBaseWidget( QWidget *parent) :
    QWidget(parent), m_isOut(false)
{
    InitUi();
    InitAnimation();
    InitConnect();
}

bottomBaseWidget::~bottomBaseWidget()
{
    delete optimizeBtn;
    delete safeCheckBtn;
    delete cleanBtn;
    delete softMngBtn;
    delete humanSvrBtn;
    delete mobileBtn;
    delete speedBtn;
    delete moreBtn;
    delete routerBtn;
    delete layout;
    delete outAnimation;
    delete inAnimation;
    delete outOpacityAnimation;
    delete inOpacityAnimation;
    delete inGroup;
    delete outGroup;
    delete Effect;
}

void bottomBaseWidget::startAnimation()
{
    if (m_isOut){
      inGroup->start();
         m_isOut = false;
    }else{
        outGroup->start();
        m_isOut = true;
    }
}

void bottomBaseWidget::InitUi()
{
    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    setAutoFillBackground(true);
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QColor(255,255,255));
    this->setPalette(palette);

    safeCheckBtn = new ButtonWithName(":/background/safe_check.png", 4,  this, 1, tr("查杀修复"));
    cleanBtn = new ButtonWithName(":/background/clean.png", 4, this, 1, tr("电脑清理"));
    optimizeBtn = new ButtonWithName(":/background/youhua.png", 4, this, 1, tr("优化加速"));


    softMngBtn = new ButtonWithName(":/background/AdvanceTools_360SoftManger_10_32.png", 1, this, 1, tr("软件管家"));
    humanSvrBtn = new ButtonWithName(":/background/360JiShi_10_32.png", 1, this, 1, tr("人工服务"));
    mobileBtn = new ButtonWithName(":/background/AdvanceTools_360MobileMgr_10_32.png", 1, this, 1, tr("手机助手"));
    speedBtn = new ButtonWithName(":/background/AdvanceTools_NetSpeed_10_32.png", 1, this, 1, tr("宽带测速器"));
    moreBtn = new ButtonWithName(":/background/advtool_more.png", 4, this);
    routerBtn = new Button(":/background/routerdefender.png", 4, this);

    int space = 0;
    softMngBtn->setSpacing(space);
    humanSvrBtn->setSpacing(space);
    mobileBtn->setSpacing(space);
    speedBtn->setSpacing(space);

    softMngBtn->setFontSize(9);
    humanSvrBtn->setFontSize(9);
    mobileBtn->setFontSize(9);
    speedBtn->setFontSize(9);

    softMngBtn->SetBackGround(":/background/short_cut_bkg.png", 3, 1);
    humanSvrBtn->SetBackGround(":/background/short_cut_bkg.png", 3, 1);
    mobileBtn->SetBackGround(":/background/short_cut_bkg.png", 3, 1);
    speedBtn->SetBackGround(":/background/short_cut_bkg.png", 3, 1);


    QFont ft;
    QLabel *moreLabel = new QLabel(tr("更多"), this);
    QVBoxLayout *moreLayout = new QVBoxLayout;
    ft.setPointSize(11);
    moreLabel->setFont(ft);

    palette.setColor(QPalette::WindowText, Qt::blue);
    moreLabel->setPalette(palette);

    moreLayout->addWidget(moreBtn, 0);
    moreLayout->addWidget(moreLabel, 0, Qt::AlignHCenter);
    moreLayout->setSpacing(12);
    moreLayout->setMargin(0);

    QLabel *routerLabel1 = new QLabel(tr("路由器卫士"), this);
    QLabel *routerLabel2 = new QLabel(tr("帮您免费升级为智能路由器"), this);
    ft.setPointSize(11);
    routerLabel2->setFont(ft);
    ft.setBold(true);
    ft.setPointSize(12);
    routerLabel1->setFont(ft);

    QVBoxLayout *labelLayout = new  QVBoxLayout;
    labelLayout->addWidget(routerLabel1, 0, Qt::AlignRight);
    labelLayout->addWidget(routerLabel2, 0, Qt::AlignRight);
    labelLayout->setSpacing(5);
    labelLayout->setMargin(0);

    QHBoxLayout *routerLayout = new QHBoxLayout;
    routerLayout->addLayout(labelLayout, 0);
    routerLayout->addWidget(routerBtn);
    routerLayout->setSpacing(10);
    routerLayout->setMargin(0);

    QHBoxLayout *advtoolLayout = new QHBoxLayout;
    advtoolLayout->addWidget(softMngBtn, 0, Qt::AlignBottom);
    advtoolLayout->addWidget(humanSvrBtn, 0, Qt::AlignBottom);
    advtoolLayout->addWidget(mobileBtn, 0, Qt::AlignBottom);
    advtoolLayout->addWidget(speedBtn, 0, Qt::AlignBottom);
    advtoolLayout->addLayout(moreLayout, 0);
    advtoolLayout->setSpacing(5);
    advtoolLayout->setMargin(0);

    QVBoxLayout *toolLayout  = new QVBoxLayout;
    toolLayout->addLayout(routerLayout, 0);
    toolLayout->addStretch(15);
    toolLayout->addLayout(advtoolLayout, 0);
    toolLayout->setSpacing(0);
    toolLayout->setContentsMargins(0, 10, 0, 5);

    layout = new QHBoxLayout;
    layout->addWidget(safeCheckBtn, 0, Qt::AlignVCenter	);
    layout->addWidget(cleanBtn, 0, Qt::AlignVCenter);
    layout->addWidget(optimizeBtn, 0, Qt::AlignVCenter	);
    layout->addStretch(10);
    layout->addLayout(toolLayout, 0);

    setLayout(layout);
}

void bottomBaseWidget::InitAnimation()
{
        Effect = new QGraphicsOpacityEffect;
        Effect->setOpacity(1);
        this->setGraphicsEffect(Effect);

        outAnimation = new QPropertyAnimation(this, "AnimationPos");
        outAnimation->setStartValue(QPoint(0, 440));
        outAnimation->setEndValue(QPoint(0, 600));
        outAnimation->setDuration(400);

        inAnimation = new QPropertyAnimation(this, "AnimationPos");
        inAnimation->setStartValue(QPoint(0, 600));
        inAnimation->setEndValue(QPoint(0, 440));
        inAnimation->setDuration(400);


        outOpacityAnimation = new QPropertyAnimation(this, "Opacity");
        outOpacityAnimation->setStartValue(1);
        outOpacityAnimation->setEndValue(0);
        outOpacityAnimation->setDuration(400);

        inOpacityAnimation = new QPropertyAnimation(this, "Opacity");
        inOpacityAnimation->setStartValue(0);
        inOpacityAnimation->setEndValue(1);
        inOpacityAnimation->setDuration(400);

        inGroup = new QParallelAnimationGroup;
        outGroup = new QParallelAnimationGroup;

        inGroup->addAnimation(inAnimation);
        inGroup->addAnimation(inOpacityAnimation);
        outGroup->addAnimation(outAnimation);
        outGroup->addAnimation(outOpacityAnimation);
}

void bottomBaseWidget::InitConnect()
{
    connect(inAnimation, SIGNAL(valueChanged(QVariant)), this, SLOT(update()));
    connect(outAnimation, SIGNAL(valueChanged(QVariant)), this, SLOT(update()));
}

