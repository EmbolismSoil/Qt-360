#ifndef LOWERBOTTOMWIDGET_H
#define LOWERBOTTOMWIDGET_H

#include <QWidget>
#include <QVBoxLayout>

class LowerBottomWidget : public QWidget
{
    Q_OBJECT
public:
    typedef enum{speed,  safe, clean}widgetT;
    explicit LowerBottomWidget(QWidget *parent = 0);
    void InsertLayout(QBoxLayout *layout, int pos = 0, int stretch = 0)
    {
        Layout->insertLayout(pos, layout, stretch);
    }

    void setSpacing(int spac){Layout->setSpacing(spac);}
    void addStretch(int s){Layout->addStretch(s);}

    static LowerBottomWidget* factory(widgetT Type, QWidget * = 0);
signals:

public slots:

protected:
 //   virtual  QSize sizeHint () const;
private:
    QVBoxLayout *Layout;
};

#endif // LOWERBOTTOMWIDGET_H
