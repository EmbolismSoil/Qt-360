#include "basewidget.h"
#include <QVBoxLayout>
#include <QLabel>
#include <nunberwidget.h>
#include <QFont>
#include <QPalette>

TopBaseWidget::TopBaseWidget(QWidget *parent) :
    QWidget(parent)
{
    title = new titleBar(this);
    loginBtn = new LoginButton(":/background/head_bkg.png", 2, this);

    QVBoxLayout *layout = new QVBoxLayout;
    QHBoxLayout *loginLayout = new QHBoxLayout;
    QHBoxLayout *numberLayout = new QHBoxLayout;
    QLabel *label = new QLabel(tr("建议体检"),this);
    QLabel *labelMin = new QLabel(tr("建议每天进行体检"),this);
    QFont ft;
    QPalette palette;
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

    layout->addWidget(title, 0);
    layout->addLayout(loginLayout, 0);
    layout->addLayout(numberLayout, 0);
    layout->addWidget(examineBtn, 0,  Qt::AlignHCenter);
    layout->addStretch(10);

    layout->setSpacing(0);
    layout->setMargin(0);
    setLayout(layout);
}
