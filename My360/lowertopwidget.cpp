#include "lowertopwidget.h"

#if 0
LowerTopWidget::LowerTopWidget(QWidget *parent) :
    QWidget(parent)
{


       vlayout = new QVBoxLayout;
       hlayout = new QHBoxLayout;

       title = new titleBar(this);
}
#endif

LowerTopWidget::LowerTopWidget(QString BtnLeft,
         QString BtnRight, int xnum, int ynum, QString TopLabel,
                               QString bottomLabel, QWidget *parent):
    QWidget(parent)
{
    setAutoFillBackground(true);
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QColor("#2ABF1D"));
    this->setPalette(palette);


    QLabel *toplabel = new QLabel(TopLabel, this);
    QLabel *btmlabel = new QLabel(bottomLabel, this);

    palette.setColor(QPalette::WindowText, QColor(255,255,255));
    toplabel->setPalette(palette);
    btmlabel->setPalette(palette);

    QFont ft;

    ft.setPointSize(12);
    btmlabel->setFont(ft);
    ft.setPointSize(22);
    toplabel->setFont(ft);


    titleBtn = new Button(":/background/return.png",  4, this);
    title = new titleBar(this);
    title->InsertUserWidget(titleBtn, 0, 0, Qt::AlignLeft);

    leftBtn = new Button(BtnLeft);
    rightBtn = new Button(BtnRight, xnum, this, ynum);

    QVBoxLayout *labelLayout = new QVBoxLayout;
    labelLayout->addWidget(toplabel, 0, Qt::AlignLeft);
    labelLayout->addWidget(btmlabel, 0, Qt::AlignLeft);
    labelLayout->setMargin(0);
    labelLayout->setSpacing(10);

    QHBoxLayout *logoLayout = new QHBoxLayout;
    logoLayout->addWidget(leftBtn, 0);
    logoLayout->addLayout(labelLayout, 0);
    logoLayout->setMargin(0);
    logoLayout->setSpacing(10);

    hlayout = new QHBoxLayout;
    hlayout->addLayout(logoLayout, 0);
    hlayout->addStretch(10);
    hlayout->addWidget(rightBtn, 0);
    hlayout->setContentsMargins(20, 10, 20, 0);
    hlayout->setSpacing(0);

    vlayout = new QVBoxLayout;
    vlayout->addWidget(title, 0);
    vlayout->addLayout(hlayout, 0);
    vlayout->addStretch(10);
    vlayout->setMargin(0);
    vlayout->setSpacing(0);

    setLayout(vlayout);
}


