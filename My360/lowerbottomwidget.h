#ifndef LOWERBOTTOMWIDGET_H
#define LOWERBOTTOMWIDGET_H

#include <QWidget>
#include <QVBoxLayout>

class LowerBottomWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LowerBottomWidget(QWidget *parent = 0);
    void InsertLayout(QBoxLayout *layout, int pos, int stretch)
    {
        Layout->insertLayout(pos, layout, stretch);
    }
signals:

public slots:

protected:
 //   virtual  QSize sizeHint () const;
private:
    QVBoxLayout *Layout;
};

#endif // LOWERBOTTOMWIDGET_H
