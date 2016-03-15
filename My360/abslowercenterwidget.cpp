#include "abslowercenterwidget.h"
#include <QVBoxLayout>
#include <lowerbottomwidget.h>
#include <lowertopwidget.h>

AbsLowerCenterWidget::AbsLowerCenterWidget(QWidget *parent) :
    QWidget(parent)
{
}

AbsLowerCenterWidget::~AbsLowerCenterWidget()
{
    delete layout;
    delete BottomWidget;
    delete TopWidget;
}


#if 0
void AbsLowerCenterWidget::init(AbsLowerCenterWidget *LowerCenter)
{
    LowerCenter->InitUi();

    LowerCenter->layout->addWidget(TopWidget);
    LowerCenter->layout->addWidget(BottomWidget);
    LowerCenter->layout->setMargin(0);
    LowerCenter->layout->setSpacing(0);
    LowerCenter->setLayout(layout);
    LowerCenter->lower();
}
#endif
