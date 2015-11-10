#include "buttonwithname.h"
#include <QVBoxLayout>


ButtonWithName::ButtonWithName(QString FileName, int xnum, QWidget *parent, int ynum, QString name):
   QWidget(parent)
{
        Btn = new Button(FileName, xnum, this, ynum);

        layout = new QVBoxLayout;
        layout->addWidget(Btn, 0,  Qt::AlignHCenter);

        if (name != 0){
            nameLabel = new QLabel(name, this);
            font = new QFont;
            font->setPointSize(11);
            nameLabel->setFont(*font);
            layout->addWidget(nameLabel, 0, Qt::AlignHCenter);
        }

        layout->setMargin(0);
        layout->setSpacing(0);
        setLayout(layout);
}
