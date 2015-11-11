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
    QWidget(parent), m_isOut(false)
{
    IinitUi();
    IinitAnimatio();
    InitConnect();
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

    QPainter painter(this);
    painter.drawPixmap(event->rect(), *backGround);
}

void TopBaseWidget::IinitAnimatio()
{
    Effect = new QGraphicsOpacityEffect;
    Effect->setOpacity(1);
    this->setGraphicsEffect(Effect);

    outAnimation = new QPropertyAnimation(this, "AnimationPos");
    outAnimation->setStartValue(QPointF(0, 0));
    outAnimation->setEndValue(QPointF(0, -440));
    outAnimation->setDuration(200);

    inAnimation = new QPropertyAnimation(this, "AnimationPos");
    inAnimation->setStartValue(QPointF(0, -440));
    inAnimation->setEndValue(QPointF(0, 0));
    inAnimation->setDuration(200);


    outOpacityAnimation = new QPropertyAnimation(this, "Opacity");
    outOpacityAnimation->setStartValue(1);
    outOpacityAnimation->setEndValue(0);
    outOpacityAnimation->setDuration(200);

    inOpacityAnimation = new QPropertyAnimation(this, "Opacity");
    inOpacityAnimation->setStartValue(0);
    inOpacityAnimation->setEndValue(1);
    inOpacityAnimation->setDuration(200);

    inGroup = new QParallelAnimationGroup;
    outGroup = new QParallelAnimationGroup;

    inGroup->addAnimation(inAnimation);
    inGroup->addAnimation(inOpacityAnimation);
    outGroup->addAnimation(outAnimation);
    outGroup->addAnimation(outOpacityAnimation);
}

void TopBaseWidget::IinitUi()
{
    setAutoFillBackground(true);
    //setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    backGround = new QPixmap(":/background/wenli.png");

    QPalette palette;
    palette.setBrush(this->backgroundRole(), QColor("#2ABF1D"));
    this->setPalette(palette);

   title = new titleBar(this);
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
   numberLayout->setMargin(0);
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
   setContentsMargins (25, 0, 0, 0);

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



