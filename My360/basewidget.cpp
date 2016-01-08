#include "basewidget.h"
#include <QVBoxLayout>
#include <QLabel>
#include <nunberwidget.h>
#include <QFont>
#include <QPalette>
#include <QPainter>
#include <QPaintEvent>
#include <QPropertyAnimation>

TopBaseWidget::TopBaseWidget(QWidget *parent) :
    QWidget(parent),  backGround(NULL), m_isOut(false)
{
    IinitUi();
    IinitAnimatio();
    InitConnect();
}

TopBaseWidget::~TopBaseWidget()
{
    delete title;
    delete examineBtn;
    delete safeBtn;
    delete payinBtn;
    delete lineBtn;

    delete loginBtn;
    delete number;
    delete backGround;

    delete outAnimation;
    delete inAnimation;
     delete outOpacityAnimation;
    delete inOpacityAnimation;
    delete inGroup;
    delete outGroup;
    delete Effect;
}

void TopBaseWidget::startAnimation()
{
    if (m_isOut){
      inGroup->start();
         m_isOut = false;
    }else{
        outGroup->start();
        m_isOut = true;
    }
}

void TopBaseWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    if (backGround != NULL){
        QPainter painter(this);
        painter.drawPixmap(event->rect(), *backGround);
    }
}

void TopBaseWidget::IinitAnimatio()
{
    Effect = new QGraphicsOpacityEffect;
    Effect->setOpacity(1);
    this->setGraphicsEffect(Effect);

    outAnimation = new QPropertyAnimation(this, "AnimationPos");
    outAnimation->setStartValue(QPointF(0, 0));
    outAnimation->setEndValue(QPointF(0, -440));
    outAnimation->setDuration(400);

    inAnimation = new QPropertyAnimation(this, "AnimationPos");
    inAnimation->setStartValue(QPointF(0, -440));
    inAnimation->setEndValue(QPointF(0, 0));
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

void TopBaseWidget::IinitUi()
{
    //setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

  //  backGround = new QPixmap(":/background/wenli.png");

    setAutoFillBackground(true);
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QColor("#2ABF1D"));
    this->setPalette(palette);

   title = new titleBar(this);
   Button* logo = new Button(":/background/360logo.png", 1, title);
   Button* updateBtn = new Button(":/background/update_btn.png", 4 , title);
   QLabel* text = new QLabel(tr("360安全管家 10.0 Beta"), title);

   QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->addWidget(logo, 0);
    hlayout->addWidget(text, 0);
    hlayout->addWidget(updateBtn, 0);
    hlayout->setSpacing(6);
    hlayout->setContentsMargins(10, 10, 0, 0);
    title->InsertUserLayout(hlayout, 0, 0);

   loginBtn = new LoginButton(":/background/head_bkg.png", 2, this);

   QVBoxLayout *layout = new QVBoxLayout;

   QHBoxLayout *safeBtnLayout = new QHBoxLayout;
   QHBoxLayout *loginLayout = new QHBoxLayout;
   QHBoxLayout *numberLayout = new QHBoxLayout;
   QLabel *label = new QLabel(tr("建议体检"),this);
   QLabel *labelMin = new QLabel(tr("建议每天进行体检"),this);
   QFont ft;
   //QPalette palette;
   QVBoxLayout *labelLayout = new QVBoxLayout;

   examineBtn = new Button(":/background/btn_examine_now.png", 4, this);

   palette.setColor(QPalette::WindowText, Qt::white);

   ft.setPointSize(22);
   ft.setBold(true);
   label->setFont(ft);
   label->setPalette(palette);
   ft.setPointSize(11);
   ft.setBold(false);
   labelMin->setFont(ft);
   labelMin->setPalette(palette);

   labelLayout->addStretch(10);
   labelLayout->addWidget(label, 0, Qt::AlignHCenter);
   labelLayout->addWidget(labelMin, 0, Qt::AlignHCenter);
   labelLayout->addStretch(10);
   labelLayout->setSpacing(10);
   labelLayout->setMargin(0);

   number = new NunberWidget(this);
   number->setNum(85);

   loginLayout->addStretch(10);
   loginLayout->addWidget(new QLabel(tr("登录360帐号")));
   loginLayout->addWidget(loginBtn);
   loginLayout->setSpacing(8);
   loginLayout->setContentsMargins(0, 20, 10, 0);

   numberLayout->addWidget(number, 0);
   numberLayout->addLayout(labelLayout, 0);
   numberLayout->addStretch(10);
   numberLayout->setContentsMargins(10, 0, 0 , 0);
   numberLayout->setSpacing(15);

   QVector<QString> payinPathVec;
   payinPathVec.push_back(":/background/payinsure_safe_normal.png");
   payinPathVec.push_back(":/background/payinsure_safe_hover.png");
   payinPathVec.push_back(":/background/payinsure_safe_press.png");
   payinBtn = new Button(payinPathVec, this);

   QVector<QString> safePathVec;
   safePathVec.push_back(":/background/security_safe_normal.png");
   safePathVec.push_back(":/background/security_safe_hover.png");
   safePathVec.push_back(":/background/security_safe_press.png");
   safeBtn = new Button(safePathVec, this);

   QHBoxLayout *payinLayout = new QHBoxLayout;
   lineBtn = new Button(":/background/guardline.png", 1, this);
   payinLayout->addWidget(payinBtn);
   payinLayout->addWidget(lineBtn);
   payinLayout->setSpacing(5);
   payinLayout->setContentsMargins (25, 0, 0, 0);

   safeBtnLayout->addLayout(payinLayout, 0);
   safeBtnLayout->addWidget(safeBtn,0);
   safeBtnLayout->addStretch(10);
   safeBtnLayout->setMargin(0);
   safeBtnLayout->setSpacing(20);

   layout->addWidget(title, 0);
   layout->addLayout(loginLayout, 0);
   layout->addLayout(numberLayout, 0);
   layout->addWidget(examineBtn, 0,  Qt::AlignHCenter);
   layout->addLayout(safeBtnLayout, 0);
   layout->addStretch(10);

   layout->setSpacing(0);
   layout->setMargin(0);
   setLayout(layout);
}

void TopBaseWidget::InitConnect()
{
       connect(inAnimation, SIGNAL(	valueChanged(QVariant)), this, SLOT(update()));
       connect(outAnimation, SIGNAL(valueChanged(QVariant)), this, SLOT(update()));
}



