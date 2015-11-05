#include "basewidget.h"
#include <QVBoxLayout>
#include <QLabel>
#include <nunberwidget.h>

TopBaseWidget::TopBaseWidget(QWidget *parent) :
    QWidget(parent)
{
    title = new titleBar(this);
    loginBtn = new LoginButton(":/background/head_bkg.png", 2, this);

    QVBoxLayout *layout = new QVBoxLayout;
    QHBoxLayout *loginLayout = new QHBoxLayout;
    QHBoxLayout *numberLayout = new QHBoxLayout;

    number = new NunberWidget(this);
    number->setNum(85);

    loginLayout->addStretch(10);
    loginLayout->addWidget(new QLabel(tr("登录360帐号")));
    loginLayout->addWidget(loginBtn);
    loginLayout->setSpacing(8);

    numberLayout->addWidget(number, 0);
    numberLayout->addStretch(10);

    layout->addWidget(title, 0);
    layout->addLayout(loginLayout, 0);
    layout->addLayout(numberLayout, 0);
    layout->addStretch(10);

    layout->setSpacing(0);
    setLayout(layout);
}
